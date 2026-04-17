//Transmitter

#include <Arduino.h>

#include <cc1101.h>


using namespace CC1101;

Radio radio(/* cs pin */ 10);

const int triggerPin = 3;   // D3 input

void setup() {
  // ESP32-WROOM devkit
  // /dev/ttyACM0
  Serial.begin(115200);

  delay(3000);

  Serial.println(F("Starting ..."));

  delay(1000);

  pinMode(triggerPin, INPUT);   // use INPUT_PULLUP if your switch goes to GND

  if (radio.begin() == STATUS_CHIP_NOT_FOUND) {

    Serial.println(F("Chip not found!"));

    while (true) { delay(1000); }

  }

  radio.setModulation(MOD_ASK_OOK);

  radio.setFrequency(433.8);

  radio.setDataRate(10);

  radio.setOutputPower(10);

  radio.setPacketLengthMode(PKT_LEN_MODE_VARIABLE);

  radio.setAddressFilteringMode(ADDR_FILTER_MODE_NONE);

  radio.setPreambleLength(64);

  radio.setSyncWord(0x1234);

  radio.setSyncMode(SYNC_MODE_16_16);

  radio.setCrc(true);

  radio.setDataWhitening(true);

  radio.setManchester(false);

  radio.setFEC(false);

}

void loop() {

  // Check if D3 is HIGH

  if (digitalRead(triggerPin) == HIGH) {

    const char *msg = "hello";

    Serial.print(F("Transmitting: "));

    Serial.println(msg);

    Status status = radio.transmit((const uint8_t *)msg, strlen(msg));

    if (status == STATUS_OK) {

      Serial.println(F("[OK]"));

    } else {

      Serial.print("[ERROR ");

      Serial.print(status);

      Serial.println("]");

    }

    delay(500); // debounce / avoid flooding

  }

}

