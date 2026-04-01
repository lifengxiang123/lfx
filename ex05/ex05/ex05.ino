#define LED1 2
#define LED2 4

const int freq = 5000;
const int ch1 = 0;
const int ch2 = 1;
const int res = 8;

void setup() {
  ledcSetup(ch1, freq, res);
  ledcSetup(ch2, freq, res);
  ledcAttachPin(LED1, ch1);
  ledcAttachPin(LED2, ch2);
}

void loop() {
  for (int i = 0; i <= 255; i++) {
    ledcWrite(ch1, i);
    ledcWrite(ch2, 255 - i);
    delay(6);
  }
  for (int i = 255; i >= 0; i--) {
    ledcWrite(ch1, i);
    ledcWrite(ch2, 255 - i);
    delay(6);
  }
}