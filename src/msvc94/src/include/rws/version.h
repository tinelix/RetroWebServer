#ifndef _RWS_VERSION_H
#define _RWS_VERSION_H

typedef struct {
	unsigned int major;
	unsigned int minor;
	unsigned int build_num;
	unsigned long int build_date;
} RWS_VERSION;

const char* rws_get_branding_short_name();

RWS_VERSION rws_get_version();

#endif
