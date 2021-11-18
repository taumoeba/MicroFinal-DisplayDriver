#include "pixel_display.hpp"

extern RGBmatrixPanel matrix;
enum commands {null_signal = 0, start_signal = 's', winner_signal = 'w', finish_signal = 'f' };
extern char heatNum;

void matrix_loop();
void parse_input();

void setup() 
{
  matrix.begin();
}


void loop()
{
  while(Serial.available())
  {
    parse_input();
  }

  matrix_loop();
}

void parse_input()
{
  static bool start_received = false;
  static bool winner_received = false;
  static bool finish_received = false;
  
  enum commands input_command = (enum commands)Serial.read();
  
  if(start_received || winner_received || finish_received)
  {
    if(start_received)
    {

    }
  }

  switch(input_command)
  {
    case start_signal:
      race_start();
      startupMessage(); // on boot command
      displayHeat(heatNum);
  
     
      break;
    case winner_signal:
      winner_received = true;
      break;
    case finish_signal:
      finish_received = true;
      break;
    case null_signal:
      break;
    default:
      break;
  }
}
