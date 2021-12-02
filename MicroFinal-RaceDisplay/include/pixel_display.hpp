#ifndef   PIXEL_DISPLAY_HPP
#define   PIXEL_DISPLAY_HPP

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

extern RGBmatrixPanel matrix;
// Display startup message, run once in void setup()
void startupMessage();
// Display current heat number
void displayHeat(uint8_t heatNum);
// Display countdown before race
void raceStart();
// Display which car wins. laneNum should be 1 or 2
void carFinish(uint8_t laneNum);
// Display final race times
void finalTimes(unsigned int lane1Millis, unsigned int lane2Millis);
// Display timeout message
void timeOut();
/* Block until X bytes have been received. If the function has a timeout
* the buffer is filled with '\0' to indicate the info was corrupted.*/
void blockReceiveBytes(char *buffer, size_t length);

#endif