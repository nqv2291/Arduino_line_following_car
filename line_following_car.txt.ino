//motors (motor1 = left, motor2 = right)
int motor1pin1 = 2;
int motor1pin2 = 3;
int motor2pin3 = 4;
int motor2pin4 = 7;
int en1 = 5;
int en2 = 6;

//sensors
int sensor_VCC = 8;
int sensor1 = 11;
int sensor2 = 12;
int sensor3 = 13;
int temp;

//LED
int led = 9;

void setup() {

  Serial.begin(9600);
  
  pinMode(sensor_VCC, OUTPUT);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin3, OUTPUT);
  pinMode(motor2pin4, OUTPUT);
  pinMode(led, OUTPUT);
  temp = 0;
}

void loop() {
  digitalWrite(sensor_VCC, HIGH);
  analogWrite(en1, 130);
  analogWrite(en2, 130);

  //Control the LEDs
  if (temp >= 500) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
  //Control direction of motors:
  if((digitalRead(sensor1) == LOW && digitalRead(sensor2) == LOW && digitalRead(sensor3) == LOW) || (digitalRead(sensor1) == HIGH && digitalRead(sensor2) == HIGH && digitalRead(sensor3) == HIGH)) {
    //STOP  ==========
    temp += 1;
    delay(1);
    if (temp >= 500) {
      Serial.println("====");
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, LOW);
      digitalWrite(motor2pin3, LOW);
      digitalWrite(motor2pin4, LOW);
    }
    else {
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);
      digitalWrite(motor2pin3, HIGH);
      digitalWrite(motor2pin4, LOW);
    }
  }
  else if((digitalRead(sensor1) == HIGH && digitalRead(sensor3) == HIGH) || digitalRead(sensor2) == HIGH) {
    //GO STRAIGH |||||||||||||
    temp = 0;
    Serial.println("|||||");
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin3, HIGH);
    digitalWrite(motor2pin4, LOW);
  }
  else if(digitalRead(sensor1) == HIGH && digitalRead(sensor3) == LOW) {
    //turn LEFT <<<<<<<<<<<<<
    temp = 0;
    Serial.println("<<<<<");
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin3, HIGH);
    digitalWrite(motor2pin4, LOW);
  }
  else if(digitalRead(sensor1) == LOW && digitalRead(sensor3) == HIGH) {
    //turn RIGHT >>>>>>>>>>>>
    temp = 0;
    Serial.println(">>>>>");
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin3, LOW);
    digitalWrite(motor2pin4, LOW);
  }
}
