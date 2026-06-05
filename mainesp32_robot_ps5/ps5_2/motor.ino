void drive_manual(int speed, int strafe, int turn ) {

// Serial.print("Speed: "); Serial.print(speed);
// Serial.print(" | Strafe: "); Serial.print(strafe);
// Serial.print(" | Turn: "); Serial.println(turn);

  int motor1Speed,motor2Speed,motor3Speed,motor4Speed;

    // Calculate motor speeds
  motor1Speed =  (speed + turn + strafe);  // LF
  motor2Speed = (speed -turn - strafe);    // RF
  motor3Speed = (speed -turn + strafe);    // LB
  motor4Speed = (speed +turn - strafe);    // RB

  // Serial.print("M1: "); Serial.print(motor1Speed);
  // Serial.print(" | M2: "); Serial.print(motor2Speed);
  // Serial.print(" | M3: "); Serial.print(motor3Speed);
  // Serial.print(" | M4: "); Serial.println(motor4Speed);

  // if slow_mode

  if (slow_mode == 1) {
    motor1Speed /= 3;
    motor2Speed /= 3;
    motor3Speed /= 3;
    motor4Speed /= 3;
    // Serial.println("slow");
  }

  motor1Speed = adjust_speed(motor1Speed);
  motor2Speed = adjust_speed(motor2Speed);
  motor3Speed = adjust_speed(motor3Speed);
  motor4Speed = adjust_speed(motor4Speed);

  int maxMotorSpeed = max(max(abs(motor1Speed), abs(motor2Speed)), max(abs(motor3Speed), abs(motor4Speed)));
  if (maxMotorSpeed > 128) {
    motor1Speed = (motor1Speed * 128) / maxMotorSpeed;
    motor2Speed = (motor2Speed * 128) / maxMotorSpeed;
    motor3Speed = (motor3Speed * 128) / maxMotorSpeed;
    motor4Speed = (motor4Speed * 128) / maxMotorSpeed;
  }

  // Control motors
  ControlMotor(motor1Speed, motorLF1,motorLF2);
  ControlMotor(motor2Speed, motorRF1,motorRF2);
  ControlMotor(motor3Speed, motorLB1,motorLB2);
  ControlMotor(motor4Speed, motorRB1,motorRB2);

  delay(25);
}

void ControlMotor(int speed, int pinA, int pinB) {
  int pwm = abs(speed);
  pwm = constrain(pwm, 0, 255); // 
  
  if (speed > 0) {
    analogWrite(pinA, 0);     // ⭐ เปลี่ยนเป็น analogWrite
    analogWrite(pinB, pwm);
  } else if (speed < 0) {
    analogWrite(pinA, pwm);
    analogWrite(pinB, 0);
  } else {
    analogWrite(pinA, 0);
    analogWrite(pinB, 0);
  }

  // int frequency = map(abs(speed), 0, 127, 0, 255);
  // if (frequency > 255) {
  //   frequency = 255;
  // }
  // analogWrite(PWM, frequency);

}

int adjust_speed(int speed) {
  if (abs(speed) < 25) return 0;
  return constrain(speed, -255, 255);
}

int limit_power(int value) {

  if (value > 255) return 255;
  else if (value < -255) return -255;
  return constrain(value, -255, 255);

}

void shooter_power(int nue_shootMT,int stop_shoot,int power,int power1 ,int power2) {
//  int power1= 150;  // กำหนดความแรงตามต้องการ
//  int power2= 200;  // กำหนดความแรงตามต้องการ
//  int power=255;
  // Serial.println(nue_shootMT)
  // Serial.println(power);

  if (nue_shootMT == 1) {
    digitalWrite(en_shooter, HIGH);  // ทิศทางหมุนทางที่ 1
    analogWrite(motor_shoot_up, limit_power(power));
    analogWrite(motor_shoot_down, limit_power(power));
  }
  // } else {
  //   digitalWrite(en_shooter, HIGH); // ทิศทางหมุนทางที่ 2
  // }

  if (nue_shootMT == 0) {
     digitalWrite(en_shooter, HIGH);
    analogWrite(motor_shoot_up, limit_power(-power1));
    analogWrite(motor_shoot_down, limit_power(power2));
  
  }
  if (stop_shoot == 1) {
    analogWrite(motor_shoot_up, 0);
    analogWrite(motor_shoot_down, 0);
  }
  //  if (stop_shoot == 1) {
  //   power1=0;
  //   power2=0;
  //   power=0;

  // }

  // จ่าย PWM ให้มอเตอร์ 2 ตัว
  // analogWrite(motor_shoot_up, limit_power(power));
  // analogWrite(motor_shoot_down, limit_power(power2));
 
}





