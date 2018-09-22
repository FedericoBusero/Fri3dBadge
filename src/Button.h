// ensure this library description is only included once
#ifndef Button_h
#define Button_h

#include <Arduino.h>

// library interface description
class Button {
  public:
    Button(int _pin);
    bool getButton();

    // below is all the stuff needed for automated debouncing with callbacks
    void debounceButton( );

  private:
    int pin;
    int state;
    int lastDebounceTime;
    void (*pressedCallbacks)();
    void (*releasedCallbacks)();

  public:
    int getDebouncedState( );
    void setPressedCallback( void (*callback)() );
    void setReleasedCallback( void (*callback)() );
};

// library interface description
class TouchButton {
  public:
    TouchButton(int _pin)
      : pin(_pin) {
      pinMode( _pin, INPUT );
    }

    int getTouchpad( ) {
      return analogRead( pin );
    }

  private:
    int pin;
};


#endif
