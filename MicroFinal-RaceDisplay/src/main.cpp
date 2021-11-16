#include <Arduino.h>
#include <SPI.h>
#include <RGBmatrixPanel.h>

#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);

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

char inByte = 0;
char dualTimersMsg[] = {'0','.','0', '0', '0'};
char dualTimersMsg2[] = {'8','.','0', '3', '6'};

void startupMessage() { // Slide 1
  matrix.setCursor(2,4);
  matrix.println("Rocket Car");
  matrix.setCursor(2,16);
  matrix.println("Race Track");
}

void displayHeat(int heatNum) { // Between slides 2 and 3
  matrix.setTextSize(2);
  matrix.setCursor(8,0);
  matrix.print("Heat");
  matrix.setCursor(20,16);
  matrix.print("#");
  matrix.print(heatNum);
}

void dualTimers() { // Not final function
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  matrix.setCursor(4,0);
  matrix.print("Car");
  matrix.setCursor(22, 0); // Same x-loc as end of previous char
  matrix.print("1"); // "Car 1" is 22 pixels long
  matrix.drawLine(31, 0, 31, 32, matrix.Color333(7,7,7));
  matrix.drawLine(32, 0, 32, 32, matrix.Color333(7,7,7));
  matrix.setCursor(37, 0);
  matrix.print("Car");
  matrix.setCursor(55, 0);
  matrix.print("2");
  matrix.setCursor(1, 16);
  for(int i=0; i<5; i++) {
    matrix.print(dualTimersMsg[i]);
  }
  matrix.setCursor(34, 16);
  for(int i=0; i<5; i++) {
    matrix.print(dualTimersMsg[i]);
  }
}

void dualTimers_Lane1Wins() { // Not final function
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  //Line
  matrix.drawLine(31, 0, 31, 32, matrix.Color333(7,7,7));
  matrix.drawLine(32, 0, 32, 32, matrix.Color333(7,7,7));
  //Car2
  matrix.setCursor(37, 0);
  matrix.print("Car");
  matrix.setCursor(55, 0);
  matrix.print("2");
  // Car 1 Wins
  matrix.setCursor(4, 4);
  matrix.setTextColor(matrix.Color888(0,255,0));
  matrix.print("Car");
  matrix.setCursor(22, 4); // Same x-loc as end of previous char
  matrix.print("1"); // "Car 1" is 22 pixels long
  matrix.setCursor(2,16);
  matrix.print("Wins!");
  //Car 2
  matrix.setCursor(34, 16);
  matrix.setTextColor(matrix.Color888(255,255,255));
  for(int i=0; i<5; i++) {
    matrix.print(dualTimersMsg2[i]);
  }
}

void setup() {
  matrix.begin();
  Serial.begin(9600);
  matrix.setCursor(0, 0);
  matrix.setTextSize(1);
  /* Printing a float
  for(int i=0; i<3; i++) {
    matrix.print(printThis[i]);
  }
  */
}

void loop() {
  /*
  if(Serial.available() > 0) {
    inByte = Serial.read();
   matrix.print(inByte);
  }
  
 dualTimers();
 dualTimers_Lane1Wins();
 */
  displayHeat(4);
  
}
