Arduino library for SPI FRAM - Fujitsu MB85RS
==============

SPI Ferroelectric Random Access Memory (FRAM). Read/write endurance for each memory slot : 10^13 cycles and more.
Supports 64K, 128K, 256K, 512K, 1M and 2M chips.
These memories chips can work up to 25MHz in SPI Mode 0 or Mode 3.

## Features ##
- Device settings detection (if Device ID feature is available)
- Write one 8-bits, 16-bits or 32-bits value
- Read one 8-bits, 16-bits or 32-bits value
- Get device information
	- 1: Manufacturer ID
	- 2: Product ID
	- 3: Density code
	- 4: Density human readable
	- 5: Define the last memory address of the chip
- Get the last memory address
- Manage write protect pin
- Erase memory (set all chip to 0x00) and stop if error on write
- Prevent cycling through memory map to avoid unwanted overwrites
- Debug mode manageable from header file


## Revision History ##
v0.7 - Working version
Please note when you activate DEBUG_TRACE & CHIP_TRACE in .h the performances are slower than it should be. Serial trace takes times! Avoid the use of DEBUG_TRACE & CHIP_TRACE for a normal usage.

[Download it here !](https://github.com/christophepersoz/FRAM_MB85RS_SPI/archive/master.zip)

## Devices ##

**Fujitsu FRAM** - manufacturer code 0x04 - [Fujitsu page](http://www.fujitsu.com/us/products/devices/semiconductor/memory/fram/lineup/index.html)

|  Model | Density (kB) | Device ID feature | Density code | Memory addressing | Tested |
|  ------ | :------: | :------: | :------: | :------: | :------: |
|  **MB85RS64V** | 64 | Yes | 0x03 | 16 bits | No |
|  **MB85RS128B** | 128 | Yes | 0x04 | 16 bits | No |
|  **MB85RS256B** | 256 | Yes | 0x05 | 16 bits | No |
|  **MB85RS512T** | 512 | Yes | 0x06 | 16 bits | No |
|  **MB85RS1MT** | 1024 | Yes | 0x07 | 24 bits | Yes |
|  **MB85RS2MT** | 2048 | Yes | 0x08 | 24 bits | No |


## To do ##
- [x] Functions revision and cleaning
- [x] Minimize code's size and reduce Serial outputs and ERRORS to reduce memory footprint
- [x] Change Wire I2C communication into transactionnal SPI
- [x] Change I2C Addressing into SPI 32bit max addressing
- [x] Add OP_CODE for SPI FRAM chips
- [x] Creation of wroking test example / benchmark speed
- [ ] Add High Speed Reading Mode and Sleep Mode
- [x] Tests on MB85RS1MT SPI
- [x] Update/change examples
- [x] Read / Write an array of bytes
- [x] Read / Write one array of shorts
- [x] Getter for Max memory address and Last memory address used on read/write op
- [ ] v1.0 - First complete release
- [ ] v1.2 - Thinking about expand the lib to Cypress F-RAM chip
- [ ] Forked the repo and create the lib for M-RAM chips

Close to the complete release...


## Testing ##

I only own 1Mbit chips, so if anybody can test all the other chips...
This library has been developped to work on ARM Teensy 3.2, 3.5 and above.
It should be works on Arduino too, but I won't test it.


## Credits ##
- Sosandroid who wrote the I2C version of this library that I forked for SPI (https://github.com/sosandroid/FRAM_MB85RC_I2C)
- [Kevin Townsend](https://github.com/microbuilder) wrote the very first [Adafruit Lib](https://github.com/adafruit/Adafruit_FRAM_I2C) of which this one is forked.
- All testers who helped to improve this library
