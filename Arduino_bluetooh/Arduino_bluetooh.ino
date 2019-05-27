#include <SoftwareSerial.h>

SoftwareSerial miBT(10, 11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Listo");
  miBT.begin(38400); 
}

void loop() {
  // put your main code here, to run repeatedly:
  if (miBT.available())
  Serial.write(miBT.read());

  if (Serial.available())
  miBT.write(Serial.read());

}
