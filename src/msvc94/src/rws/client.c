#include <rws/client.h>
#include <stdio.h>
#include <string.h>
#include <winsock.h>

HTTPCLIENTINFO rws_get_client_info(SOCKET client) {

	HTTPCLIENTINFO client_info;
	struct sockaddr_in client_addr;

	unsigned long ip = 0;
	char client_ip[128];
	int client_addrlen;

	memset((char*)&client_addr, 0, sizeof(client_addr));

	client_addrlen = sizeof(client_addr);
	
	getpeername(client, (LPSOCKADDR*)&client_addr, &client_addrlen);

	ip = inet_addr(inet_ntoa(client_addr.sin_addr));

	client_info.port = ntohs(client_addr.sin_port);

	sprintf(client_info.addr, 
			"%lu.%lu.%lu.%lu",
			ip & 0xFF,
			(ip >>  8) & 0xFF,
			(ip >> 16) & 0xFF,
			(ip >> 24) & 0xFF
	);

	return client_info;
}
