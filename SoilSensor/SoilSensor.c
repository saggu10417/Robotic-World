int sensorPin1 = A0;
int sensorPin2 = A1;
int sensorValue1;
int sensorValue2;
int limit1 = 300;
int limit2 = 300;

void setup() {
Serial.begin(9600);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
}

void loop() {

sensorValue1 = analogRead(sensorPin1);
sensorValue2 = analogRead(sensorPin2);
Serial.println("Analog Value1 : ");
Serial.println("Analog Value2 : ");
Serial.println(sensorValue1);
Serial.println(sensorValue2);

if (sensorValue1<limit1) {
digitalWrite(12, HIGH);
}
else {
digitalWrite(12, LOW);

}
if (sensorValue2<limit2) {
digitalWrite(13, HIGH);
}
else {
digitalWrite(13, LOW);
}

delay(1000);
}
