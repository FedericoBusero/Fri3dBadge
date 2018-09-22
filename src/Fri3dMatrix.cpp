// include this library's description file
#include "Fri3dMatrix.h"
#include "Arduino.h"

uint8_t font[ 96 * 3 ] = {
  0x00, 0x00, 0x00,      // (space)
  0x17, 0x00, 0x00,  // !
  0x03, 0x00, 0x03,  // "
  0x0A, 0x1F, 0x0A,  // #
  0x16, 0x13, 0x1A,  // 0x
  0x09, 0x04, 0x0A,  // %
  0x0A, 0x15, 0x1A,  // &
  0x03, 0x00, 0x00,  // '
  0x00, 0x0E, 0x11,  // (
  0x11, 0x0E, 0x00,  // )
  0x06, 0x06, 0x00,  // *
  0x04, 0x0E, 0x04,  // +
  0x0C, 0x1C, 0x00,  // ,
  0x04, 0x04, 0x04,  // -
  0x10, 0x00, 0x00,  // .
  0x18, 0x04, 0x03,  // /
  //numbers created from: https://fontstruct.com/fontstructions/show/188079/tiny_3x5
  0x0E, 0x11, 0x0E,  // 0
  0x12, 0x1F, 0x10,  // 1
  0x12, 0x19, 0x16,  // 2
  0x11, 0x15, 0x0A,  // 3
  0x07, 0x04, 0x1F,  // 4
  0x17, 0x15, 0x09,  // 5
  0x0E, 0x15, 0x08,  // 6
  0x01, 0x19, 0x07,  // 7
  0x0A, 0x15, 0x0A,  // 8
  0x02, 0x15, 0x0E,  // 9
  0x00, 0x0A, 0x00,  // :
  0x00, 0x1A, 0x00,  // ;
  0x04, 0x0A, 0x11,  // <
  0x0A, 0x0A, 0x0A,  // =
  0x11, 0x0A, 0x04,  // >
  0x00, 0x15, 0x07,  // ?
  0x1F, 0x15, 0x17,  // @
  0x1F, 0x05, 0x1F,  // A
  0x1F, 0x15, 0x1B,  // B
  0x1F, 0x11, 0x11,  // C
  0x1F, 0x11, 0x0E,  // D
  0x1F, 0x15, 0x15,  // E
  0x1F, 0x05, 0x01,  // F
  0x1F, 0x11, 0x1D,  // G
  0x1F, 0x04, 0x1F,  // H
  0x11, 0x1F, 0x11,  // I
  0x08, 0x10, 0x0F,  // J
  0x1F, 0x04, 0x1B,  // K
  0x1F, 0x10, 0x10,  // L
  0x1F, 0x02, 0x1F,  // M
  0x1F, 0x01, 0x1E,  // N
  0x1F, 0x11, 0x1F,  // O
  0x1F, 0x05, 0x07,  // P
  0x0E, 0x19, 0x1E,  // Q
  0x1F, 0x05, 0x1B,  // R
  0x17, 0x15, 0x1D,  // S
  0x01, 0x1F, 0x01,  // T
  0x1F, 0x10, 0x1F,  // U
  0x0F, 0x10, 0x0F,  // V
  0x1F, 0x0C, 0x1F,  // W
  0x1B, 0x04, 0x1B,  // X
  0x17, 0x14, 0x1F,  // Y
  0x19, 0x15, 0x13,  // Z
  0x00, 0x1F, 0x11,  // [
  0x03, 0x04, 0x18,  // BackSlash
  0x11, 0x1F, 0x00,  // ]
  0x06, 0x01, 0x06,  // ^
  0x10, 0x10, 0x10,  // _
  0x01, 0x01, 0x02,  // `
  0x18, 0x14, 0x1C,  // a
  0x1F, 0x14, 0x1C,  // b
  0x1C, 0x14, 0x14,  // c
  0x1C, 0x14, 0x1F,  // d
  0x0C, 0x1A, 0x14,  // e
  0x04, 0x1E, 0x05,  // f
  0x17, 0x15, 0x1E,  // g
  0x1F, 0x04, 0x1C,  // h
  0x00, 0x1D, 0x00,  // i
  0x08, 0x10, 0x0D,  // j
  0x1F, 0x0C, 0x1A,  // k
  0x00, 0x1F, 0x00,  // l
  0x18, 0x0C, 0x18,  // m
  0x1C, 0x04, 0x18,  // n
  0x1E, 0x12, 0x1E,  // o
  0x1F, 0x05, 0x07,  // p
  0x07, 0x05, 0x1F,  // q
  0x1E, 0x04, 0x04,  // r
  0x12, 0x15, 0x09,  // s
  0x02, 0x1F, 0x02,  // t
  0x1C, 0x10, 0x1C,  // u
  0x0C, 0x10, 0x0C,  // v
  0x0C, 0x18, 0x0C,  // w
  0x14, 0x08, 0x14,  // x
  0x16, 0x18, 0x06,  // y
  0x04, 0x1C, 0x10,  // z
  0x04, 0x0E, 0x11,  // {
  0x00, 0x1F, 0x00,  // |
  0x11, 0x0E, 0x04,  // }
  0x02, 0x04, 0x02,  // ~
  0x1F, 0x1F, 0x1F   //
};

