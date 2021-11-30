#include "pixel_display.hpp"

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);
char heatNum = '4'; //Temp var for testing

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

void raceProgress()
{
  uint16_t img = 0;
  matrix.drawRGBBitmap(0, 0, &img, 64, 32);
  //matrix.drawRGBBitmap(0, 0, &img, &mask, 64, 32);
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

void finalTimes(unsigned int lane1Millis, unsigned int lane2Millis) 
{
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
  unsigned int time_check = lane1Millis/1000;
  if (time_check >=10)
  {
    timeOut();
  }
  else
  {
    matrix.print(time_check);
    matrix.setCursor(6,21);
    matrix.print('.');
    matrix.setCursor(11,21);
    matrix.print(lane1Millis%1000);
  }

  // Time 2
  matrix.setCursor(35,21);
  time_check = lane2Millis/1000;
  if (time_check >=10)
  {
    timeOut();
  }
  else
  {
    matrix.print(time_check);
    matrix.setCursor(40,21);
    matrix.print('.');
    matrix.setCursor(45,21);
    matrix.print(lane2Millis%1000);
  }
 
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

void pixel_setup()
{
  matrix.begin();
}

void pixel_loop() {
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

