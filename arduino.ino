#include <Servo.h>
#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>

#define FIREBASE_URL "shitty-c8eda.firebaseio.com"
#define FIREBASE_AUTH "FgCXjwAr9JHQjJGx88fKwvIuqo103KoGSFgcTKvK"
#define WIFI_SSID "wit-iphone"
#define WIFI_PASSWORD "234567890"

int i = 1;
const int CloseAngle = 90;
const int OpenAngle = 180;
int currentAngle;
int UpdateAngle;


Servo servo;
const int buzzer = D3;

void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_URL, FIREBASE_AUTH);
  servo.attach(D4);

  pinMode(D2,OUTPUT);
  pinMode(D4,OUTPUT);
  pinMode(buzzer, OUTPUT);
   //digitalWrite(D1, Firebase.getInt("IonicArduino/LED1"));

}

void loop() {
  currentAngle = Firebase.getFloat("IonicArduino/Range");
  
  if (currentAngle == CloseAngle || currentAngle == 0) {
   digitalWrite(D2, HIGH);
   noTone(buzzer);
   
   }
   else {
   digitalWrite(D2, LOW);
   tone(buzzer, 261);
   delay(100);
   tone(buzzer, 294);
   delay(100);
   tone(buzzer, 329);
   delay(100);
   tone(buzzer, 349);
   delay(100);
   tone(buzzer, 392);
   delay(100);
   tone(buzzer, 440);
   delay(100);
   tone(buzzer, 493);
   delay(100);
   tone(buzzer, 532);
   delay(100);
   }
   
  
  servo.write(Firebase.getFloat("IonicArduino/Range"));
  Serial.println(Firebase.getFloat("IonicArduino/Range"));
  

}
