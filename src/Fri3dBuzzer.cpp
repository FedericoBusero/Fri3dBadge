#include "Fri3dBuzzer.h"
#include "Arduino.h"

Fri3dBuzzer::Fri3dBuzzer() {
  pinMode(BUZZER_PIN, OUTPUT);
  ledcSetup( 0, 3000, 8 );
  setVolume( 255 );
  ledcAttachPin(BUZZER_PIN, 0);
}

void 
Fri3dBuzzer::setFrequency( int frequency ) {
  ledcWriteTone( 0, frequency );
}

void 
Fri3dBuzzer::setVolume( int volume ) {
  ledcWrite( 0, volume );
}
