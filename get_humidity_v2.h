
#ifndef GET_HUMIDITY_V2_H
#define GET_HUMIDITY_V2_H

#include "bricklet_humidity_v2.h"

#ifdef __cplusplus
extern "C" {
#endif

IPConnection init_ip_connection();

int init_brick_connection(IPConnection *ipcon, HumidityV2 *h, char* host, uint16_t port, char* uid);

void destroy_brick_connection(IPConnection *ipcon, HumidityV2 *h);

int get_humidity_v2(HumidityV2 *humidity_v2);

int get_temperature_v2(HumidityV2 *humidity_v2);

#endif
