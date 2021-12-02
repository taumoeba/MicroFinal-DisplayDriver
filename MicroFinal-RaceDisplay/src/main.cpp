#include "pixel_display.hpp"

#define TIME_BYTES 2
#define BAUD_RATE 9600
enum commands {null_signal = 0, start_signal = 'S', winner_signal = 'W', finish_signal = 'F' };
extern char heatNum;

void pixel_loop();
void parse_input();

void setup() 
{
  // Start matrix and serial communication
  matrix.begin();
  Serial.begin(9600);
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
    blockReceiveBytes(buffer, 1);
    carFinish(buffer[0]);
    winner_received = false;
  }
  else if(finish_received)
  {
    blockReceiveBytes(buffer, TIME_BYTES);
    // buffer[1] = 3;
    //buffer[0] = 3; ///TODO: MSB overflows on display
 
    //unsigned int time1 = *((unsigned int*)buffer);
    unsigned int temp = 0;
    temp  = (unsigned int) buffer[0];
    temp |=((unsigned int) buffer[1]) << 8;
  
    unsigned int time1 = temp;

    Serial.println("START");

    Serial.print(time1 / 1000);
    Serial.print('.');
    Serial.println(time1 % 1000);
    Serial.println("END");
    Serial.println(time1);
    blockReceiveBytes(buffer, TIME_BYTES);
    //buffer[1] = 9;
    //buffer[0] = 9;
    temp  = (unsigned int) buffer[0];
    temp |=((unsigned int) buffer[1]) << 8;
    unsigned int time2 = temp;
    finalTimes(time1, time2);
    finish_received = false;
  }
}
