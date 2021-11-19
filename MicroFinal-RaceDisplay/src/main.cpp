#include "pixel_display.hpp"

#define TIME_BYTES 2
enum commands {null_signal = 0, start_signal = 'S', winner_signal = 'W', finish_signal = 'F' };
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
      delay(2000);
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
    buffer[0] = 255; ///TODO: MSB overflows on display
    buffer[1] = 255;
    //unsigned int time1 = *((unsigned int*)buffer);
    unsigned int temp;
    temp  = (unsigned int) buffer[1];
    temp |=((unsigned int) buffer[0]) << 8;
  
    unsigned int time1 = temp;

    Serial.println("START");

    Serial.print(time1 / 1000UL);
    Serial.print('.');
    Serial.println(time1 % 1000UL);
    Serial.println("END");
    //Serial.readBytesUntil('\n', buffer, TIME_BYTES);
    buffer[1] = 0;
    buffer[0] = 0;
    temp  = (unsigned int) buffer[1];
    temp |=((unsigned int) buffer[0]) << 8;
    unsigned int time2 = temp;
    finalTimes(time1, time2);
    finish_received = false;
  }
}
