
//The logic behind the button press
void buttonLogic()
{
  //Read the button pin to capture if the user pressed the side button
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW)
  {
    if (wasButtonStateHigh)
    {
      changeToNextState = true;
    }
    wasButtonStateHigh = false;
  }
  else
  {
    wasButtonStateHigh = true;
  }
}
