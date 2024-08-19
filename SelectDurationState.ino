//The select duration state
void selectDuration()
{
  delay(50);
  
  potentiometerValue = analogRead(potentiometerPin);

  //Set the duration; values represent minutes
  if (potentiometerValue <= 250)
  {
    setDuration = 5; // 5 minutes
  }
  else if (250 < potentiometerValue && potentiometerValue <= 500)
  {
    setDuration = 10; // 10 minutes
  }
  else if (500 < potentiometerValue && potentiometerValue <= 750)
  {
    setDuration = 20; // 20 minutes
  }
  else
  {
    setDuration = 30; // 30 minutes
  }

  //Update the display only if the user changed the duration
  if (setDuration != previousSetDuration)
  {
    previousSetDuration = setDuration;

    screen.clear();
    screen.setCursor(0, 0);
    screen.print("Durata:");
    screen.setCursor(8, 0);
    if (setDuration == 5)
    {
      screen.print("05");
    }
    else
    {
      screen.print(setDuration);
    }
    screen.setCursor(11, 0);
    screen.print("min.");
  }
}
