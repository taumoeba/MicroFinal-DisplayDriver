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
void startupMessage();
void displayHeat(char heatNum);
void raceStart();
void carFinish(char laneNum);
void finalTimes(unsigned long lane1Millis, unsigned long lane2Millis);
void timeOut();

#endif