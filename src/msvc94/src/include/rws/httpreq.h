#ifndef _RWS_HTTPREQ_H
#define _RWS_HTTPREQ_H

typedef struct {
	char host[255];
	char user_agent[255];
	char accept[255];
	char accept_encoding[255];
	char accept_language[255];
} HTTPREQUESTFIELDS;

typedef struct {
	char method[10];
	char version[25];
	char uri[255];
	char path[255];
	char from[255];
	HTTPREQUESTFIELDS fields;
} HTTPREQUEST;

HTTPREQUEST rws_parse_http_request(char* buffer);

#endif
