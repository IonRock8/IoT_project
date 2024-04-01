int led = 5;
int digitalPin = 4;
int val = 0;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(digitalPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  /*digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);*/
  val = digitalRead(digitalPin);
  Serial.print("val = ");
  Serial.println(val);
  if (val == 1) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
  
}