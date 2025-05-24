#include <rws/version.h>

const char* rws_get_branding_short_name() {
	return "TinelixRWS";
}

RWS_VERSION rws_get_version() {
	RWS_VERSION version;

	(&version)->minor = 0;
	(&version)->major = 0;
	(&version)->build_num = 0;
	(&version)->build_date = 0;

	return version;
}
