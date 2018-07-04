
Basic go package to use the Humidity V2 Bricklet from Tinkerforge. The package uses the C-Bindings from Tinkerforge and compile they with cgo.

# How to use

Create a new .go file and import this package:

```go
package main

import "fmt"
import tinkerforgeHumidityV2 "github.com/Anthrazz/tinkerforgeHumidityV2"

func main() {
        myHumidityBricklet := tinkerforgeHumidityV2.New()
        myHumidityBricklet.BrickletUID = "Dhz"

        temp, err := myHumidityBricklet.GetTemperature()
        if err != nil {
                fmt.Println("Error:", err)
        } else {
                fmt.Println("Temperature in °C:", temp)
        }

        humi, err := myHumidityBricklet.GetHumidity()
        if err != nil {
                fmt.Println("Error:", err)
        } else {
                fmt.Println("Humidity in %:", humi)
        }

}
```

