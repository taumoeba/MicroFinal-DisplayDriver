#include "pixel_display.hpp"

<<<<<<< HEAD
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
=======
/* DON'T DELETE YET. Method 1 for active timer.
unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= 250) {
    previousMillis = currentMillis;
    raceTimer++;

    displayTimers(raceTimer);
  }


unsigned long currentMillis = millis();
unsigned long previousMillis = 0;
unsigned long raceTimer = 0; // Must reset when race is done. When displaying results?
*/

void startupMessage() { // Display once in void setup()
  matrix.setTextColor(matrix.Color888(252,255,255));
  matrix.fillScreen(matrix.Color333(0, 0, 0)); // Blank screen
  matrix.setTextSize(1);
  matrix.setCursor(2,4);
  matrix.println("Rocket Car");
  matrix.setCursor(2,16);
  matrix.println("Race Track");
}

void displayHeat(char heatNum) { // TO FIX: If heatNum is over 9, formatting gets weird
  matrix.setTextColor(matrix.Color888(255,255,255));
  matrix.fillScreen(matrix.Color333(0, 0, 0)); // Blank screen
  matrix.setTextSize(2);
  matrix.setCursor(8,1);
  matrix.print("Heat");
  matrix.setCursor(20,17);
  matrix.print("#");
  matrix.print(heatNum);
}

void raceStart() {
  matrix.setTextColor(matrix.Color888(255,255,255));
  matrix.fillScreen(matrix.Color333(0, 0, 0)); // Blank screen
  matrix.setTextSize(4);
  matrix.setCursor(22,2);
  matrix.setTextColor(matrix.Color888(255, 0, 0));
  matrix.print('3');
  delay(1000);
  matrix.fillScreen(matrix.Color333(0, 0, 0)); // Blank screen
  matrix.setCursor(22,2);
  matrix.setTextColor(matrix.Color888(252, 119, 3));
  matrix.print('2');
  delay(1000);
  matrix.fillScreen(matrix.Color333(0, 0, 0)); // Blank screen
  matrix.setCursor(22,2);
  matrix.setTextColor(matrix.Color888(252, 186, 3));
  matrix.print('1');
  delay(1000);
  matrix.fillScreen(matrix.Color333(0, 0, 0)); // Blank screen
  matrix.setCursor(10,2);
  matrix.setTextColor(matrix.Color888(0, 255, 0));
  matrix.print("GO");
}

void carFinish(char laneNum) { // laneNum should be 1 or 2
  matrix.setTextColor(matrix.Color888(255,255,255));
  matrix.fillScreen(matrix.Color333(0, 0, 0)); // Blank screen
  matrix.setTextSize(2);
  matrix.setCursor(6,1);
  matrix.print("Car ");
  matrix.setCursor(48,1);
  matrix.print(laneNum);
  matrix.setCursor(4,17);
  matrix.print("Wins!");
}

void finalTimes(unsigned long lane1Millis, unsigned long lane2Millis) {
  matrix.setTextColor(matrix.Color888(255,255,255));
  matrix.fillScreen(matrix.Color333(0, 0, 0)); // Blank screen
  // Final Times
  matrix.setTextSize(1);
  matrix.setCursor(1,0);
  matrix.print("Final");
  matrix.setCursor(34,0);
  matrix.print("Times");
  // Dividing Lines
  matrix.drawLine(31, 9, 31, 32, matrix.Color888(0,0,255));
  matrix.drawLine(32, 9, 32, 32, matrix.Color333(0,0,255));
  matrix.drawLine(0,9,64,9,matrix.Color888(0,0,255));
  // Car 1
  matrix.setCursor(3,11);
  matrix.print("Car");
  matrix.setCursor(22,11);
  matrix.print("1");
  // Car 2
  matrix.setCursor(36,11);
  matrix.print("Car");
  matrix.setCursor(55,11);
  matrix.print("2");
  // Time 1
  matrix.setCursor(2,21);
  matrix.print(lane1Millis/1000);
  matrix.setCursor(6,21);
  matrix.print('.');
  matrix.setCursor(11,21);
  matrix.print(lane1Millis-((lane1Millis/1000)*1000));
  // Time 2
  matrix.setCursor(35,21);
  matrix.print(lane2Millis/1000);
  matrix.setCursor(40,21);
  matrix.print('.');
  matrix.setCursor(45,21);
  matrix.print(lane2Millis-((lane2Millis/1000)*1000));
}

void timeOut() {
  matrix.setTextColor(matrix.Color888(255,255,255));
  matrix.fillScreen(matrix.Color333(0, 0, 0)); // Blank screen
  matrix.setTextSize(2);
  matrix.setCursor(8,1);
  matrix.print("Time");
  matrix.setCursor(16,17);
  matrix.print("Out");
}

void setup()
{
  matrix.begin();
}

void loop() {
  // Looping through available screens
  startupMessage();
  delay(2000);
  displayHeat('4');
  delay(2000);
  raceStart();
  delay(2000);
  timeOut();
  delay(2000);
  carFinish('1');
  delay(2000);
  carFinish('2');
  delay(2000);
  finalTimes(4317, 5184);
  delay(2000);
}
>>>>>>> f3c5a5e7da1a8615eb123188298423be8382b9d4
