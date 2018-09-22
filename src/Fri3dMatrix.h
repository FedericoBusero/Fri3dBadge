// ensure this library description is only included once
#ifndef Fri3dMatrix_h
#define Fri3dMatrix_h

#include <Arduino.h>

#define LATCH_PIN 15
#define CLOCK_PIN 4
#define DATA_PIN 2
#define ENABLE_PIN 13

#define MATRIX_BRIGHTNESS_MAX 16

// library interface description
class Fri3dMatrix {
public:
  Fri3dMatrix();

  void setPixel( int x, int y, int value );
  int getPixel( int x, int y ) const;

  void clear( int value = 0 );
  
  void drawCharacter( int x_offset , char c, int value = 1 );
  void drawString( int x_offset , String s, int value = 1 );
  void showbitmap_progmem(const PROGMEM uint16_t *bitmap );
  void showbitmap(const PROGMEM uint16_t *bitmap );
  
  void render( int delay = 0 ) const;
  void startRenderThread();
  void stopRenderThread();
  void setBrightness(int _brightness);
  
protected:
  int buffer[5][14];
  void shiftIntoRegister( int b ) const;

};

#endif

