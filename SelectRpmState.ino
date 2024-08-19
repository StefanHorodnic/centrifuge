//The select rpm state
void selectRpm()
{
  delay(50);
  
  potentiometerValue = analogRead(potentiometerPin);

  //Set the speed; values represent rpms
  if (potentiometerValue <= 250)
  {
    setRpm = 2000; // 2000 rpm
  }
  else if (250 < potentiometerValue && potentiometerValue <= 500)
  {
    setRpm = 3000; // 3000 rpm
  }
  else if (500 < potentiometerValue && potentiometerValue <= 750)
  {
    setRpm = 4000; // 4000 rpm
  }
  else
  {
    setRpm = 5000; // 5000 rpm
  }

  //Update the display only if the user changed the duration
  if (setRpm != previousSetRpm)
  {
    previousSetRpm = setRpm;

    screen.clear();
    screen.setCursor(0, 0);
    screen.print("Viteza:");
    screen.setCursor(8, 0);
    screen.print(setRpm);
    screen.setCursor(13, 0);
    screen.print("RPM");
  }
}
