#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4
#define IN5 8
#define IN6 9
#define IN7 10
#define IN8 11
#define MAX_SPEED 150//từ 0-255
#define MIN_SPEED 0
#define UPDOWN A0
#define LEFTRIGHT A1
#define SPEED A2
void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  pinMode(UPDOWN, INPUT);
  pinMode(LEFTRIGHT, INPUT);
  Serial.begin(9600);
}
 
void motor_1_Dung() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
void motor_2_Dung() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void motor_3_Dung() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void motor_4_Dung() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
 
void motor_1_Tien(int speed) { //speed: từ 0 - MAX_SPEED
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED - http://arduino.vn/reference/constrain
  digitalWrite(IN1, HIGH);// chân này không có PWM
  analogWrite(IN2, 255-speed);
}
 
void motor_1_Lui(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED - http://arduino.vn/reference/constrain
  digitalWrite(IN1, LOW);// chân này không có PWM
  analogWrite(IN2, speed);
}
 
void motor_2_Tien(int speed) { //speed: từ 0 - MAX_SPEED
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED - http://arduino.vn/reference/constrain
  analogWrite(IN3, 255-speed);
  digitalWrite(IN4, HIGH);// chân này không có PWM
}
 
void motor_2_Lui(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED - http://arduino.vn/reference/constrain
  analogWrite(IN4, 255-speed);
  digitalWrite(IN3, HIGH);// chân này không có PWM
}

void motor_3_Tien(int speed) { //speed: từ 0 - MAX_SPEED
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED - http://arduino.vn/reference/constrain
  digitalWrite(IN1, HIGH);// chân này không có PWM
  analogWrite(IN2, 255-speed);
}
 
void motor_3_Lui(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED - http://arduino.vn/reference/constrain
  digitalWrite(IN1, LOW);// chân này không có PWM
  analogWrite(IN2, speed);
}
 
void motor_4_Tien(int speed) { //speed: từ 0 - MAX_SPEED
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED - http://arduino.vn/reference/constrain
  analogWrite(IN3, 255-speed);
  digitalWrite(IN4, HIGH);// chân này không có PWM
}
 
void motor_4_Lui(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED - http://arduino.vn/reference/constrain
  analogWrite(IN4, 255-speed);
  digitalWrite(IN3, HIGH);// chân này không có PWM
}
 
void loop()
{
  int input1 = pulseIn(UPDOWN, HIGH);
  int input2 = pulseIn(LEFTRIGHT, HIGH);
  int input3 = pulseIn(SPEED, HIGH);
  int dir = map(input1,1080,1890,0,100);
  int dir2 = map(input2,1085,1890,0,100);
  int spd = map(input3,1075,1895,0,255);
  Serial.println(dir2);

  if(dir<45){
    motor_1_Tien(spd); // motor 1 tiến
    motor_2_Tien(spd); //motor 2 lùi
    motor_3_Tien(spd);
    motor_4_Tien(spd);
  }else if(dir>55){
    motor_1_Lui(spd); // motor 1 tiến
    motor_2_Lui(spd); //motor 2 lùi
    motor_3_Lui(spd);
    motor_4_Lui(spd);
  }else{
    motor_1_Dung();
    motor_2_Dung();
    motor_3_Dung();
    motor_4_Dung();
  }
  if(dir2>70){
    motor_1_Tien(0); // motor 1 tiến
    motor_2_Tien(spd-150); //motor 2 lùi
    motor_3_Tien(0);
    motor_4_Tien(spd-150);
  }else if(dir2<20){
    motor_1_Tien(spd-150); // motor 1 tiến
    motor_2_Tien(0); //motor 2 lùi
    motor_3_Tien(spd-150);
    motor_3_Tien(0);
  }
}
