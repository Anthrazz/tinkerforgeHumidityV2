package tinkerforgeHumidityV2

/*
#include <get_humidity_v2.h>
*/
import "C"

import "unsafe"
import "errors"

var BrickdHost string = "localhost"
var BrickdPort int = 4223
var BrickletUID string = "XYZ"

func GetTemperature() (float64, error) {
	ipcon := C.init_ip_connection()

	host := C.CString(BrickdHost)
	port := C.uint16_t(uint16(BrickdPort))
	uid := C.CString(BrickletUID)

	defer C.free(unsafe.Pointer(host))
	defer C.free(unsafe.Pointer(uid))

	var h C.HumidityV2
	C.init_brick_connection(&ipcon, &h, host, port, uid)

	// C.get* put into float() to convert returned integer of type C.int to go float
	temperature := float64(C.get_temperature_v2(&h)) / 100

	C.destroy_brick_connection(&ipcon, &h)

	if temperature == -300 {
		return 0, errors.New("Could not get temperature, probably timeout")
	}

	return temperature, nil
}

func GetHumidity() (float64, error) {
	ipcon := C.init_ip_connection()

	host := C.CString(BrickdHost)
	port := C.uint16_t(uint16(BrickdPort))
	uid := C.CString(BrickletUID)

	defer C.free(unsafe.Pointer(host))
	defer C.free(unsafe.Pointer(uid))

	var h C.HumidityV2
	C.init_brick_connection(&ipcon, &h, host, port, uid)

	// C.get* put into float() to convert returned integer of type C.int to go float
	humidity := float64(C.get_humidity_v2(&h))

	C.destroy_brick_connection(&ipcon, &h)

	if humidity == -1 {
		return 0, errors.New("Could not get humidity, probably timeout")
	}

	return humidity / 100, nil
}
