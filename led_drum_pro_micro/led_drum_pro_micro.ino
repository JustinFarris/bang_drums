const int LT1 = 5; //red
const int LT2 = 6; //green
const int LT3 = 7; //blue
const int LT4 = 8; //white
const int LT5R = 3; 
const int LT5G = 2; 
const int LT5B = 10; 
const int TR1 = 21;
const int TR2 = 20;
const int TR3 = 19;
const int TR4 = 18;
const int TR5 = 9;

const int hit = 150;

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
