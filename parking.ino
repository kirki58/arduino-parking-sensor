#define echopin 9
#define trigpin 10
#define buzzer 8
long duration;
int distance;
void setup() {
  pinMode(echopin, INPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop(){
  //reset trigpin
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);

  //launch trigpin for 20 ms
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(20);
  digitalWrite(trigpin,LOW);

  //get the amount of time echopin was on "HIGH" state
  duration = pulseIn(echopin,HIGH);
  // distance = duration x speed of sound / 2
  distance = duration * 0.034 / 2;

  if(distance < 50){
    tone(buzzer,440);
    delay(distance*10);
    noTone(buzzer);
    delay(distance*10);
  }
}
