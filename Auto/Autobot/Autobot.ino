/*
 * Slave code for auto robot
 * Motor control: L298N module
 * Connections: (Arduino - L298N)
 *    D9 - Motor 1    (Right motor)
 *    D10 - Motor 2   (Left motor)
 *    D4 - IN1
 *    D5 - IN2
 *    D6 - IN3
 *    D7 - IN4
 * A potentiometer is put on pin A0 for pre-battle manual speed adjustment    
 */

int data = '0';
uint8_t value = 0;

int MR = 9;
int ML = 10;

void setup() 
{
  Serial.begin(9600);    // Initiate UART communication with HC-05 (Slave)
  Serial1.begin(9600); // receive data from HC-05
  for (int i = 4; i <= 7; i++)    //set pins D4, D5, D6, and D7 as output
  {
    pinMode(i, OUTPUT);
  }

  for (int i = 4; i <= 7; i++)    //initial output value of each pin is LOW, both motors stop
  {
    digitalWrite(i, LOW); // khong chinh toc do xe ak
  } 
}

void loop() 
{
   if (Serial1.available() > 0){  // do nothing when there is no new data
      data = Serial1.read();  // read incoming data
      Serial.println(data);
      if ('0' == data)  //halt
      {
          for (int i = 4; i <= 7; i++)    //both motors stop
          {
            digitalWrite(i, LOW);
          }
      }
      else if ('1' == data)   // robot adjusts direction (turns right)
      {
          digitalWrite(4, LOW);
          digitalWrite(5, HIGH);
          digitalWrite(6, HIGH);
          digitalWrite(7, LOW);
      }
      else if ('2' == data)   // robot goes straight
      {
          digitalWrite(4, HIGH);
          digitalWrite(5, LOW);
          digitalWrite(6, HIGH);
          digitalWrite(7, LOW);
      }
   }

   setSpeedMotor();   //set motor speed
}

void setSpeedMotor()
{
  value = analogRead(A0);   //manually adjusted motor speed
  analogWrite(MR, value);   //writing motor speed
  analogWrite(ML, value);
}