Fri3dMatrix::Fri3dMatrix() {
  pinMode( LATCH_PIN, OUTPUT );
  digitalWrite( LATCH_PIN, 1 );
  pinMode( CLOCK_PIN, OUTPUT );
  digitalWrite( CLOCK_PIN, 0 );
  pinMode( DATA_PIN, OUTPUT );
  digitalWrite( DATA_PIN, 0 );
  pinMode( ENABLE_PIN, OUTPUT );
  digitalWrite( ENABLE_PIN, 0 );
  clear( 0 );
  startRenderThread();
}

void Fri3dMatrix::setPixel( int x, int y, int value ) {
  if( ( x >= 0 ) && ( x < 14 ) && ( y >= 0 ) && ( y < 5 ) )
    buffer[ y ][ x ] = value;
}

int Fri3dMatrix::getPixel( int x, int y ) const {
  return buffer[ y ][ x ];
}

void Fri3dMatrix::clear( int value ) {
  for( int y = 0; y < 5; y++ )
    for( int x = 0; x < 14; x++ )
      setPixel( x, y, value );
}

void Fri3dMatrix::drawCharacter(int x_offset, char c, int value) {
  for( int x = 0; x < 3; x++ )
  {
    uint8_t row = font[ ( c - 32 ) * 3 + x ];
    for( int y = 0; y < 5; y++ ) {
      int color = ( row & ( 1 << y ) ) >> y;
      if( color )
        setPixel( x + x_offset, y, value );
    }
  }
}

void Fri3dMatrix::drawString(int x_offset, String s, int value) {
  for( int i = 0; i < s.length(); i++ ) {
    drawCharacter( x_offset + i * 4, s[ i ], value );
  }
}

void Fri3dMatrix::showbitmap_progmem(const PROGMEM uint16_t *bitmap )
{
  for (int row = 0; row < 5; ++row)
  {
    uint16_t linebits  = pgm_read_word_near(&(bitmap[row]));

    for (int count = 0; count < 14; ++count)
    {
      int bit = (linebits & (0b1 << (13 - count))) >> (13 - count);
      buffer[row][count]=bit;
    }
  }
}

void Fri3dMatrix::showbitmap(const uint16_t *bitmap )
{
  for (int row = 0; row < 5; ++row)
  {
    uint16_t linebits = bitmap[row];
    for (int count = 0; count < 14; ++count)
    {
      int bit = (linebits & (0b1 << (13 - count))) >> (13 - count);
      buffer[row][count]=bit;
    }
  }
}

void Fri3dMatrix::render( int delay ) const {
  for( int row = 0; row < 5; row++ ) {

    // send right eye
    for( int i = 0; i < 7; i++ ) {
      shiftIntoRegister( 1 - buffer[ row ][ 13 - i ] );
    }
    for( int i = 0; i < 5; i++ ) {
      if( row == i )
        shiftIntoRegister( 1 );
      else
        shiftIntoRegister( 0 );
    }

    // send left eye
    for( int i = 0; i < 7; i++ ) {
      shiftIntoRegister( 1 - buffer[ row ][ 6 - i ] );
    }
    for( int i = 0; i < 5; i++ ) {
      if( row == i )
        shiftIntoRegister( 1 );
      else
        shiftIntoRegister( 0 );
    }

    digitalWrite( LATCH_PIN, 0 );
    digitalWrite( LATCH_PIN, 1 );

    vTaskDelay( delay );
  }
}

void renderThread( void * parameter )
{
  Fri3dMatrix* matrix = (Fri3dMatrix*)parameter;
  for (;;) {
    matrix->render( 1 );
  }
}

TaskHandle_t renderTask;
void Fri3dMatrix::startRenderThread() {
  xTaskCreatePinnedToCore(
    renderThread,             /* Task function. */
    "renderThread",           /* name of task. */
    1000,                     /* Stack size of task */
    this,                     /* parameter of the task */
    1,                        /* priority of the task */
    &(renderTask),              /* Task handle to keep track of created task */
    1);                       /* Core */
}

void Fri3dMatrix::stopRenderThread() {
  vTaskDelete(renderTask);
}

void Fri3dMatrix::shiftIntoRegister( int b ) const {
  digitalWrite( DATA_PIN, b );
  digitalWrite( CLOCK_PIN, 1 );
  digitalWrite( CLOCK_PIN, 0 );
}
