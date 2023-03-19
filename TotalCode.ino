#include <LiquidCrystal.h> //library necessary for LCD
#include <DHT.h>

LiquidCrystal lcd(18, 15, 23, 22, 21, 19); //connections to ESP32 pins
// | ESP32pin=LCDpin | 18=RS | 15=E | 23=4 | 22=5 | 21=6 | 19=7 | 
 
#define DHTPIN 27 // Sets the pin for the humidity sensor to 27
#define DHTTYPE DHT11 // Sets the sensor type to the Humidity sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  lcd.begin(16, 2); // Set up LCD for 16 columns and 2 rows
  lcd.setCursor(0, 0); // Set cursor to column 0, line 0
  lcd.print("Temp: "); // LCD top row print  | 6 Characters
  lcd.setCursor(0, 1); // Set cursor to column 0, line 1
  lcd.print("Humidity: "); // LCD bottom row print  | 10 Characters
}
 
void loop() 
{
  delay(1500); // Wait for 1.5 seconds till switch

  float humidity = dht.readHumidity(); // Read the Humidity data
  float temperature = dht.readTemperature(); // Read the Temperature data

  lcd.setCursor(6, 0); // Set cursor to column 6, line 1 
  lcd.print(temperature); // LCD top row print temp value
  lcd.print("C"); // LCD top row print Celcius


  lcd.setCursor(10, 1); // Set cursor to column 0, line 1
  lcd.print(humidity); // LCD bottom row print humidity value
  lcd.print("%"); // LCD top row print Celcius

  delay(1500); // Wait for 1.5 seconds till switch
}