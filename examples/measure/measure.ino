// Demonstrate Vcc::measure

#include <Vcc.h>
#include <EEPROM.h>

#define BAUDRATE 9600

int intref;

void setup(void)
{
  Serial.begin(BAUDRATE);
  while (!Serial);
  EEPROM.get(EE_INTREF, intref);
}

void loop(void)
{
  int voltage;
  voltage = Vcc::measure(1000,1100);
  Serial.print(F("Vcc (uncalibrated): "));
  Serial.print(voltage);
  Serial.println(F(" mV"));
  if (intref != 0xFFFF) {
    voltage = Vcc::measure(1000);
    Serial.print(F("Vcc (calibrated):   "));
    Serial.print(voltage);
    Serial.println(F(" mV"));
    Serial.print(F("Internal Reference: "));
    Serial.print(intref);
    Serial.println(F(" mV"));
  }    
  delay(2000); 
}
