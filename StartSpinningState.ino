//The start of thw spinning state
void startSpinning()
{
//  if(servo.attached() == false)
//  {
//    servo.attach(9);
//    servo.write(21);
//  }
  
  delay(1000);
  
  //Set the write value to 59 (I don't know why this is the minimum value)
  servoValue = servoMinim;
  servo.write(servoValue);
  startSpinningTime = millis();
  changeToNextState = true; //Change the state automatically
}
