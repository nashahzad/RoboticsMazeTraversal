const int Input1 = 12;
const int Input2 = 11;
const int Input3 = 13;
const int Input4 = 10;
const int trig1 = 42;
const int echo1 = 43;
const int trig2 = 51;
const int echo2 = 49;
const int trig3 = 23;
const int echo3 = 22;

const int sp = 255;
const int spL = 255;

void setup() {
  Serial.begin(9600);
}

void loop()  {
pinMode(Input1, OUTPUT);
pinMode(Input2, OUTPUT);
pinMode(Input3, OUTPUT);
pinMode(Input4, OUTPUT);
pinMode(trig1, OUTPUT);
pinMode(echo1, INPUT);
pinMode(trig2, OUTPUT);
pinMode(echo2, INPUT);
pinMode(trig3, OUTPUT);
pinMode(echo3, INPUT);  
      
long duration1, inches1, cm1, duration2, inches2, cm2, duration3, inches3, cm3;
  
  //Activating trigger, sending initial pulse

  /////////////////////////////////////////////
  //1 IS THE RIGHT
  //2 IS THE MIDDLE
  //3 IS THE LEFT
  ////////////////////////////////////////////
  
  digitalWrite(trig1, LOW);
  delayMicroseconds(10);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);

  //Activating echo, awaiting response
  pinMode(echo1, INPUT);
  duration1 = pulseIn(echo1, HIGH);
 
  //Convert from time to distance
  inches1 = microsecondsToInches(duration1);
  cm1 = microsecondsToCentimeters(duration1);

  Serial.print(inches1);
  Serial.print("in1, ");
  Serial.print(cm1);
  Serial.print("cm1, ");
  
    //Activating trigger, sending initial pulse
  digitalWrite(trig2, LOW);
  delayMicroseconds(10);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);

  //Activating echo, awaiting response
  pinMode(echo2, INPUT);
  duration2 = pulseIn(echo2, HIGH);
 
  //Convert from time to distance
  inches2 = microsecondsToInches(duration2);
  cm2 = microsecondsToCentimeters(duration2);

  Serial.print(inches2);
  Serial.print("in2, ");
  Serial.print(cm2);
  Serial.print("cm2, ");
  
//      //Activating trigger, sending initial pulse
//  digitalWrite(trig3, LOW);
//  delayMicroseconds(10);
//  digitalWrite(trig3, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trig3, LOW);
//
//  //Activating echo, awaiting response
//  pinMode(echo3, INPUT);
//  duration3 = pulseIn(echo3, HIGH);
// 
//  //Convert from time to distance
//  inches3 = microsecondsToInches(duration3);
//  cm3 = microsecondsToCentimeters(duration3);
//
//  Serial.print(inches3);
//  Serial.print("in3, ");
//  Serial.print(cm3);
//  Serial.print("cm3");
  Serial.println();
  
  delay(15);
  if(cm2 <= 5 && cm2 > 0){
    reverse(375);
  }

  
  //IF SPACE OPEN ON RIGHT TURN RIGHT OTHERWISE CONTINUE FORWARD
  //IF LESS THAN 20 CENTIMETERS IN FRONT SENSOR
  //TURN LEFT 90 DEGREES
  if(cm1 > 42 || cm1 == 0){
    forward();
    delay(300);
    stopMotors();
    turnRight();
    stopMotors();
  }
  else if (cm2 < 20 && cm2 > 0) 
    {
      stopMotors();
      turnLeft();
      stopMotors();
    }
   else
    {
      forward();
    }
//    delay(250); 
    //STABILIZATION THINGY STUFF I DON'T EVEN KNOW ANYMORE
//  FUDGE MUFFINS MANG
//if(cm1 < 5 && cm2 < 5){
//  stopMotors();
//  turnLeft(165);
//  stopMotors();
//  forward();
//} else if(cm3 < 5 && cm2 < 5){
//  stopMotors();
//  turnRight(190);
//  stopMotors();
//  forward();
//}
//
//if(cm1 - cm3 > 0){
////  stopMotors();
//  turnRight(120);
////  stopMotors();
////  forward();
//} else{
////  stopMotors();
//  turnLeft(120);
////  stopMotors();
////  forward();
//}
}


void forward(){
  analogWrite(Input1, 0);
  analogWrite(Input2, sp);
  analogWrite(Input3, 0);
  analogWrite(Input4, 230);
}

void turnRight(){
//  delay(400);
  analogWrite(Input1, spL);
  analogWrite(Input2, 0);
  analogWrite(Input3, 0);
  analogWrite(Input4, sp);
  delay(360);
  forward();
  delay(800);
}

void turnRight(int num){
  delay(0);
  analogWrite(Input1, spL);
  analogWrite(Input2, 0);
  analogWrite(Input3, 0);
  analogWrite(Input4, sp);
  delay(num);
  forward();
  delay(500);
}

void turnLeft(){
  analogWrite(Input1, 0);
  analogWrite(Input2, spL);
  analogWrite(Input3, sp);
  analogWrite(Input4, 0);
  delay(360);
//  forward();
}

void turnLeft(int num){
  analogWrite(Input1, 0);
  analogWrite(Input2, spL);
  analogWrite(Input3, sp);
  analogWrite(Input4, 0);
  delay(num);
//  forward();
}

void stopMotors(){
  analogWrite(Input1, spL);
  analogWrite(Input2, 0);
  analogWrite(Input3, sp);
  analogWrite(Input4, 0);
  delay(30);
  analogWrite(Input1, 0);
  analogWrite(Input2, 0);
  analogWrite(Input3, 0);
  analogWrite(Input4, 0);
  
  delay(1000);
}

void reverse(int num){
  stopMotors();
  analogWrite(Input1, 200);
  analogWrite(Input2, 0);
  analogWrite(Input3, 200);
  analogWrite(Input4, 0);
  delay(num);
//  sstopMotors();
//  forward();
}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
