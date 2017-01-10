/**************************************************************************/
/*!
    @file     FRAM_connect.ino
    @author   SOSAndroid (E. Ha.) for I2C version
              Christophe Persoz for SPI version
    @license  BSD (see license.txt)

    This sketch connects the FRAM chips and tries to identify it.
    This succeed if the IDs are known, fails otherwise

    @section  HISTORY

    v1.0.0 - First release

*/
/**************************************************************************/

#include <SPI.h>
#include <FRAM_MB85RS_SPI.h>


//Creating object for FRAM chip
uint8_t FRAM_CS = 21  ;
static FRAM_MB85RS_SPI FRAM(FRAM_CS);



void setup()
{

	Serial.begin(115200);
    while (!Serial) {} //wait until Serial ready
    
    Serial.println("Starting...");

    FRAM.init();
	// If SER_OUT is enabled at the library level
    // the device's IDs are displayed on Serial
}

void loop()
{
	// nothing to do
}
