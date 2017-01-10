/**************************************************************************/
/*!
    @file     FRAM_simple_write_read.ino
    @author   SOSAndroid (E. Ha.) for I2C version
              Christophe Persoz for SPI version
    @license  BSD (see license.txt)

    Example sketch to write & read "automatic setting".

    @section  HISTORY

    v1.0.0 - First release
*/
/**************************************************************************/

#include <SPI.h>
#include <FRAM_MB85RS_SPI.h>


//dummy data used for the test
uint8_t writevalue = 0xBE;
uint8_t readvalue = 0xEF; // at the end, readvalue should be equal to writevalue


//random addresses to write from
uint32_t writeaddress = 0x0; // Beginning of the memory map


//Creating object for FRAM chip
uint8_t FRAM_CS = 21  ;
static FRAM_MB85RS_SPI FRAM(FRAM_CS);



void setup()
{

	Serial.begin(115200);
    while (!Serial) {}  //wait until Serial ready
	
    Serial.println("Starting...");

	FRAM.init();

//-------- First run, beginning of memory map ---------
	Serial.println("1st test");
	Serial.print("Writing at location 0x");
	Serial.println(writeaddress, HEX);
	
    Serial.print("Writing...");
	if (FRAM.write(writeaddress, writevalue))
        Serial.println("ok");
    else
        Serial.println("eror");
    
    Serial.print("Reading...");
    if (FRAM.read(writeaddress, &readvalue))
        Serial.println("ok");
    else
        Serial.println("eror");
    
	Serial.print("Written value 0x");
	Serial.println(writevalue, HEX);
	
	Serial.print("Read value 0x");
	Serial.println(readvalue, HEX);
	
	if (writevalue == readvalue)
		Serial.println("Write Byte test : OK");
	else
		Serial.println("Write Byte test : NOT OK");
	
	
//-------- Device IDs ---------
	if (FRAM.checkDevice())
        Serial.println("Finished....");
    else
        Serial.println("ERROR....");
}

void loop()
{
	// nothing to do
}
