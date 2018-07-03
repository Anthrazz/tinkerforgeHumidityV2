
Basic go package to use the Humidity V2 Bricklet from Tinkerforge. The package uses the C-Bindings from Tinkerforge and compile they with cgo.

# How to use

Basic example with a new *.go file:

```go
package main

import "fmt"
import tinkerforgeHumidityV2 "github.com/Anthrazz/tinkerforgeHumidityV2"

func main() {

        tinkerforgeHumidityV2.BrickletUID = "Dhz"

        temp, err := tinkerforgeHumidityV2.GetTemperature()
        if err != nil {
                fmt.Println("Error:", err)
        } else {
                fmt.Println("Temperature in °C:", temp)
        }

        humi, err := tinkerforgeHumidityV2.GetHumidity()
        if err != nil {
                fmt.Println("Error:", err)
        } else {
                fmt.Println("Humidity in %:", humi)
        }
}
```

