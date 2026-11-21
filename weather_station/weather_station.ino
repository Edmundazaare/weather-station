#include <DHT.h>

#define DHTPIN 7      
#define DHTTYPE DHT11 

#include <LCD-I2C.h>
#include <Wire.h>

LCD_I2C lcd(0x27, 16, 2);

DHT dht(DHTPIN, DHTTYPE);
float threshold = 40.00;
int ledPin = 8;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(ledPin, OUTPUT);
  Wire.begin();
  lcd.begin(&Wire);
  lcd.display();
  lcd.backlight();
}

void loop() {
  delay(2000);  // Wait 2 seconds between readings

  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();  // Celsius

  if (isnan(humidity) || isnan(temp)) {
    Serial.println("Failed to read DHT sensor");
    return;
  }

  if(threshold >= humidity || threshold >= temp){
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(50);

  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%  Temp: ");
  Serial.print(temp);
  Serial.println("°C");

  //lcd display
    lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.setCursor(6, 0);
  lcd.print(temp);
  lcd.setCursor(12, 0);
  lcd.print("°C");
  lcd.setCursor(0, 1);
  lcd.print("Hum:");
  lcd.setCursor(6, 1);
  lcd.print(humidity);
  lcd.setCursor(12, 1);
  lcd.print("%");
}