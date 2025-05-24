#include <rws/httpreq.h>
#include <rws/clrprntf.h>
#include <winsock.h>

void rws_parse_http_header(
	char* buffer, char *header_name, char* value
);

HTTPREQUEST rws_parse_http_request(char* buffer) {

	HTTPREQUEST request;
	char* lineStart;
	char buffer2[1024];

	strcpy(request.method, "");
	strcpy(request.path, "");
	strcpy(request.uri, "");
	strcpy(request.version, "");
	strcpy(request.fields.user_agent, "");
	strcpy(request.fields.host, "");
	strcpy(request.fields.accept, "");
	strcpy(request.fields.accept_encoding, "");
	strcpy(request.fields.accept_language, "");

	strcpy(buffer2, buffer);
	
	lineStart = strtok(buffer2, "\r\n");

	sscanf(
			lineStart, "%s %s %s", 
			request.method,
			request.uri,
			request.version
	);

	rws_parse_http_header(buffer, "Host", request.fields.host);
	rws_parse_http_header(buffer, "User-Agent", request.fields.user_agent);
	rws_parse_http_header(buffer, "Accept", request.fields.accept);
	rws_parse_http_header(buffer, "Accept-Encoding", request.fields.accept_encoding);
	rws_parse_http_header(buffer, "Accept-Language", request.fields.accept_language);
	
	return request;		
}

void rws_parse_http_header(
	char* buffer, char *header_name, char* value
) {
	char line_buffer[256];
	char* pos;
	char* lineStart;

	sprintf(line_buffer, "%s: ", header_name);
	pos = strstr(buffer, line_buffer);

	if(pos != NULL) {
		pos += strlen(line_buffer);
		sscanf(pos, "%[^\\r]", value);
	}

	lineStart = strtok(value, "\r\n");
}
