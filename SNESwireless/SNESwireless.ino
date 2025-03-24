// SNES Classic converter
// Wii and WiiU style connection (I am using this for a 3rd party SNES classic controller)
//
//Written by ChrisLeeWoo
//
/* Adapted from:
 *  ArduinoNunchukDemo.ino
 *  Copyright 2011-2013 Gabriel Bianconi, http://www.gabrielbianconi.com/
 *  Project URL: http://www.gabrielbianconi.com/projects/arduinonunchuk/
 */

#include <Wire.h>
#include <ArduinoNunchuk.h>
#include <Keyboard.h>

#define BAUDRATE 19200

ArduinoNunchuk nunchuk = ArduinoNunchuk();

//accelZ
//  1   1    1    1    1    1   1   1   0   0  default when nothing pressed, lots of 1s
//  ?   b    y    a    x    ?   lf  up

//accelY
//  1   1    1    1    1    1   1   1   0   0  default
//  rg  dw   lt   se   ?    st  ?   ?

//accelX only used for rt and lt
//default     0000000000  this is opposite of the others!
//rt pressed  0001111100
//lt pressed  1110000000

const int up_mask = 0b0000000100;
const int dw_mask = 0b0100000000;
const int lf_mask = 0b0000001000;
const int rg_mask = 0b1000000000;

const int a_mask =  0b0001000000;
const int b_mask =  0b0100000000;
const int x_mask =  0b0000100000;
const int y_mask =  0b0010000000;

const int st_mask = 0b0000010000;
const int se_mask = 0b0001000000;
const int lt_mask = 0b1110000000;
const int rt_mask = 0b0001111100;

int rt_press = 0;
int lt_press = 0;
int up_press = 0;
int dw_press = 0;
int lf_press = 0;
int rg_press = 0;
int a_press = 0;
int b_press = 0;
int x_press = 0;
int y_press = 0;
int st_press = 0;
int se_press = 0;

void setup()
{
  Serial.begin(BAUDRATE);
  nunchuk.init();
  Keyboard.begin();

}

void loop()
{
  nunchuk.update();

  //Serial.print(nunchuk.analogX, BIN); //pos and neg
  //Serial.print(' ');
  //Serial.print(nunchuk.analogY, BIN); //pos and neg
  //Serial.print(' ');
  Serial.print(nunchuk.accelX, BIN);  //pos and neg
  Serial.print(' ');
  Serial.print(nunchuk.accelY, BIN);  //pos and neg
  Serial.print(' ');
  Serial.print(nunchuk.accelZ, BIN);  //magic happens
  Serial.print("\n");
  //Serial.print(nunchuk.zButton, DEC);
  //Serial.print(' ');
  //Serial.println(nunchuk.cButton, DEC);
  delay(1);

  rt_press = nunchuk.accelX & rt_mask;
  lt_press = nunchuk.accelX & lt_mask;

  up_press = nunchuk.accelZ & up_mask;
  dw_press = nunchuk.accelY & dw_mask;
  lf_press = nunchuk.accelZ & lf_mask;
  rg_press = nunchuk.accelY & rg_mask;

  a_press = nunchuk.accelZ & a_mask;
  b_press = nunchuk.accelZ & b_mask;
  x_press = nunchuk.accelZ & x_mask;
  y_press = nunchuk.accelZ & y_mask;

  st_press = nunchuk.accelY & st_mask;
  se_press = nunchuk.accelY & se_mask;


  if (rt_press == rt_mask){
    Keyboard.press('w');
    Serial.print("right trigger ");
  }
  else Keyboard.release('w');

  if (lt_press == lt_mask){
  Keyboard.press('q');
    Serial.print("left trigger ");
  }
     else Keyboard.release('q');


  if (up_press != up_mask)
  {  Keyboard.press(KEY_UP_ARROW); }
  else Keyboard.release(KEY_UP_ARROW);

  if (dw_press != dw_mask)
  {  Keyboard.press(KEY_DOWN_ARROW); }
  else Keyboard.release(KEY_DOWN_ARROW);

  if (lf_press != lf_mask)
   { Keyboard.press(KEY_LEFT_ARROW); }
  else Keyboard.release(KEY_LEFT_ARROW);

  if (rg_press != rg_mask)
  {  Keyboard.press(KEY_RIGHT_ARROW); }
  else Keyboard.release(KEY_RIGHT_ARROW);

  if (a_press != a_mask)
  {  Keyboard.press('x'); }
  else Keyboard.release('x');

  if (b_press != b_mask)
  {  Keyboard.press('z'); }
  else Keyboard.release('z');

  if (x_press != x_mask)
  {  Keyboard.press('s'); }
  else Keyboard.release('s');

  if (y_press != y_mask)
  {  Keyboard.press('a'); }
  else Keyboard.release('a');

  if (st_press != st_mask) {
    Keyboard.press(KEY_RETURN);
  } else {
    Keyboard.release(KEY_RETURN)
  }

  char rightShift = KEY_RIGHT_SHIFT;
  if(se_press != se_mask) {
    Keyboard.press(KEY_RIGHT_SHIFT);
  } else {
    Keyboard.release(rightShift);
  }
}
