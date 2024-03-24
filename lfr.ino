// variable to store sensor value 
int a;
int b;
int c;
int d;
int e;

// Variables for storing IR sensor
int svel;
int svl;
int svc;
int svr;
int sver;
// Pin definition
int svelPin=A1;
int svlPin=A2;
int svcPin=A3;
int svrPin=A4;
int sverPin=A5;
// PWM Values 
int ninety=100;
int ext=80;
int very=70;
int norm=60;
int lil=50;

void setup() {
  Serial.begin(9600);
  pinMode(svelPin, INPUT);
  pinMode(svlPin, INPUT);
  pinMode(svrPin, INPUT);
  pinMode(sverPin, INPUT);
  pinMode(svcPin, INPUT);
  pinMode(12,OUTPUT);
  digitalWrite(12,HIGH);
  pinMode(9,OUTPUT);// enA | For generating PWM for left motor
  pinMode(11,OUTPUT);// left motor 2-
  pinMode(10,OUTPUT);// left motor 1+
  pinMode(3,OUTPUT);// enB | For generating PWM for right motor
  pinMode(5,OUTPUT);// right motor 1+  
  pinMode(4,OUTPUT);// right motor 2- 
}
void forward(){
  for(int i=0;i<120;i++){
    analogWrite(9,i);
    analogWrite(3,i);
    digitalWrite(11,1);
    digitalWrite(10,0);
    digitalWrite(5,1);
    digitalWrite(4,0);
  }
}
void stop(){
  digitalWrite(12,1);
  analogWrite(9,0);
  analogWrite(3,0);
  digitalWrite(11,0);
  digitalWrite(10,0);
  digitalWrite(5,0);
  digitalWrite(4,0);
}
void left(int pwm){
  analogWrite(9, pwm);
  analogWrite(3, pwm);
  digitalWrite(11, 0);
  digitalWrite(10, 1);
  digitalWrite(5, 1);
  digitalWrite(4, 0);
}
void ninetyleft(int pwm){
  analogWrite(9, pwm);
  analogWrite(3, pwm);
  digitalWrite(11, 0);
  digitalWrite(10, 0);
  digitalWrite(5, 1);
  digitalWrite(4, 0);
}
void right(int pwm){
  analogWrite(9, pwm);
  analogWrite(3, pwm);
  digitalWrite(11, 1);
  digitalWrite(10, 0);
  digitalWrite(5, 0);
  digitalWrite(4, 1);
}
void ninetyright(int pwm){
  analogWrite(9, pwm);
  analogWrite(3, pwm);
  digitalWrite(11, 1);
  digitalWrite(10, 0);
  digitalWrite(5, 0);
  digitalWrite(4, 0);
}
void backwards(int pwm){
  analogWrite(9, pwm);
  analogWrite(3, pwm);
  digitalWrite(11,0);
  digitalWrite(10,1);
  digitalWrite(5,0);
  digitalWrite(4,1);
}

void loop() {
  svel=analogRead(svelPin);
  svl=analogRead(svlPin);
  svc=analogRead(svcPin);
  svr=analogRead(svrPin);
  sver=analogRead(sverPin);
  
  if (svel<50){
    a=0;
  }
  else {
    a=1;
  }
  if (svl<50){
    b=0;
  }
  else {
    b=1;
  }
  if (svc<50){
    c=0;
  }
  else {
    c=1;
  }
  if (svr<50){
    d=0;
  }
  else {
    d=1;
  }
  if (sver<50){
    e=0;
  }
  else {
    e=1;
  }

    if(a==0 && b==0 && c==1 && d==0 && e==0){
      forward();
      Serial.print("forward");
      Serial.print("\n");
  }
   else if(a==0 && b==1 && c==0 && d==0 && e==0){
    left(norm);
    Serial.print(" left");
    Serial.print("\n");
  }
  else if(a==1 && b==0 && c==0 && d==0 && e==0){
    left(ext);
    Serial.print(" extreme left");
    Serial.print("\n");
  }
  else if(a==1 && b==1 && c==0 && d==0 && e==0){
    left(very);
    Serial.print(" very left");
    Serial.print("\n");
  }
  else if(a==1 && b==1 && c==1 && d==0 && e==0){
    ninetyleft(ninety);
    Serial.print(" ninety degree left");
    Serial.print("\n");
  }
  else if(a==0 && b==1 && c==1 && d==0 && e==0){
    left(lil);
    Serial.print(" little left");
    Serial.print("\n");
  }
  else if(a==0 && b==0 && c==0 && d==1 && e==0){
    right(norm);
    Serial.print("right");
    Serial.print("\n");
  }
  else if(a==0 && b==0 && c==0 && d==0 && e==1){
    right(ext);
    Serial.print("extreme right");
    Serial.print("\n");
  }
  else if(a==0 && b==0 && c==0 && d==1 && e==1){
    right(very);
    Serial.print("very right");
    Serial.print("\n");
  }
  else if(a==0 && b==0 && c==1 && d==1 && e==1){
    ninetyright(ninety);
    Serial.print("90  degree right");
    Serial.print("\n");
  }
  else if(a==0 && b==0 && c==1 && d==1 && e==0){
    right(lil);
    Serial.print("little right");
    Serial.print("\n");
  }
  else if(a==0 && b==0 && c==0 && d==0 && e==0){
    stop();
    Serial.print("stop");
    Serial.print("\n");
  }

}
