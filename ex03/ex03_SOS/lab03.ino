const int ledPin = 2;  
const int freq = 5000;
const int resolution = 8;

void setup() {
  ledcAttach(ledPin, freq, resolution);
}

void loop() {
  // 慢慢变亮
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    ledcWrite(ledPin, dutyCycle);   
    delay(10);
  }
  // 慢慢变暗
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    ledcWrite(ledPin, dutyCycle);   
    delay(10);
  }
}