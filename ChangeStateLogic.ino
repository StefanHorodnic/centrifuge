//The logic behind changing states
void changeStateLogic()
{
  if (changeToNextState)
  {
    if (state != 5)
    {
      state++;
    }
    else
    {
      state = 0;
    }
    changeToNextState = false;
  }
}
