void set_pin(){

  pinMode(motorLF1,OUTPUT);
  pinMode(motorLF2,OUTPUT);
  pinMode(motorRF1,OUTPUT);
  pinMode(motorRF2,OUTPUT);
  pinMode(motorLB1,OUTPUT);
  pinMode(motorLB2,OUTPUT);
  pinMode(motorRB1,OUTPUT);
  pinMode(motorRB2,OUTPUT);

  pinMode(motor_shoot_up, OUTPUT);
  pinMode(motor_shoot_down, OUTPUT);


}

void onEvent() {
  if(PS4.event.button_down.square) {
    toggle[0] = !toggle[0];
    Serial.print("Square: ");
    Serial.println(toggle[0]);
  }
  if(PS4.event.button_down.triangle) {
    toggle[1] = !toggle[1];
    Serial.print("Triangle: ");
    Serial.println(toggle[1]);
  }
  if(PS4.event.button_down.circle) {
    toggle[2] = !toggle[2];
    Serial.print("Circle: ");
    Serial.println(toggle[2]);
  }
  if(PS4.event.button_down.cross){
    toggle[3] = !toggle[3];
    Serial.print("Cross: ");
    Serial.println(toggle[3]);
  }
  if(PS4.event.button_down.l1) {
    toggle[4] = !toggle[4];
    Serial.print("L1: ");
    Serial.println(toggle[4]);
  }
  if(PS4.event.button_down.l2) {
    toggle[5] = !toggle[5];
    Serial.print("L1: ");
    Serial.println(toggle[4]);
  }
  if(PS4.event.button_down.r1) {
    toggle[6] = !toggle[6];
    Serial.print("R1: ");
    Serial.println(toggle[6]);
  }
   if(PS4.event.button_down.r2) {
    toggle[7] = !toggle[7];
    Serial.print("R2: ");
    Serial.println(toggle[7]);
  }
  if(PS4.event.button_down.share) {
    toggle[8] = !toggle[8];
    Serial.print("Share: ");
    Serial.println(toggle[8]);
  }
  if(PS4.event.button_down.ps) {
    toggle[10] = !toggle[10];
    Serial.print("PS: ");
    Serial.println(toggle[10]);
  }
  if(PS4.event.button_down.touchpad) {
    toggle[11] = !toggle[11];
    Serial.print("Touchpad: ");
    Serial.println(toggle[11]);
  }
  if(PS4.event.button_down.up) {
    toggle[12] = !toggle[12];
    Serial.print("Up: ");
    Serial.println(toggle[12]);
  }
  if(PS4.event.button_down.down) {
    toggle[13] = !toggle[13];
    Serial.print("Down: ");
    Serial.println(toggle[13]);
  }
  if(PS4.event.button_down.left) {
    toggle[14] = !toggle[14];
    Serial.print("Left: ");
    Serial.println(toggle[14]);
  }
}

void Serial_joy() {
  
  int leftX = PS4.LStickX();
  int leftY = PS4.LStickY();
  int rightX = PS4.RStickX(); 
  int rightY = PS4.RStickY();
  int Circle = PS4.Circle();
  int Square = PS4.Square();
  int L2 = PS4.L2();
  int R2 = PS4.R2();
  int L1 = PS4.L1();
  int R1 = PS4.R1();

    if (true) {
      turn   = leftX;
      strafe = rightX;
      speed  = rightY;
      SWmode = toggle[11];
         if (SWmode ==1){
          turn   = -leftX;
          strafe = -rightX;
          speed  = rightY;
        }

    }
  snprintf(messageToSend, sizeof(messageToSend), "%d,%d,%d,%d,%d,%d\n",
           turn, speed, strafe, toggle[6], toggle[7], SWmode);
  Serial.print(messageToSend);       // ✅ Debug Monitor
  // Serial1.print(messageToSend);      // ✅ ส่งออกไปยัง Mega            
  delay(50);

}