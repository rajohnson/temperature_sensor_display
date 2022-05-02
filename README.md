# temperature_sensor_display
Read temperature sensors and display results on a character LCD.

Simple exploratory project. Reads temperature from a thermistor and a thermocouple and displays results on a LCD screen. 

Even though the HD44780 are very prevalent I hadn't written a driver to communicate with one before. I took care not to review other implementations until after I had the drive almost working. At the end I was having trouble getting the display to communicate and I referenced the mbed TextLCD to determine if I had problems with my initialization sequence (I didn't, it was a problem with the voltage on V0 that was preventing the screen from displaying data, but the TextLCD implementation is more concise and more versatile than my implementation.) https://os.mbed.com/users/simon/code/TextLCD/docs/308d188a2d3a/classTextLCD.html

I read the voltage across the thermistor with the ADC and calculate temperature using the Steinhart-Hart equation. https://en.wikipedia.org/wiki/Steinhart%E2%80%93Hart_equation

I communicate with the thermocouple through a MAX6675 which provides a SPI interface. 

https://youtu.be/gvPTWrA5Q_I

Eventually I would like to add the capacity to set the units. 
