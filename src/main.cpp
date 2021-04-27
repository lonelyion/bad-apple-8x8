#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <stdlib.h>
#include <time.h>

Adafruit_NeoPixel *pixels;
int pin = D2;
int numPixels = 64;
uint8_t test;

uint8_t buffer[9];
char cmap[8][8];
uint32_t black, white;
uint32_t color;

#define DELAYVAL 500

uint32_t get_white(uint8_t gray) {
  return pixels->Color(gray, gray, gray);
}

void setup() {
  Serial.begin(115200);
  pixels = new Adafruit_NeoPixel(numPixels, pin, NEO_GRB + NEO_KHZ400);
  pixels->begin();
  black = pixels->Color(0,0,0);
  white = pixels->Color(255,255,255);
  pixels->clear();
  for(int i = 0; i < numPixels; i++) {
    pixels->setPixelColor(i, pixels->Color(0xAA, 0xAA, 0xAA));
  }
  pixels->show();
  //delay(5000);
}

void loop() {
  if(Serial.available() > 0) {
    for(int i = 0; i < 8; i++) {
      Serial.readBytes(buffer, 8);
      for(int j = 0; j < 8; j++) {
        if(buffer[j] > 128) {
          color = pixels->Color(0xAA,0xAA,0);
        } else {
          color = pixels->Color(1,1,1);
        }
        pixels->setPixelColor((i % 2 == 0 ? i*8+j : i*8-j+7), color);
      }
    }
    pixels->show();
  }
}
