Vcc
===

This is a very small and basic library that contains only two (static) methods, which return the voltage of an AVR MCU supply in millivolts. The method switches the ADC on (and off again), if necessary, and it works for most of the chips of the AVR family that are supported by the Arduino IDE.

The method comes in two flavors. It can be called with two parameters, a *repetition counter* and a *calibration value*. The repetition counter specifies how often the measurement should be done in order to enhance accuracy. The calibration value specifies the accurate value of the internal voltage reference in millivolts. Nominally it is 1100 millivolts. However, this can change from chip to chip. If you want a truely accurate measurement, then you should determine this value for each chip, using, for example, the [*intrefTune* sketch](https://github.com/felias-fogg/intrefTune). This sketch works even if you have only access to the three ICSP pins. A simplified version of this sketch using the ordinary Serial interface can be found in the example folder.

The other flavor of the method uses a calibration value that is stored in EEPROM. It is called with only one (optional) argument, the repetition counter. So the usage of the method could look like as follows:

    #include<Vcc.h>
	...
	int milliVolts;
	...
	milliVolts = Vcc::measure(); // uses calibration value from EEPROM, 10 repetitions
	...
	milliVolts = Vcc::measure(100, 1100); // 100 repetitions, 1100 as calibration value

The library should work with ATmega8, ATmegaX8, ATmega32u4, ATmegaX4, ATmegaX0, ATtiny43U, ATtinyX4(A), ATtinyX5, ATtinyX61(A), ATtinyX7, ATtinyX8, ATtiny828, and ATtiny1634. It will not work with ATtinyX13 because of the lack of an ADC. Concerning ATmega8, one should be aware that the bandgap voltage is 1.3 volts instead of 1.1 volts. But who uses an ATmega8 these days?

The library is licensed under the MIT license.
