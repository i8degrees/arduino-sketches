// UART Serial loopback test
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200, SERIAL_8N1);
  Serial.println("hi");
}

void loop() {
  if (Serial.available() == true) {
    char data_rcvd = Serial.read();
    Serial.write(data_rcvd); 
  }
}
