int a, b, c, d, val, tmp, i;
void setup()
{
  pinMode(5, INPUT);
  pinMode(4, INPUT);
  pinMode(3, INPUT);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  Serial.println("send");
}

void loop() {


  a = digitalRead(2);
  b = digitalRead(3);
  c = digitalRead(4);
  d = digitalRead(5);

  val = a * 1 + b * 2 + c * 4 + d * 8;
  if (val != tmp)
  {
    Serial.println(val);
    switch (val)
    {
      case 1:
        digitalWrite(13, HIGH);
        Serial.println("CFL ON");
        break;
      case 3:
        digitalWrite(13, LOW);
        Serial.println("CFL OFF");
        break;
      case 8:
        for (i = 0; i < 8; i++)
        { 
          digitalWrite(7, HIGH);
          digitalWrite(8, LOW);
          delay(160);
          digitalWrite(7, HIGH);
          digitalWrite(8, HIGH);
          delay(450);
        }
        Serial.println("Motor work Finished");
        break;

      case 4:
        digitalWrite(10, HIGH);
        Serial.println("Filter ON");
        break;
      case 6:
        digitalWrite(10, LOW);
        Serial.println("Filter OFF");
        break;
    }

    tmp = val;
  }
}

