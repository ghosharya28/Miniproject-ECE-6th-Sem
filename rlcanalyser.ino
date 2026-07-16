/*
  DDS Based RF Component Analyzer
  AD9850 + Arduino UNO

  Outputs:
  Frequency(MHz),ADC_Count
*/

#define W_CLK 8
#define FQ_UD 9
#define DATA 10
#define RESET 11

const unsigned long DDS_CLOCK = 125000000UL;

// Sweep Settings
const float START_FREQ = 1.0;      // MHz
const float STOP_FREQ  = 22.0;     // MHz
const float STEP_FREQ  = 0.1;      // MHz

void pulseHigh(int pin)
{
  digitalWrite(pin, HIGH);
  delayMicroseconds(2);
  digitalWrite(pin, LOW);
}

void sendFrequency(double frequency)
{
  uint32_t tuningWord =
      (frequency * 4294967296.0) / DDS_CLOCK;

  for (int i = 0; i < 32; i++)
  {
    digitalWrite(DATA, tuningWord & 0x01);
    pulseHigh(W_CLK);
    tuningWord >>= 1;
  }

  // Control byte
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(DATA, LOW);
    pulseHigh(W_CLK);
  }

  pulseHigh(FQ_UD);
}

void setup()
{
  pinMode(W_CLK, OUTPUT);
  pinMode(FQ_UD, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(RESET, OUTPUT);

  digitalWrite(W_CLK, LOW);
  digitalWrite(FQ_UD, LOW);

  pulseHigh(RESET);
  pulseHigh(W_CLK);
  pulseHigh(FQ_UD);

  analogReference(DEFAULT);

  Serial.begin(115200);
}

void loop()
{

  for (float f = START_FREQ; f <= STOP_FREQ; f += STEP_FREQ)
  {

    sendFrequency(f * 1000000.0);

    delay(8);          // Allow detector to settle

    long sum = 0;

    // Average several ADC samples
    for (int i = 0; i < 16; i++)
    {
      sum += analogRead(A0);
    }

    int adc = sum / 16;

    Serial.print(f, 2);
    Serial.print(",");
    Serial.println(adc);
  }

  delay(500);

}