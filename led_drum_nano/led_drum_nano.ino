// triggers need analog pins (8 per nano, A0-A7)
const int TR1 = 23;
const int TR2 = 24;
const int TR3 = 25;
const int TR4 = 26;
const int TR5 = 27;
const int TR6 = 28;
const int TR7 = 19;
const int TR8 = 22;

// 6 digital single-color outputs (nano: pins 0-5)
const int LT1 = 0; //red
const int LT2 = 1; //green
const int LT3 = 2; //blue
const int LT4 = 3; //white
const int LT5 = 4; //white
const int LT6 = 5; //white

// 2 digital dynamic-color outputs, 3 pins each (nano: pins 6-11)
const int LT7R = 6; 
const int LT7G = 7; 
const int LT7B = 8; 
const int LT8R = 9; 
const int LT8G = 10; 
const int LT8B = 11; 

// fire outputs
// do these need to be different from color outputs?
// or just have the "receiver" unit read all possible color pins and fire on any of them?

const int hit = 100;

void setup()
{
  pinMode(LT1, OUTPUT);
  pinMode(LT2, OUTPUT);
  pinMode(LT3, OUTPUT);
  pinMode(LT4, OUTPUT);
  pinMode(LT5R, OUTPUT);
  pinMode(LT5G, OUTPUT);
  pinMode(LT5B, OUTPUT);
  Serial.begin(9600);       // use the serial port
}

void loop()
{
// LOOP THIS WITH A FOREACH?
//
  int TR1VAL = analogRead(TR1);
  if (TR1VAL>hit)
  {
    digitalWrite(LT1, HIGH);
     Serial.println("LT1 on");
  }
  else 
  {
    digitalWrite(LT1, LOW);
  }

//
  int TR2VAL = analogRead(TR2);
  if (TR2VAL>hit)
  {
    digitalWrite(LT2, HIGH);
     Serial.println("LT2 on");
  }
  else 
  {
    digitalWrite(LT2, LOW);
  }
//
  int TR3VAL = analogRead(TR3);
  if (TR3VAL>hit)
  {
    digitalWrite(LT3, HIGH);
     Serial.println("LT3 on");
  }
  else 
  {
    digitalWrite(LT3, LOW);
  }
//
  int TR4VAL = analogRead(TR4);
  if (TR4VAL>hit)
  {
    digitalWrite(LT4, HIGH);
     Serial.println("LT4 on");
  }
  else 
  {
    digitalWrite(LT4, LOW);
  }
//

  int TR5VAL = analogRead(TR5);
//Serial.println(TR5VAL);
  if (TR5VAL>100)
  {
  bool randR = random(0, 2);
  bool randG = random(0, 2);
  bool randB = random(0, 2);
  Serial.print("R=");
  Serial.println(randR);
  Serial.print("G=");
  Serial.println(randG);
  Serial.print("B=");
  Serial.println(randB);
    if (randR == 1){
      digitalWrite(LT5R, HIGH);
    }
      if (randG == 1){
      digitalWrite(LT5G, HIGH);
    }
    if (randB == 1){
      digitalWrite(LT5B, HIGH);
    }
//find a different way to do the white options
    if ((randR == 0) && (randG == 0) && (randB == 0)){
      digitalWrite(LT5R, HIGH);
      digitalWrite(LT5G, HIGH);
      digitalWrite(LT5B, HIGH);      
    }
      Serial.println("LT5 on");
//

  }
  else 
  {
    digitalWrite(LT5R, LOW);
    digitalWrite(LT5G, LOW);
    digitalWrite(LT5B, LOW);
  }
//

// END FOR EACH
  delay(100);
}
