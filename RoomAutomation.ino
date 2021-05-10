const int trigPin = 3;
const int echoPin = 4;

int counter=0;
unsigned long duration, distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

int Dist()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.017;
  return distance; 
}

void loop() {
  // put your main code here, to run repeatedly:
 
  int measuredDist = Dist();
  //Serial.println(measuredDist);

  while(measuredDist<=100) {
     counter++;
     //Serial.println("Counter is "+counter);
     break;
  }

 if(counter%2!=0) {
  Serial.println("Lights On!");
  digitalWrite(2,HIGH);
 }
 
 else if(counter%2==0) {
  Serial.println("Lights Off!");
  digitalWrite(2,LOW);
 }
  //Serial.println(duration);
 delay(500);
}
