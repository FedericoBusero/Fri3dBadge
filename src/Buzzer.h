// ensure this library description is only included once
#ifndef Buzzer_h
#define Buzzer_h

// library interface description
class Buzzer {
  public:
    Buzzer(int pin, int channel);
    void tone( int frequency );
    void setVolume( int volume );
    void noTone();

  private:
    int channel;
    int pin;
    int volume;
};

#endif
