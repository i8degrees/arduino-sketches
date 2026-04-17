// rx.ino:jeff
//
// >> Pressure sensor on circa 2011 Honda Oddsy
// >> RX
//

// TODO(JEFF): /home/jeff/Documents/PlatformIO/Projects/cc1101
// https://docs.platformio.org/en/latest/boards/espressif32/esp32doit-devkit-v1.html?utm_source=platformio&utm_medium=piohome

//rst:0x8 (TG1WDT_SYS_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)

//#include <Arduino.h>

// D2 PIN 4 GPIO2 (Integrated LED)
const int ledPin = LED_BUILTIN;
const int csPin = 10; // D5 PIN 8 GPIO5 (CSn)
//const int 

#include <cc1101.h>

using namespace CC1101;

// A4 - GPIO32 - 10 - D32
//Radio radio(/* cs pin */ 10);

// D5 PIN 8 GPIO5 (CSn)
//CC1101::Radio radio(/* cs pin */ csPin, 9, 10, 15);
CC1101::Radio radio(/* cs pin */ csPin);

// CC1101::STATUS_CHIP_NOT_FOUND
//CC1101::Radio radio(/* cs pin */ 10);

int _init() {
  int res = 0;
  int result = 0;

  // >> This is the default and may require further tweaks
  radio.setModulation(CC1101::MOD_ASK_OOK);
  // >> Pressure sensor on circa 2011 Honda Oddsy
  radio.setFrequency(315.00);
  // >> This is the default data rate value; the actual is unknown
  radio.setDataRate(10);
  // >> This is the default RX output value; the actual is unknown
  radio.setOutputPower(10);
  // >> This is the default
  radio.setPacketLengthMode(CC1101::PKT_LEN_MODE_VARIABLE);
  radio.setAddressFilteringMode(CC1101::ADDR_FILTER_MODE_NONE);
  radio.setPreambleLength(64);
  radio.setSyncWord(0x1234);
  radio.setSyncMode(CC1101::SYNC_MODE_16_16);
  radio.setCrc(true);
  radio.setDataWhitening(true);
  radio.setManchester(false);
  radio.setFEC(false);
  
  res = radio.begin();
  Serial.printf("RADIO_STATUS %i\n", res);
  
  if(res == CC1101::STATUS_CHIP_NOT_FOUND) {
    Serial.printf("Chip not found!\n");

    /*while(res == CC1101::STATUS_CHIP_NOT_FOUND) {
      delay_seconds(1);
    }*/
    result = 1;
    return result;
  }
  
  Serial.printf("Chip found! Here we go now... RADIO_STATUS %i\n", res);

  return result;
}

void delay_seconds(int seconds = 1) {
  int milliseconds = seconds * 1000;
  Serial.printf("ZzZ for %i milliseconds...\n", milliseconds);
  delay(milliseconds);
}

void blink(int seconds = 1) {
  
  Serial.printf("LED ON for %i seconds...\n", seconds);
  // Power up!
  digitalWrite(ledPin, HIGH);
  delay_seconds(seconds);
  // Reset OFF
  digitalWrite(ledPin, LOW);
}

void setup() {
  int res = 0;

  // ESP32-DEVKITC-32 ESP-WROOM-32
  Serial.begin(115200); // /dev/ttyACM0
  Serial.println(F("Starting receiver..."));
  
  // Initial state
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.printf("LED_BUILTIN %i\n", LED_BUILTIN);

  blink(4); // 2s
  
  //pinMode(csPin`, OUTPUT);
  // cc1101 lib
  //digitalWrite(csPin, LOW);
  
  Serial.printf("_init mark");
  res = _init();
  Serial.printf("Radio state %i\n", res);
}

enum Comment_Status {
  STATUS_OK = 0,

  STATUS_INVALID_PARAM,
  STATUS_CHIP_NOT_FOUND,
  STATUS_BAD_STATE, 
  STATUS_LENGTH_TOO_SMALL = 4,
  STATUS_LENGTH_TOO_BIG = 5,
  STATUS_CRC_MISMATCH = 6,
  STATUS_TXFIFO_UNDERFLOW,
  STATUS_RXFIFO_OVERFLOW = 8
};

void loop() {
  // return;
  char buff[32];
  size_t read;

  Serial.printf("mark\n");

  // Try to receive a packet
  CC1101::Status status = radio.receive((uint8_t *)buff, sizeof(buff) - 1, &read);
  Serial.printf("RX_STATUS %i\n", status);

  if(status == CC1101::STATU``S_OK) { // 0

    buff[read] = '\0'; // null-terminate string

    Serial.printf("Received: \n");
    Serial.println(buff);

    // Success! 1s "blink"; this is unlikely to *ever* occur as we do not have an identical TX module handy
    if (strcmp(buff, "hello") == 0) {
      blink(3);
    } else {
      Serial.printf("sub-1ghz signal detected\n");
      blink(1); // test bit code
    }
  } // else > 0
} 

`
