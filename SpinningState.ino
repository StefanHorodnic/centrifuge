//The actual spinning state
void spinning()
{
  //Measure current rpm
  infraRedState = digitalRead(infraRedPin); // Read IR sensor state

  if ( infraRedPreviousState != infraRedState) // If there is change in input
  {
    infraRedPreviousState = infraRedState;

    if (infraRedState == HIGH) // If input changes only from LOW to HIGH
    {
      oneRevolutionDuration = ( millis() - previousRevolutionTime );
      previousRevolutionTime = millis();
      currentRpm = 60000 / oneRevolutionDuration;
    }
  }

  //Adjust speed acording to set speed every 1 sec after 10 seconds of spinning
  if ((millis() - speedAdjustTime) >= 1000 && millis() - startSpinningTime > 10000)
  {   
    if (currentRpm < setRpm - rpmPrecision)
    {
      if (servoValue + servoFactor < servoMaxim)
      {
        servoValue = servoValue + servoFactor;
        servo.write(servoValue);
      }
    }
    if (currentRpm > setRpm + rpmPrecision)
    {
      if (servoValue - servoFactor > servoMinim)
      {
        servoValue = servoValue - servoFactor;
        servo.write(servoValue);
      }
    }
    speedAdjustTime = millis();
  }

  //Update screen every 1 second
  if ((millis() - screenRefreshTime) >= 1000)
  {
    int minutesPast = (millis() - startSpinningTime) / 60000;

    screen.clear();
    screen.setCursor(0, 0);
    screen.print("Timp");
    screen.setCursor(6, 0);
    screen.print(setDuration - minutesPast);
    screen.setCursor(8, 0);
    screen.print("min.");
    screen.setCursor(0, 1);
    screen.print("RPM");
    screen.setCursor(4, 1);
    screen.print(currentRpm);

    screenRefreshTime = millis();

    if(setDuration - minutesPast == 0)
    {
      changeToNextState = true;
    }
  }
}
