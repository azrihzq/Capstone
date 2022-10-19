#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial nodemcu(3, 2);
Servo myservo;

int WaterSensor1 = A0;
int WaterSensor2 = A1;
int trigger = 4;
int servoMotor = 5;
int greenLED1 = 11;
int yellowLED1 = 6;
int redLED1 = 7;
int greenLED2 = 8;
int yellowLED2 = 9;
int redLED2 = 10;
int redLED3 = 12;
const int buzzer2 = 13;
int val1 = 0;
int val2 = 0;
//int S1 ;
//int S2 ;

void setup()
{
  pinMode (WaterSensor1, INPUT);
  pinMode (WaterSensor2, INPUT);
  pinMode (trigger, OUTPUT);
  pinMode (greenLED1, OUTPUT);
  pinMode (yellowLED1, OUTPUT);
  pinMode (redLED1, OUTPUT);
  pinMode (greenLED2, OUTPUT);
  pinMode (yellowLED2, OUTPUT);
  pinMode (redLED2, OUTPUT);
  pinMode (redLED3, OUTPUT);
  pinMode (buzzer2, OUTPUT);
  myservo.attach(servoMotor);
  Serial.begin (9600);
  nodemcu.begin(4800);
}

void loop()
{
  val1 = analogRead(WaterSensor1);
  val2 = analogRead(WaterSensor2);

  /////////////////////WATER SENSOR 1/////////////////////

  if (val1 > 550)
  {
    Serial.print("Sensor 1:");
    Serial.print("\t");
    Serial.print(val1);
    Serial.print("\t");

    myservo.write (180);
    digitalWrite (redLED3, HIGH);
    digitalWrite (buzzer2, HIGH);
    digitalWrite (trigger, HIGH);

    digitalWrite (greenLED1, LOW);
    digitalWrite (yellowLED1, LOW);
    digitalWrite (redLED1, HIGH);

    //    S1 = 2;
    //    Serial.print("S1: ");
    //    Serial.print("\t");
    //    Serial.print (S1);
    //    Serial.print("\t");
  }
  else if ((val1 > 100) && (val1 <= 550))
  {
    Serial.print("Sensor 1:");
    Serial.print("\t");
    Serial.print(val1);
    Serial.print("\t");

    digitalWrite (greenLED1, LOW);
    digitalWrite (yellowLED1, HIGH);
    digitalWrite (redLED1, LOW);

    //    S1 = 0;
    //    Serial.print("S1: ");
    //    Serial.print("\t");
    //    Serial.print (S1);
    //    Serial.print("\t");
  }
  else
  {
    Serial.print("Sensor 1:");
    Serial.print("\t");
    Serial.print(val1);
    Serial.print("\t");

    myservo.write (0);
    digitalWrite (redLED3, LOW);
    digitalWrite (buzzer2, LOW);
    digitalWrite (trigger, LOW);

    digitalWrite (greenLED1, HIGH);
    digitalWrite (yellowLED1, LOW);
    digitalWrite (redLED1, LOW);

    //    S1 = 1;
    //    Serial.print("S1: ");
    //    Serial.print("\t");
    //    Serial.print (S1);
    //    Serial.print("\t");

  }

  /////////////////////WATER SENSOR 2/////////////////////

  if (val2 > 550)
  {
    Serial.print("Sensor 2:");
    Serial.print("\t");
    Serial.print(val2);
    Serial.println("\t");

    myservo.write (180);
    digitalWrite (redLED3, HIGH);
    digitalWrite (buzzer2, HIGH);
    digitalWrite (trigger, HIGH);

    digitalWrite (greenLED2, LOW);
    digitalWrite (yellowLED2, LOW);
    digitalWrite (redLED2, HIGH);

    //    S2 = 2;
    //    Serial.print("S2: ");
    //    Serial.print("\t");
    //    Serial.print (S2);
    //    Serial.println("\t");
  }
  else if ((val2 > 100) && (val2 <= 550))
  {
    Serial.print("Sensor 2:");
    Serial.print("\t");
    Serial.print(val2);
    Serial.println("\t");

    digitalWrite (greenLED2, LOW);
    digitalWrite (yellowLED2, HIGH);
    digitalWrite (redLED2, LOW);

    //    S2 = 0;
    //    Serial.print("S2: ");
    //    Serial.print("\t");
    //    Serial.print (S2);
    //    Serial.println("\t");
  }
  else
  {
    Serial.print("Sensor 2:");
    Serial.print("\t");
    Serial.print(val2);
    Serial.println("\t");

    myservo.write (0);
    digitalWrite (redLED3, LOW);
    digitalWrite (buzzer2, LOW);
    digitalWrite (trigger, LOW);

    digitalWrite (greenLED2, HIGH);
    digitalWrite (yellowLED2, LOW);
    digitalWrite (redLED2, LOW);

    //    S2 = 1;
    //    Serial.print("S2: ");
    //    Serial.print("\t");
    //    Serial.print (S2);
    //    Serial.println("\t");
  }

  /////////////////////ALARM SISTEM/////////////////////

  //  if (S1 ==  2)
  //  {
  //    if (S2 == 2)
  //    {
  //      myservo.write (180);
  //      digitalWrite (redLED3, HIGH);
  //      digitalWrite (buzzer2, HIGH);
  //      digitalWrite (trigger, HIGH);
  //    }
  //  }
  //  else if (S1 = 1)
  //  {
  //    if (S2 = 1)
  //    {
  //      myservo.write (0);
  //      digitalWrite (redLED3, LOW);
  //      digitalWrite (buzzer2, LOW);
  //      digitalWrite (trigger, LOW);
  //    }
  //  }
}
