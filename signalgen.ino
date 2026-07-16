#include <math.h>

#define W_CLK 8
#define FQ_UD 9
#define DATA 10
#define RESET 11

#define pulseHigh(pin) {digitalWrite(pin, HIGH); digitalWrite(pin, LOW);}

const double referenceClock = 125000000.0;

void sendFrequency(double frequency) {
  uint32_t freqWord = (frequency * pow(2, 32)) / referenceClock;

  for (int b = 0; b < 4; b++) {
    shiftOut(DATA, W_CLK, LSBFIRST, freqWord >> (8 * b));
  }

  shiftOut(DATA, W_CLK, LSBFIRST, 0x00);

  pulseHigh(FQ_UD);
}

void resetDDS() {
  pulseHigh(RESET);
  pulseHigh(W_CLK);
  pulseHigh(FQ_UD);
}

void setup() {
  pinMode(W_CLK, OUTPUT);
  pinMode(FQ_UD, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(RESET, OUTPUT);

  Serial.begin(115200);

  resetDDS();

  // Set AD9850 output frequency
  sendFrequency(500);   // 500 Hz --> change the frequency here 
}

void loop() {
  int value = analogRead(A0);

  Serial.println(value);

  delayMicroseconds(500);
}