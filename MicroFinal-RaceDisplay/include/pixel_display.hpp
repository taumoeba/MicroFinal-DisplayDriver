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

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);
void startupMessage();
void displayHeat(char heatNum);
void dualTimers();
void dualTimers_Lane1Wins();
void dualTimers_Lane2Wins();

#endif