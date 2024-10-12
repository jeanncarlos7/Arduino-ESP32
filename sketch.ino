#include <DHT.h>

#define DHTPIN 15         
#define DHTTYPE DHT22     
DHT dht(DHTPIN, DHTTYPE);

#define TRIG_PIN 5        
#define ECHO_PIN 18       

#define LED_BLUE 4        
#define LED_YELLOW 16     
#define LED_RED 17        
#define LED_CYAN 19       
#define LED_ORANGE 21     

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_CYAN, OUTPUT);
  pinMode(LED_ORANGE, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  readAndPrintTemperatureHumidity();

  readAndPrintDistance();
  
  delay(2000);  
}

void readAndPrintTemperatureHumidity() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C, Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  controlTemperatureLEDs(temperature);
}

void readAndPrintDistance() {
  float distance = readDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" meters");

  controlDistanceLEDs(distance);
}

float readDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  float duration = pulseIn(ECHO_PIN, HIGH);
  float distance = (duration / 2) * 0.0343; 
  return distance;
}

void controlTemperatureLEDs(float temperature) {
  if (temperature < 10) {
    digitalWrite(LED_BLUE, HIGH);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
  } else if (temperature >= 11 && temperature <= 26) {
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_RED, LOW);
  } else if (temperature > 27) {
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, HIGH);
  }
}

void controlDistanceLEDs(float distance) {
  if (distance > 4.0) {
    digitalWrite(LED_CYAN, LOW);
    digitalWrite(LED_ORANGE, LOW);
  } else if (distance >= 1.0 && distance <= 3.9) {
    digitalWrite(LED_CYAN, HIGH);
    digitalWrite(LED_ORANGE, LOW);
  } else if (distance < 1.0) {
    digitalWrite(LED_CYAN, HIGH);
    digitalWrite(LED_ORANGE, HIGH);
    Serial.println("Cuidado muito perto do obstáculo");
  }
}
