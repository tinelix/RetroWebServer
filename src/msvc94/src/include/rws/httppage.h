#ifndef _RWS_HTTPPAGE_H
#define _RWS_HTTPPAGE_H

#include <rws/httpreq.h>
#include <rws/client.h>

char* rws_load_http_page(HTTPCLIENTINFO client_info, HTTPREQUEST request);
const char* rws_get_http_status_desc(int status);

#endif
