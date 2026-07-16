#include <Wire.h>
#include <U8g2lib.h>

// ================= OLED =================
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0);

// ================= AD9850 PINS =================
#define W_CLK 8
#define FQ_UD 9
#define DATA 10
#define RESET 11

// ================= VARIABLES =================
int reflectionValue = 0;

int minReflection = 1023;
long resonantFreq = 0;

// ================= DDS FUNCTIONS =================
void pulseHigh(int pin) {

  digitalWrite(pin, HIGH);
  digitalWrite(pin, LOW);
}

void sendFrequency(double frequency) {

  uint32_t freqWord = (frequency * 4294967295.0) / 125000000.0;

  for (int i = 0; i < 32; i++) {

    digitalWrite(DATA, freqWord & 0x01);

    pulseHigh(W_CLK);

    freqWord >>= 1;
  }

  // Control byte
  for (int i = 0; i < 8; i++) {

    digitalWrite(DATA, LOW);

    pulseHigh(W_CLK);
  }

  pulseHigh(FQ_UD);
}

// ================= SETUP =================
void setup() {

  // DDS Pins
  pinMode(W_CLK, OUTPUT);
  pinMode(FQ_UD, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(RESET, OUTPUT);

  // Serial
  Serial.begin(115200);

  // DDS Init
  pulseHigh(RESET);
  pulseHigh(W_CLK);
  pulseHigh(FQ_UD);

  // OLED Init
  u8g2.setI2CAddress(0x3C * 2);

  u8g2.begin();

  // Startup Screen
  u8g2.clearBuffer();

  u8g2.setFont(u8g2_font_ncenB08_tr);

  u8g2.drawStr(15, 30, "RF ANALYZER");

  u8g2.sendBuffer();

  delay(2000);
}

// ================= MAIN LOOP =================
void loop() {

  minReflection = 1023;

  // Sweep 1 MHz to 30 MHz
  for (long f = 1000000; f <= 30000000; f += 500000) {

    // Send frequency to AD9850
    sendFrequency(f);

    delay(50);

    // Read detector
    reflectionValue = analogRead(A0);

    // Resonance detection
    if (reflectionValue < minReflection) {

      minReflection = reflectionValue;

      resonantFreq = f;
    }

    // ================= OLED DISPLAY =================
    u8g2.clearBuffer();

    // Title
    u8g2.setFont(u8g2_font_6x10_tf);

    u8g2.drawStr(25, 10, "ANTENNA ANALYZER");

    // Frequency
    u8g2.setCursor(0, 25);
    u8g2.print("Freq:");

    u8g2.print(f / 1000000.0, 1);

    u8g2.print(" MHz");

    // Reflection
    u8g2.setCursor(0, 40);
    u8g2.print("Reflection:");

    u8g2.print(reflectionValue);

    // Resonance
    u8g2.setCursor(0, 55);
    u8g2.print("Res:");

    u8g2.print(resonantFreq / 1000000.0, 1);

    u8g2.print(" MHz");

    // Push to OLED
    u8g2.sendBuffer();

    // ================= SERIAL OUTPUT =================
    Serial.print(f);

    Serial.print(",");

    Serial.println(reflectionValue);
  }

  delay(2000);
}