#include "esphome.h"
using namespace esphome;
#define PIN_1 2
#define PIN_2 0
#define PIN_3 12
#define PIN_4 13

class MyCustomFanoutput : public Component, public FloatOutput {
 public:
  void setup() override {
    // This will be called by App.setup()
    pinMode(PIN_1, OUTPUT);
    pinMode(PIN_2, OUTPUT);
    pinMode(PIN_3, OUTPUT);
	pinMode(PIN_4, OUTPUT);
  }

  void write_state(float state) override {
     if (state == 0.00) {
       digitalWrite(PIN_1, HIGH);
       digitalWrite(PIN_2, LOW);
       digitalWrite(PIN_3, LOW);
       digitalWrite(PIN_4, LOW);
     }
     else if (state == 0.33) {
       digitalWrite(PIN_1, LOW);
       digitalWrite(PIN_2, HIGH);
       digitalWrite(PIN_3, LOW);
       digitalWrite(PIN_4, LOW);
     }
     else if (state == 0.66) {
        digitalWrite(PIN_1, LOW);
        digitalWrite(PIN_2, LOW);
        digitalWrite(PIN_3, HIGH);
        digitalWrite(PIN_4, LOW);
     }
     else if (state == 1) {
        digitalWrite(PIN_1, LOW);
        digitalWrite(PIN_2, LOW);
        digitalWrite(PIN_3, LOW);
        digitalWrite(PIN_4, HIGH);
     }
  }
};