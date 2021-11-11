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

void setup() {
  matrix.begin();
}

void loop() {
  
}
