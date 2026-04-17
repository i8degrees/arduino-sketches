// https://wicg.github.io/webusb/#enumeration
// https://github.com/webusb/arduino/
// https://webusb.github.io/arduino/demos/
// https://editor.p5js.org/shawn/sketches/tQA-v09N_
// Third-party WebUSB Arduino library
#include <WebUSB.h>

WebUSB WebUSBSerial(1 /* https:// */, "editor.p5js.org/shawn/full/tQA-v09N_");  // Landing page

#define Serial WebUSBSerial

const int ledPin = 13;
int inByte = 0;

void setup() {
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, LOW);
  delay(500);
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
  digitalWrite(ledPin, HIGH);
  
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for serial port to connect.
  }
  
  Serial.write("WebUSB!");
  Serial.flush();
  
  digitalWrite(ledPin, LOW);
  delay(500);
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
  digitalWrite(ledPin, HIGH);
}

void loop() {
  if (Serial) {
    digitalWrite(ledPin, LOW);
    delay(500);
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
    digitalWrite(ledPin, HIGH);
    inByte = Serial.read();
    Serial.write(inByte);
    Serial.flush();
    delay(10);
  }
}
