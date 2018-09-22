#include "Arduino.h"

#include "Buzzer.h"

Buzzer::Buzzer(int pin, int channel) {
  this->channel = channel;
  this->pin = pin;
  this->volume = 255;

  ledcSetup( this->channel, 3000, 8 );
  ledcWrite( this->channel, 0 );
  ledcAttachPin(pin, this->channel); 
}

void
Buzzer::tone( int frequency ) {
  ledcWriteTone( this->channel, frequency );
  ledcWrite( this->channel, this->volume );
}

void
Buzzer::setVolume( int volume ) {
  this->volume = volume;
}

void
Buzzer::noTone() {
  ledcWrite( this->channel, 0 );
}

