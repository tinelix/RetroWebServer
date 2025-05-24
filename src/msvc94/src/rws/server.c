#include <stdio.h>
#include <windows.h>
#include <winsock.h>

#include <rws/client.h>
#include <rws/server.h>
#include <rws/version.h>
#include <rws/clrprntf.h>
#include <rws/httpreq.h>

SOCKET httpd;
BOOL isRunning = FALSE;

void rws_on_error(int errcode);
void rws_stop();
BOOL WINAPI rws_ctrl_handler(DWORD dwCtrlType);

HTTPCLIENTINFO prev_client_info;
HTTPREQUEST	prev_request;

int rws_hello() {
	RWS_VERSION version;

	version = rws_get_version();
	
	printf("Tinelix RetroWebServer %d.%d.%d (MSVC94/x86)\r\n", 
		   version.major,
		   version.minor,
		   version.build_num
	);
	printf("Copyright (C) 2025 Dmitry Tretyakov\r\n\r\n");
	return 0;
}

int rws_prepare() {
	WSADATA wsa_data;

	rws_hello();

	// SetConsoleCtrlHandler() function

	SetConsoleCtrlHandler((PHANDLER_ROUTINE)rws_ctrl_handler, TRUE);
		
	WSAStartup(MAKEWORD(1, 1), &wsa_data);

	return 0; 
}

void rws_start(RWSS_PARAMS* params) {
	SOCKADDR_IN server_addr;
	int result = 0;

	rws_prepare();

	httpd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(httpd == INVALID_SOCKET) {
		rws_on_error((int)httpd);		
	}

	memset((char*)&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(params->port);

	if((result = bind(httpd, (LPSOCKADDR)&server_addr, sizeof(server_addr))) != 0) {
		rws_on_error(result);	
	}

	if(listen(httpd, SOMAXCONN) != 0) {
		rws_on_error(result);
	} else {
		rws_clrprintf(2, "Listening client connections at port %d...\r\n", params->port);
		rws_clrprintf(3, "Press CTRL+C to stop server.\r\n");
	}

	isRunning = TRUE;

	while(isRunning) {

		HTTPCLIENTINFO client_info;
		HTTPREQUEST request;
		int bytesRead = 0;
		SOCKET client = accept(httpd, NULL, NULL);
		char buffer[1024];
		char* pBuffer;
		char* rBuffer;

		bytesRead = recv(client, buffer, sizeof(buffer)-1, 0);

		if(client == INVALID_SOCKET)
			continue;

		if(bytesRead <= 0)
			continue;

		pBuffer = buffer;

		client_info = rws_get_client_info(client);
		request = rws_parse_http_request(buffer);

		rws_clrprintf(
			1, "New connection from %s:%d - %s %s\r\n", 
			client_info.addr, client_info.port,
			request.method, request.uri
		);

		if(
			(strcmp(prev_client_info.addr, client_info.addr) != 0) &&
			(strcmp(
				prev_request.fields.user_agent, 
				request.fields.user_agent
			) != 0 ||
			strcmp(
				prev_request.fields.host, 
				request.fields.host
			) != 0 ||
			strcmp(
				prev_request.fields.accept, 
				request.fields.accept
			) != 0)
		) {
			rws_clrprintf(5, "User-Agent: [%s]\r\n", request.fields.user_agent);
			rws_clrprintf(5, "Host: [%s]\r\n", request.fields.host);
			rws_clrprintf(4, "Accept: [%s]\r\n", request.fields.accept);
		}

		prev_client_info = client_info;

		rBuffer = rws_load_http_page(client_info, request);

		send(client, rBuffer, strlen(rBuffer), 0);

		closesocket(client);

		Sleep(100);	
			
	}
	
	return;
}

void rws_on_error(int errcode) {

	if(errcode == 0) {
		rws_clrprintf(-1, "[ERROR] Failed to initialize socket.\r\n");
	} else {
		rws_clrprintf(-1, "[ERROR] WinSock error #%d.\r\n", WSAGetLastError());
	}

	rws_stop();
}

void rws_stop() {
	rws_clrprintf(2, "Exiting...\r\n");
	closesocket(httpd);
	WSACleanup();
}

BOOL WINAPI rws_ctrl_handler(DWORD dwCtrlType) {
	switch(dwCtrlType) {
		case CTRL_C_EVENT:
			isRunning = FALSE;
			return TRUE;
		default:
			return FALSE;
	}
}
