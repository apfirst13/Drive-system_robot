void drive_manual(int speed, int strafe, int turn ) {

  //  Serial.println(strafe);

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

int limit_power(int power){
  if (power>255){return 255;}
  else if (power<-255){return -255;}
  return power;
}

// void shooter_power(int speed){
//   if (speed > 1){
//     digitalWrite(en_shooter,HIGH);
//   }
//   else{digitalWrite(en_shooter,LOW);}
//   analogWrite(motor_shoot_up,limit_power(speed));
//   analogWrite(motor_shoot_down,limit_power(speed));
// }

// void pnuematic(){

//   digitalWrite(arm,pneu_arm_dribble);
//   digitalWrite(go_shoot,pneu_shoot);

// }

void shooter_power(int nue_shootMT){
  // Serial.println(nue_shootMT,speed);
    Serial.println(nue_shootMT);
  if (nue_shootMT==1) {
    digitalWrite(en_shooter,0);
  }                                                   
  else{digitalWrite(en_shooter,1);}
  // analogWrite(motor_shoot_up,limit_power(speed));
  // analogWrite(motor_shoot_down,limit_power(speed));
}



