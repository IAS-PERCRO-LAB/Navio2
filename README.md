Navio 2 for Debian 12
=====

Collection of drivers and examples for Navio 2 - autopilot shield for Raspberry Pi.

## Additions of this fork
* fix many errors and warnings due to new CXX 11 standards
* update GPIO submodule to 1.79.1
* add `CMakeLists` to Navio2 library, that install the library system-level.

### Build and install Navio2 library
This enables to use `find_package(Navio2)` in other CMake projects.

```bash
cd Navio2/C++/Navio
mkdir build && cd build
cmake ..
make
sudo make install
```

## Repository structure

### C++

#### Examples

Basic examples showing how to work with Navio's onboard devices using C++.

* AccelGyroMag
* ADC
* AHRS
* Barometer
* GPS
* LED 2
* RCInput
* Servo

#### Navio 2

C++ drivers for Navio 2's onboard devices and peripheral interfaces.

* MPU9250 SPI
* LSM9DS1 SPI
* U-blox SPI
* MS5611 I2C
* I2C driver
* SPI driver

### Python

Basic examples showing how to work with Navio's onboard devices using Python.

* AccelGyroMag
* ADC
* Barometer
* GPS
* LED
* RCInput
* Servo


### Utilities

Applications and utilities for Navio.

* 3D IMU visualizer
* U-blox SPI to PTY bridge utility
* U-blox SPI to TCP bridge utility
* ROS packages installation script

### Cross-compilation

#### Requirements

* Install the toolchain `gcc-arm-linux-gnueabihf g++-arm-linux-gnueabihf` (`sudo apt-get install gcc-arm-linux-gnueabihf g++-arm-linux-gnueabihf` for Debian based systems)

#### Usage

* `export CXX=arm-linux-gnueabihf-g++`
* Compile the examples via `make`
