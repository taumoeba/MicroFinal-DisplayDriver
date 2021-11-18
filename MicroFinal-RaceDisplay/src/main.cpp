#include "pixel_display.hpp"

#define TIME_BYTES 4
enum commands {null_signal = 0, start_signal = 's', winner_signal = 'w', finish_signal = 'f' };
extern char heatNum;

void pixel_loop();
void parse_input();

void setup() 
{
  matrix.begin();
  Serial.begin(9600);
  Serial.setTimeout(10000);
  startupMessage(); // on boot command
}


void loop()
{
  while(Serial.available())
  {
    parse_input();
  }

  //pixel_loop();
}

void parse_input()
{
  static bool winner_received = false;
  static bool finish_received = false;
  char buffer[TIME_BYTES];

  enum commands input_command = (enum commands)Serial.read();

  switch(input_command)
  {
    case start_signal:
      displayHeat(heatNum);
      delay(5000);
      raceStart();
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

  if(winner_received)
  {
    Serial.readBytesUntil('\n', buffer, 1);
    carFinish(buffer[0]);
    winner_received = false;
  }
  else if(finish_received)
  {
    //Serial.readBytesUntil('\n', buffer, TIME_BYTES);
    buffer[0] = 129; ///TODO: MSB overflows on display
    buffer[1] = 100;
    buffer[3] = 100;
    buffer[4] = 100;
    unsigned long time1 = (unsigned long)buffer[0];
    //Serial.readBytesUntil('\n', buffer, TIME_BYTES);
    buffer[0] = 1;
    buffer[1] = 1;
    buffer[3] = 1;
    buffer[4] = 1;
    unsigned long time2 = (unsigned long)buffer[0];
    finalTimes(time1, time2);
    finish_received = false;
  }
}
