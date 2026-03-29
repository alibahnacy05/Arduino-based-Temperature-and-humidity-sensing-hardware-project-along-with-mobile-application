#include <Bonezegei_DHT11.h>

Bonezegei_DHT11 dht(7);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  if (dht.getData()) { // get all data from DHT11
    float tempC = dht.getTemperature();       // temperature in Celsius
    float tempF = (tempC * 9.0 / 5.0) + 32.0;  // convert to Fahrenheit
    int hum = dht.getHumidity();              // humidity

    // Print each value on a new line with updated labels
    Serial.print("Temp in Celsius: ");
    Serial.print(tempC, 1);
    Serial.println("°C");

    Serial.print("Temp in Fahrenheit: ");
    Serial.print(tempF, 1);
    Serial.println("°F");

    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.println("%");
  }

  delay(2000); // delay at least 2 seconds for DHT11 to read the data
}
