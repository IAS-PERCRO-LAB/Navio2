/*
Provided to you by Emlid Ltd (c) 2014.
twitter.com/emlidtech || www.emlid.com || info@emlid.com

Example: Get pressure from MS5611 barometer onboard of Navio shield for Raspberry Pi

To run this example navigate to the directory containing it and run following commands:
make
./Barometer
*/

#include <Common/MS5611.h>
#include <Common/Util.h>
#include <unistd.h>
#include <iostream>

int main() {
    MS5611 barometer;

    if (check_apm()) {
        return 1;
    }

    barometer.initialize();

    while (true) {
        barometer.refreshPressure();
        usleep(10000); // Waiting for pressure data ready
        barometer.readPressure();

        barometer.refreshTemperature();
        usleep(10000); // Waiting for temperature data ready
        barometer.readTemperature();

        barometer.calculatePressureAndTemperature();

        std::cout << "Temperature(C): " << barometer.getTemperature() <<
                  " Pressure(millibar): " << barometer.getPressure() << std::endl;

        sleep(1);
    }
}
