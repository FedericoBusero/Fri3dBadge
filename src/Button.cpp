#include "Button.h"

#include <Arduino.h>

Button::Button(int _pin) {
  pin = _pin;
  state = 0;
  lastDebounceTime = 0;
  pressedCallbacks = NULL;
  releasedCallbacks = NULL;

  pinMode( _pin, INPUT_PULLUP );
}



bool
Button::getButton( ) {
  return 1 - digitalRead( pin );
}

void
Button::debounceButton( ) {
  if ( (millis() - lastDebounceTime) > 50) {
    int buttonState = getButton( );
    // the button is on a pull-up pin, so stuff here may seem upside down
    if ( (buttonState == 0) && (state != 0 ) ) {
      state = 0;
      lastDebounceTime = millis();
      if ( releasedCallbacks )
        (*(releasedCallbacks))();
    }
    else if ( (buttonState == 1) && (state != 1 ) ) {
      state = 1;
      lastDebounceTime = millis();
      if ( pressedCallbacks )
        (*(pressedCallbacks))();
    }
  }
}

int
Button::getDebouncedState( ) {
  return state;
}


void
Button::setPressedCallback( void (*callback)() ) {
  pressedCallbacks = callback;
}

void
Button::setReleasedCallback( void (*callback)() ) {
  releasedCallbacks = callback;
}
