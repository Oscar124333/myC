# Main Topics/Mechanisms

### Pressure Mapping Sensor
The pressure mapping sensor will be beneath the thermistor array. It is intended for mapping foot pressure, and it will be a commercial version.

### Thermistor Array
The thermistor array will be embedded in a layer of closed-cell neoprene foam. The thermistors are 10k ohms and are meant to read the temperature of the feet. The array itself is connected via 8:1 multiplexers (columns) and 16-bit GPIO expanders branching from an ESP32 (rows). This way, we can share 1 ADC across all the thermistors. As for thermistors, we plan to have 26 columns by 12 rows of thermistors for a total of 312 thermistors.

### Other notes
I am still pretty much a beginner at C code, and I know nothing about coding on ArduinoIDE. I also have no electrical engineering experience, nor do I know much vocabulary besides what voltage and ohms are.
