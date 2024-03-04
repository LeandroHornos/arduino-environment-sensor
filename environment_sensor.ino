// Include the DHT11 library for interfacing with the sensor.
#include <DHT11.h>

// Create an instance of the DHT11 class.
// - For Arduino: Connect the sensor to some Digital I/O Pin (here pin 4).
DHT11 dht11(4);
const int sensor_pin = A1;	/* Soil moisture sensor O/P pin */


void setup() {
  // Initialize serial communication to allow debugging and data readout.
    // Using a baud rate of 9600 bps.
    Serial.begin(9600);
    
    // Uncomment the line below to set a custom delay between sensor readings (in milliseconds).
    // dht11.setDelay(500); // Set this to the desired delay. Default is 500ms.
}

void loop() {
  int temperature = 0;
  int humidity = 0;
  float moisture_percentage;
  int sensor_analog;

  // Read moisture
  sensor_analog = analogRead(sensor_pin);
  moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );

  // Attempt to read the temperature and humidity values from the DHT11 sensor.
  int result = dht11.readTemperatureHumidity(temperature, humidity);

  // Check the results of the readings.
  // If the reading is successful, print the temperature and humidity values.
  // If there are errors, print the appropriate error messages.
  if (result == 0) {
      Serial.print("\nTemperature: ");
      Serial.print(temperature);
      Serial.print(" °C\nHumidity: ");
      Serial.print(humidity);
  } else {
      // Print error message based on the error code.
      Serial.println(DHT11::getErrorString(result));
  }
  Serial.print("%\nSoil Moisture Percentage = ");
  Serial.print(moisture_percentage);
  Serial.print("%\n");
  
  delay(2000);
}


