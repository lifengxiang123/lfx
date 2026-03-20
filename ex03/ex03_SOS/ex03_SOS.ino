const int ledPin = 2;
unsigned long prevMillis = 0;
int state = 0;
int flashCount = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long now = millis();
  int durOn, durOff;

  if (state < 3) { durOn = 200; durOff = 200; }
  else if (state < 6) { durOn = 600; durOff = 200; }
  else if (state < 9) { durOn = 200; durOff = 200; }
  else { durOn = 0; durOff = 2000; }

  if (now - prevMillis >= (digitalRead(ledPin) ? durOn : durOff)) {
    prevMillis = now;
    int newState = !digitalRead(ledPin);
    digitalWrite(ledPin, newState);

    if (!newState) {
      flashCount++;
      if (flashCount >= 1) {
        flashCount = 0;
        state++;
        if (state >= 12) state = 0;
      }
    }
  }
}