#ifndef _RWS_CLIENT_H
#define _RWS_CLIENT_H

#include <winsock.h>

typedef struct {
	char addr[128];
	unsigned int port;
} HTTPCLIENTINFO;

HTTPCLIENTINFO rws_get_client_info(SOCKET client);

#endif
