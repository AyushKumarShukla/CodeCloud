# define TP 13
# define LED 5
# define THRESH 65
void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  delay(1000);
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int touchVal = touchRead(TP);
  Serial.println(touchVal);
  if(touchVal < THRESH)
  {
    digitalWrite(LED,HIGH);
    Serial.println("LED ON");
  }
  else
  {
    digitalWrite(LED,LOW);
    Serial.println("LED OFF");
  }
}
