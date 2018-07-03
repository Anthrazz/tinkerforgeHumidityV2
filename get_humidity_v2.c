#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_humidity_v2.h"
#include "get_humidity_v2.h"

IPConnection init_ip_connection() {
	IPConnection ipcon;
	ipcon_create(&ipcon); 
	return ipcon;
}

int init_brick_connection(IPConnection *ipcon, HumidityV2 *h, char* host, uint16_t port, char* uid) {
	humidity_v2_create(h, uid, ipcon);
	if(ipcon_connect(ipcon, host, port) < 0) {
		return -1;
	}
    return 0;
}

void destroy_brick_connection(IPConnection *ipcon, HumidityV2 *h) {
	humidity_v2_destroy(h);
	ipcon_destroy(ipcon); // Calls ipcon_disconnect internally
}


int get_humidity_v2(HumidityV2 *humidity_v2) {
	int16_t humidity;
	if(humidity_v2_get_humidity(humidity_v2, &humidity) < 0) {
		return -1;
	}
	return humidity;
}

int get_temperature_v2(HumidityV2 *humidity_v2) {
	int16_t temperature;
	if(humidity_v2_get_temperature(humidity_v2, &temperature) < 0) {
		return -30000;
	}
    return temperature;
}
