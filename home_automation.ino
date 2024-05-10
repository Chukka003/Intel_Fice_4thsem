#include <dht.h>

dht DHT;

char val;
char val2;

void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(4, INPUT);
  pinMode(10, OUTPUT);

  Serial.begin(9600);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(10, LOW);
}

void loop() {

    if (val == '1') {
    digitalWrite(7, LOW);
    Serial.println("Light On");
  } else if (val == '2') {
    digitalWrite(7, HIGH);
    Serial.println("Light Off");
  } else if (val == '3') {
    digitalWrite(6, LOW);
    Serial.println("Fan On");
  } else if (val == '4') {
    digitalWrite(6, HIGH);
    Serial.println("Fan Off");
  }

  int readData = DHT.read11(8);

  float t = DHT.temperature;
  float h = DHT.humidity;

  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print("°C | ");
  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.println("% ");
  Serial.println("");

  int flameValue = digitalRead(4);
  if (flameValue == LOW) {
    Serial.println("Flame detected!");
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(10, LOW);
  }

   if (Serial.available()) {
    val = Serial.read();
    val2 = Serial.read();
  }

  delay(1500); 

}

