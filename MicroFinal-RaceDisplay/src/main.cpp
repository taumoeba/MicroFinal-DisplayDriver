#include "pixel_display.hpp"


/* Usable Functions:

 draw a pixel in solid white
matrix.drawPixel(0, 0, matrix.Color333(7, 7, 7));

 fix the screen with green
matrix.fillRect(0, 0, 32, 16, matrix.Color333(0, 7, 0));

 draw a box in yellow
matrix.drawRect(0, 0, 32, 16, matrix.Color333(7, 7, 0));

 draw an 'X' in red
matrix.drawLine(0, 0, 31, 15, matrix.Color333(7, 0, 0));
matrix.drawLine(31, 0, 0, 15, matrix.Color333(7, 0, 0));

 draw a blue circle
matrix.drawCircle(7, 7, 7, matrix.Color333(0, 0, 7));
 
 fill a violet circle
matrix.fillCircle(23, 7, 7, matrix.Color333(7, 0, 7));

 fill the screen with 'black'
matrix.fillScreen(matrix.Color333(0, 0, 0));

// draw some text!
matrix.setTextSize(1);     // size 1 == 8 pixels high
matrix.setTextWrap(false); // Don't wrap at end of line - will do ourselves

matrix.setCursor(8, 0);    // start at top left, with 8 pixel of spacing
uint8_t w = 0;
char *str = "AdafruitIndustries";
for (w=0; w<8; w++) {
  matrix.setTextColor(Wheel(w));
  matrix.print(str[w]);
}

*/

/* DON'T DELETE YET. Method 1 for active timer.
unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= 250) {
    previousMillis = currentMillis;
    raceTimer++;

    displayTimers(raceTimer);
  }
*/

char inByte = 0;
//char zeroTimersMsg[] = {'0','.','0', '0', '0'};
//unsigned long currentMillis = millis();
//unsigned long previousMillis = 0;
//unsigned long raceTimer = 0; // Must reset when race is done. When displaying results?

void startupMessage() { // Display once in void setup()
  matrix.setTextColor(matrix.Color888(255,255,255));
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

// Reads data from serial port and prints it on the display. Add Serial.begin(9600) to void setup() to use.
void serialEcho() {
  if(Serial.available() > 0) {
    inByte = Serial.read();
   matrix.print(inByte);
  }
}

void pixel_setup()
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
  carFinish('1');
  delay(2000);
  carFinish('2');
  delay(2000);
  finalTimes(4317, 5184);
  delay(2000);
}
