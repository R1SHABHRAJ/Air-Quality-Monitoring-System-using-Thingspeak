#include <DHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

#include <WiFi.h>
#include "ThingSpeak.h"

const char *ssid =  "ZARONE 5G";                                  //Your wifi ssid
const char *pass =  "zarone.HBF#";                               //Your wifi passphrase
const char* server = "api.thingspeak.com";
unsigned long Channel_ID = 1427538;                              // Channel ID
const char *WriteAPIKey = "17MUQ90S3BKG9ARH";                    // Your write API Key

WiFiClient client;
#define DHTPIN  27   
#define DHTTYPE DHT11     
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
 WiFi.mode(WIFI_STA);
 
 ThingSpeak.begin(client);
 pinMode(34, INPUT);
 Serial.begin(9600);
 delay(200);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Air Quality");
 lcd.setCursor(0,1);
 lcd.print("Monitor System");
 delay(1500);
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(3500);
    }
     
    Serial.println("\nConnected.");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Connected to :");
    lcd.setCursor(0,1);
    lcd.print(ssid);
    
  }
  else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Fail to connect");
    lcd.setCursor(0,1);
    lcd.print("to ");  
    lcd.setCursor(2,1);
    lcd.print(ssid);
   }
lcd.clear();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Humidity : ");
  Serial.println(h);
  Serial.print("Temperature :");
  Serial.println(t);
  
 int MQ135 = analogRead(34);  //For NH3, NOx, Alcohol, Benzene, Smoke, CO2
 MQ135 = map(MQ135,0,4095,0,300);
 
 Serial.print("MQ135: ");
 Serial.println(MQ135);
 
 int x = ThingSpeak.writeField(Channel_ID, 1, h, WriteAPIKey);
 int y = ThingSpeak.writeField(Channel_ID, 2, t, WriteAPIKey);
 int z = ThingSpeak.writeField(Channel_ID, 3, MQ135, WriteAPIKey);
 
 delay(300);
 //lcd.clear();
  if (MQ135<50) {
    lcd.setCursor(0,0);
    lcd.print("Air Quality : ");
    lcd.setCursor(0,1);
    lcd.print("GOOD");
  }
  if (MQ135>50 && MQ135<100) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Air Quality : ");
    lcd.setCursor(0,1);
    lcd.print("MODERATE");
  }
  else if (MQ135>100 && MQ135<150) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Air Quality : ");
    lcd.setCursor(0,1);
    lcd.print("Good");
  }
  else if (MQ135>150 && MQ135<200) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Air Quality : ");
    lcd.setCursor(0,1);
    lcd.print("Moderate");
  }
  else if (MQ135>200 && MQ135<300) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Air Quality : ");
    lcd.setCursor(0,1);
    lcd.print("UNHEALTHY");
  }
  else if (MQ135>300 && MQ135<500) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Air Quality : ");
    lcd.setCursor(0,1);
    lcd.print("HAZARDOUS");
  
  delay(200);
  }}
