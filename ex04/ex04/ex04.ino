#define TOUCH_PIN 4
#define LED_PIN 2

const int freq = 5000;
const int ch = 0;
const int res = 8;

int mode = 1;
long lastTouch = 0;
bool lastT = false;

void setup() {
  ledcSetup(ch, freq, res);
  ledcAttachPin(LED_PIN, ch);
}

void loop() {
  int val = touchRead(TOUCH_PIN);
  bool t = (val < 30);

  if (t && !lastT && millis() - lastTouch > 200) {
    mode++;
    if (mode > 3) mode = 1;
    lastTouch = millis();
  }
  lastT = t;

  int d = mode == 1 ? 12 : mode == 2 ? 6 : 2;

  for (int i = 0; i <= 255; i++) {
    ledcWrite(ch, i);
    delay(d);
  }
  for (int i = 255; i >= 0; i--) {
    ledcWrite(ch, i);
    delay(d);
  }
}