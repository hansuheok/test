/*

Voltaat learn (http://learn.voltaat.com)

Link for full tutorial:

Tutorial: Temperature Controlled Fan using Arduino!

The purpose of this sketch is to make a programmable fan controlled by an Arduino and temperature sensor.When the

temperature goes high, the fan will be turned on, and if the temperature goes low, the fan will be turned off.

Connections from the Arduino to the breadboard:

• Arduino 5v pin → breadboard 5v line

• Arduino GND pin → breadboard GND line

Connection form the DHT11:

• GND pin → Arduino GND pin

• Signal pin → Arduino digital pin 2

• VCC pin → Arduino 5V pin

Connection from the LCD:

• VCC pin → breadboard 5v line

• GND pin→ breadboard GND line

• SDA pin→ Arduino analog pin A4

• SCL pin → Arduino analog pin A5

Connections from the NPN transistor:

• NPN emitter pin → Arduino GND pin

• NPN base pin (middle pin) → Arduino pin 3

• NPN collector pin → Motor first wire

Connections from the motor:

• Motor first wire → NPN collector pin

• Motor second wire → Arduino VCC pin (5V)

*/

#include "DHT.h"

#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD I2C address and dimensions

#define DHTPIN 2     // what pin we're connected to

#define DHTTYPE DHT11   // DHT 11

#define pwm 3

byte degree[8] =

             {

               0b00011,

               0b00011,

               0b00000,

               0b00000,

               0b00000,

               0b00000,

               0b00000,

               0b00000

             };

// Initialize DHT sensor for normal 16mhz Arduino

DHT dht(DHTPIN, DHTTYPE);

void setup() {

 lcd.init(); // Initialize the LCD

 lcd.backlight(); // Turn on the LCD backlight

lcd.createChar(1, degree);

lcd.clear();

lcd.print("   Fan Speed  ");

lcd.setCursor(0,1);

lcd.print("  Controlling ");

delay(2000);

analogWrite(pwm, 255);

lcd.clear();

lcd.print("Robu ");

delay(2000);

 Serial.begin(9600);

 dht.begin();

}

void loop() {

 // Wait a few seconds between measurements.

 delay(2000);

 // Reading temperature or humidity takes about 250 milliseconds!

 // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)

 float h = dht.readHumidity();

 // Read temperature as Celsius

 float t = dht.readTemperature();

 // Read temperature as Fahrenheit

 float f = dht.readTemperature(true);

 

 // Check if any reads failed and exit early (to try again).

 if (isnan(h) || isnan(t) || isnan(f)) {

   Serial.println("Failed to read from DHT sensor!");

   return;

 }

 // Compute heat index

 // Must send in t in Fahrenheit!

 float hi = dht.computeHeatIndex(f, h);

 Serial.print("Humidity: ");

 Serial.print(h);

 Serial.print(" %\t");

 Serial.print("temperature: ");

 Serial.print(t);

 Serial.print(" *C ");

 Serial.print(f);

 Serial.print(" *F\t");

 Serial.print("Heat index: ");

 Serial.print(hi);

 Serial.println(" *F");

   lcd.setCursor(0,0);

 lcd.print("temp: ");

 lcd.print(t);   // Printing terature on LCD

 lcd.print(" C");

 lcd.setCursor(0,1);

  if(t <31 )

   {

     analogWrite(pwm,0);

     lcd.print("Fan OFF            ");

     delay(100);

   }

   

   else if(t==33)

   {            

     analogWrite(pwm, 51);

     lcd.print("Fan Speed: 20%   ");

     delay(100);

   }

   

    else if(t==35)

   {

     analogWrite(pwm, 102);

     lcd.print("Fan Speed: 40%   ");

     delay(100);

   }

   

    else if(t==37)

   {

     analogWrite(pwm, 153);

     lcd.print("Fan Speed: 60%   ");

     delay(100);

   }

   

   else if(t==39)

   {

     analogWrite(pwm, 204);

     

     lcd.print("Fan Speed: 80%    ");

     delay(100);

   }

    else if(t>40)

   {

     analogWrite(pwm, 255);

     lcd.print("Fan Speed: 100%   ");

     delay(100);

   }

 delay(3000);

}

‍
‍
