#include <rws/httppage.h>
#include <rws/version.h>
#include <rws/clrprntf.h>

#include <stdio.h>
#include <errno.h>

char* rws_make_http_response(int status, char* page);
int rws_read_http_page(HTTPREQUEST request, char* buffer, size_t szBuffer);
const char* rws_get_http_status_desc(int status);

char* rws_load_http_page(HTTPCLIENTINFO client_info, HTTPREQUEST request) {
	char* response;
	char page[3258];
	int status = 200;
	
	int read_status = rws_read_http_page(request, page, 3528);
	
	switch(read_status) {
		default:
			status = 200;
			break;
		case 1:
			status = 403;
			break;
		case 2:
			status = 404;
			break;
		case 3:
			status = 400;
			break;
		case 4:
			status = 452;
			break;
	}
	
	if(read_status > 0) {
		strcpy(page, rws_gen_http_error_page(status));
	} else {
		rws_clrprintf(
			2, "Response from server: HTTP %d - %s %s\r\n", 
			status, request.method, request.uri 
		);
	}

	response = rws_make_http_response(status, page);

	return response;
}

char* rws_make_http_response(int status, char* page) {
	char response[4096];
	
	sprintf(response,
			"HTTP/%s %d %s\r\n"
			"Content-Type: text/html\r\n"
			"Connection: close\r\n"
			"\r\n"
			"%s\n",
			"1.1", status, rws_get_http_status_desc(status), page
	);

	return response;		
}

int rws_read_http_page(HTTPREQUEST request, char* buffer, size_t szBuffer) {
	
	size_t szFile = 0;
	size_t szFileRead = 0;
	FILE* file;

	if(strcmp(request.uri, "/") == 0) {
		strcpy(request.uri, "index.htm");
	} else {
		strcpy(request.uri, request.uri + 1);
	}

	file = fopen(request.uri, "rb");

	if(!file) {

		rws_clrprintf(
			-1, "File read error (%d: %s)\r\n", 
			errno, request.uri 
		);

		switch(errno) {
			case EACCES:
				return 1;
			case ENOENT:
				return 2;
			case EINVAL:
				return 3;
		}
	}

	fseek(file, 0L, SEEK_END);
	szFile = ftell(file);
	rewind(file);

	if(szFile >= szBuffer) {
		return 4;
	}

	szFileRead = fread(buffer, sizeof(char), szFile, file);
	
	if(szFileRead != szFile) {
		return 5;
	}

	buffer[szFile] = '\0';

	fclose(file);

	return 0;

}

const char* rws_get_http_status_desc(int status) {
	
	switch(status) {
		case 200:
			return "OK";
		case 400:
			return "Bad Request";
		case 401:
			return "Unauthorized";
		case 402:
			return "Payment Required";
		case 403:
			return "Forbidden";
		case 404:
			return "Not Found";
		case 405:
			return "Method Not Allowed";
		case 406:
			return "Not Acceptable";
		case 422:
			return "Unprocessable Content";
		case 450:
			return "Blocked by Deep Packet Inspection";
		case 452:
			return "Unavailable For Security Reasons";
		case 500:
			return "Internal Server Error";
		case 501:
			return "Not Implemented";
		case 503:
			return "Service Unavailable";
	}	
}
