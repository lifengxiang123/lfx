#define LED_PIN 2

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("ESP32 实验1 环境搭建成功");
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED 亮");
  delay(1000);
  
  digitalWrite(LED_PIN, LOW);
  Serial.println("LED 灭");
  delay(1000);
}