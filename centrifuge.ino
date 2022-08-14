#include <Servo.h>

Servo motor;
void setup() {
  motor.attach(9);
  delay(1);
  motor.write(10);
  delay(5000);
  motor.writeMicroseconds(2000);
  delay(600000);//10 minutes
  motor.writeMicroseconds(1500);
  motor.detach();
}

void loop() {
}
