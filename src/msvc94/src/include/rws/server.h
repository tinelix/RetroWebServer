#ifndef _RWS_SERVER_H
#define _RWS_SERVER_H

#include <stdio.h>

typedef struct {
	char* addr;
	unsigned int port;
} RWSS_PARAMS;

typedef struct {
	char* addr;
	unsigned int port;
	char* ua; // ua -> useragent
} RWSC_INFO;

typedef struct {
  char* version;
  unsigned int status;
  char* uri;
  char* content;
} HTTPRESPONSE;

void rws_start(RWSS_PARAMS* params);

#endif

