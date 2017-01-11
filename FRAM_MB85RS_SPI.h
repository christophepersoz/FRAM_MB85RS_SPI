/**************************************************************************/
/*! 
    @file     FRAM_MB85RS_SPI.h
    @author   Christophe Persoz for SPI version
              SOSAndroid.fr (E. Ha.) for I2C version
	
    @section  HISTORY

    v0.7 - See ReadMe for more informations
    
    Driver for the MB85RC SPI FRAM from Fujitsu.
	
    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2013, SOSAndroid.fr (E. Ha.)
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/**************************************************************************/
#ifndef __FRAM_MB85RS_SPI_H__
#define __FRAM_MB85RS_SPI_H__

#include <SPI.h>


// DEFINES

#define SPICONFIG   SPISettings(28000000, MSBFIRST, SPI_MODE0) // SPI frequency (24 MHz max), MODE 0
#ifndef DEBUG_TRACE
    #define DEBUG_TRACE    // Enabling Debug Trace on Serial
#endif
#ifndef CHIP_TRACE
    #define CHIP_TRACE     // Serial trace for characteristics of the chip
#endif


// IDs - can be extends to any other compatible chip
#define FUJITSU_ID 0x04

// Density codes gives the memory's adressing scheme
#define DENSITY_MB85RS64V  0x03	// 64K
#define DENSITY_MB85RS128B 0x04	// 128K
#define DENSITY_MB85RS256B 0x05	// 256K
#define DENSITY_MB85RS512T 0x06	// 512K
#define DENSITY_MB85RS1MT  0x07	// 1M
#define DENSITY_MB85RS2MT  0x08	// 2M

// OP-CODES
#define FRAM_WRSR  0x01 // 0000 0001 - Write Status Register
#define FRAM_WRITE 0x02 // 0000 0010 - Write Memory
#define FRAM_READ  0x03 // 0000 0011 - Read Memory
#define FRAM_WRDI  0x04 // 0000 0100 - Reset Write Enable Latch
#define FRAM_RDSR  0x05 // 0000 0101 - Read Status Register
#define FRAM_WREN  0x06 // 0000 0110 - Set Write Enable Latch
#define FRAM_FSTRD 0x0B // 0000 1011 - Fast Read
#define FRAM_RDID  0x9F // 1001 1111 - Read Device ID
#define FRAM_SLEEP 0xB9 // 1011 1001 - Sleep mode


// Managing Write protect pin
// false means protection off, write enabled
#define DEFAULT_WP_STATUS false


class FRAM_MB85RS_SPI
{
 public:
    FRAM_MB85RS_SPI(uint8_t cs);
    FRAM_MB85RS_SPI(uint8_t cs, uint8_t wp);
    

    void	init();
    boolean	checkDevice();
    
    boolean	read(uint32_t framAddr, uint8_t *value);
    boolean	read(uint32_t framAddr, uint16_t *value);
    boolean	read(uint32_t framAddr, uint32_t *value);
    boolean	write(uint32_t framAddr, uint8_t value);
    boolean	write(uint32_t framAddr, uint16_t value);
    boolean	write(uint32_t framAddr, uint32_t value);
    
    boolean readArray(uint32_t startAddr, uint8_t values[], size_t nbItems );
    boolean readArray(uint32_t startAddr, uint16_t values[], size_t nbItems );
    boolean writeArray(uint32_t startAddr, uint8_t values[], size_t nbItems );
    boolean writeArray(uint32_t startAddr, uint16_t values[], size_t nbItems );
    
    boolean	isAvailable();
    boolean	getWPStatus();
    boolean	enableWP();
    boolean	disableWP();
    boolean	eraseChip();
    uint32_t getMaxMemAdr();
    uint32_t getLastMemAdr();
    
    
 private:
    
    boolean		_framInitialised;
    uint8_t     _cs;            // CS pin
    boolean     _wp;            // WP management
    uint8_t     _wpPin;         // WP pin connected and Write Protection enabled
    boolean     _wpStatus;      // WP Status
    uint8_t     _manufacturer;  // Manufacturer ID
    uint16_t	_productID;     // Product ID
    uint8_t     _densitycode;   // Code which represent the size of the chip
    uint16_t	_density;       // Human readable size of F-RAM chip
    uint32_t	_maxaddress;    // Maximum address suported by F-RAM chip
    uint32_t    _lastaddress;   // Last address used in memory
    
    void        _csCONFIG();
    void        _csASSERT();
    void        _csRELEASE();
    boolean     _getDeviceID();
    boolean     _deviceID2Serial();
    void        _setMemAddr(uint32_t *framAddr);
};



#endif
