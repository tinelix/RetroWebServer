#include <stdio.h>
#include <rws/server.h>

int main() {
	RWSS_PARAMS rws_params;

	rws_params.addr = "127.0.0.1";
	rws_params.port = 80;

 	rws_start(&rws_params);
	rws_stop();
	return 0;
}


