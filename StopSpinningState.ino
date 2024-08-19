//The stop spinning logic
void stopSpinning()
{
  servo.write(0);
  servo.detach();
  
  delay(50);

  servo.attach(9);
  servo.write(21);
  
  screen.clear();
  screen.setCursor(5, 0);
  screen.print("Gata!");
  
  delay(5000);

  servo.write(21);

  screen.clear();
  
  changeToNextState = true; //Change the state automatically
}
