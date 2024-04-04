// SENSOR DE HUMEDAD Y TEMP DHT22

#include <AM2302-Sensor.h>
AM2302::AM2302_Sensor am2302{4};


const int soil_sensor_pin = A1;	/* Soil moisture sensor O/P pin */

// Calibracion del sensor capacitivo.
const int air = 805; // Sensor de humedad del suelo al aire
const int water = 410; // Sensor de humedad del suelo en agua

void setup() {
  // Initialize serial communication to allow debugging and data readout.
    // Using a baud rate of 9600 bps.
  Serial.begin(9600);
  am2302.begin();

  auto status = am2302.read();
    // Uncomment the line below to set a custom delay between sensor readings (in milliseconds).
    // dht11.setDelay(500); // Set this to the desired delay. Default is 500ms.
}

int count = 0;

void loop() {
  float soil_moisture_percentage;
  float raw_soil_moisture;

  // LEEMOS SENSOR CAPACITIVO DE HUMEDAD DEL SUELO
  raw_soil_moisture = analogRead(soil_sensor_pin);
  soil_moisture_percentage = 100 - map(raw_soil_moisture, water, air, 0, 100);
  if(soil_moisture_percentage > 100){
    soil_moisture_percentage = 100.0;
  }
  else if (soil_moisture_percentage < 0) {
    soil_moisture_percentage = 0.0;
  }
  auto status = am2302.read();
  float temperature = am2302.get_Temperature();
  float humidity = am2302.get_Humidity();


  String datosCombinados = String(temperature) + ";" + String(humidity) + ";" + String(soil_moisture_percentage);

  // Ahora puedes usar la variable datosCombinados como necesites
  Serial.println(datosCombinados);
  count = count + 1;
  delay(5000);
}


