// https://forum.arduino.cc/t/problem-using-joystick-potentiometer/883121
// 1. https://www.arduino.cc/reference/en/libraries/mouse/mouse.move/
//Inputs outputs

// #include <Mouse.h>

int xAxis = 0;
int yAxis = 0;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("wtf");
  
  pinMode(A0, INPUT);
  // pinMode(A1,INPUT);
  // pinMode(A2,INPUT);
  // pinMode(A3,INPUT);

  // Mouse.begin();
}

void loop() {
  delay(16);
  
  xAxis = analogRead(xAxis);
  // yAxis = analogRead(yAxis);

    // Serial.print("\nxAxis: " + xAxis);
    // Serial.print("\nyAxis: " + yAxis);

}