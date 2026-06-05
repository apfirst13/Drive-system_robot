#include <ps5Controller.h>

#define motorLF1 4
#define motorLF2 5

#define motorRF1 33
#define motorRF2 15

#define motorRB1 23
#define motorRB2 32

#define motorLB1 26
#define motorLB2 27

#define motor_shoot_up 18
#define motor_shoot_down 19
#define en_shooter 21 //dir

#define pro_tect 25
#define gogo_shoot 13

int speed = 0, strafe = 0, turn = 0;

int slow_mode = 0 , SWmode = 0 ;

int nue_shootMT = 0 ,stop_shoot=0;

int go_shoot =0 ;

int power=0 ,power1=0 , power2=0;

int protect =0; 

bool toggle[16] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};

void onConnect() {
  Serial.println("Connected!.");
}

void onDisConnect() {
  Serial.println("Disconnected!.");
}

void onEvent() {
  if(ps5.event.button_down.square) {
    toggle[0] = !toggle[0];
    Serial.print("Square: ");
    Serial.println(toggle[0]);
  }
  if(ps5.event.button_down.triangle) {
    toggle[1] = !toggle[1];
    Serial.print("Triangle: ");
    Serial.println(toggle[1]);
  }
  if(ps5.event.button_down.circle) {
    toggle[2] = !toggle[2];
    Serial.print("Circle: ");
    Serial.println(toggle[2]);
  }
  if(ps5.event.button_down.cross){
    toggle[3] = !toggle[3];
    Serial.print("Cross: ");
    Serial.println(toggle[3]);
  }
  if(ps5.event.button_down.l1) {
    toggle[4] = !toggle[4];
    Serial.print("L1: ");
    Serial.println(toggle[4]);
  }
   if(ps5.event.button_down.l2) {
    toggle[5] = !toggle[5];
    Serial.print("L2: ");
    Serial.println(toggle[5]);
  }
  if(ps5.event.button_down.r1) {
    toggle[6] = !toggle[6];
    Serial.print("R1: ");
    Serial.println(toggle[6]);
  }
    if(ps5.event.button_down.r2) {
    toggle[7] = !toggle[7];
    Serial.print("R1: ");
    Serial.println(toggle[7]);
  }
  if(ps5.event.button_down.share) {
    toggle[8] = !toggle[8];
    Serial.print("Share: ");
    Serial.println(toggle[8]);
  }
  if(ps5.event.button_down.ps) {
    toggle[10] = !toggle[10];
    Serial.print("PS: ");
    Serial.println(toggle[10]);
  }
  if(ps5.event.button_down.touchpad) {
    toggle[11] = !toggle[11];
    Serial.print("Touchpad: ");
    Serial.println(toggle[11]);
  }
  if(ps5.event.button_down.up) {
    toggle[12] = !toggle[12];
    Serial.print("Up: ");
    Serial.println(toggle[12]);
  }
  if(ps5.event.button_down.down) {
    toggle[13] = !toggle[13];
    Serial.print("Down: ");
    Serial.println(toggle[13]);
  }
  if(ps5.event.button_down.left) {
    toggle[14] = !toggle[14];
    Serial.print("Left: ");
    Serial.println(toggle[14]);
  }
}

enum RobotState {
  STATE_IDLE,         // รอการสั่งงาน
  STATE_DRIVE,        // ขับเคลื่อน
  STATE_SHOOT,        // ยิงลูก
  STATE_SHOOT_STOP    // หยุดยิง
};

RobotState currentState = STATE_IDLE;


void setup() {
  Serial.begin(115200);
  ps5.attachOnConnect(onConnect);
  ps5.attachOnDisconnect(onDisConnect);
  ps5.attach(onEvent);
  // ps5.begin("88:03:4C:79:F5:36"); // joy cotton
  ps5.begin(14:3A:9A:2F:BE:32); // joy ขาว

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
  pinMode(en_shooter,OUTPUT);

  pinMode(pro_tect, OUTPUT);
  pinMode(gogo_shoot,OUTPUT);

  analogWrite(motor_shoot_up, 0);
  analogWrite(motor_shoot_down, 0);
  Serial.println("Bluetooth Ready.");
}
// ตัวอย่างสมมุติ ใช้ไลบรารี ps5controller.h ที่มีฟังก์ชัน setLedColor(r,g,b);

// void setColorBasedOnMode(int sw_mode) {
//   if (sw_mode == 1) {
//     ps5.setLightBar(255, 0, 0);  // แดง โหมด ON
//   } else {
//     ps5.setLightBar(0, 0, 255);  // น้ำเงิน โหมด OFF
//   }
// }


void loop() {
  drive_manual(speed,strafe,turn);
  update_joy();
  rel(go_shoot);
  rel1(protect);

// if (sw_mode != SWmode) {  // ถ้าโหมดเปลี่ยน
//     sw_mode = SWmode;
//     setColorBasedOnMode(sw_mode);
//  }
  // Serial.print(nue_shootMT);

  switch (currentState) {
    case STATE_IDLE:
      if (abs(speed) > 20 || abs(strafe) > 20 || abs(turn) > 20) {
        currentState = STATE_DRIVE;
      } else if (stop_shoot == 1) {
        currentState = STATE_SHOOT_STOP;
      } else if (nue_shootMT == 1 || toggle[14]) {
        currentState = STATE_SHOOT;
      }
      break;

    case STATE_DRIVE:
      drive_manual(speed, strafe, turn);
      if (stop_shoot == 1) currentState = STATE_SHOOT_STOP;
      else if (nue_shootMT == 1 || toggle[14]) currentState = STATE_SHOOT;
      else if (speed == 0 && strafe == 0 && turn == 0) currentState = STATE_IDLE;
      break;

    case STATE_SHOOT:
      if (nue_shootMT == 1) {
        shooter_power(1, 0, 255, 0, 0); // ยิงแบบเต็มกำลัง
      } else {
        if (toggle[14]) {
          shooter_power(0, 0, 0, 200, -150); // ยิงสลับ
        } else {
          shooter_power(0, 0, 0, -150, 200); // ยิงปกติ
        }
      }
      if (stop_shoot == 1) {
        currentState = STATE_SHOOT_STOP;
      }
      break;

    case STATE_SHOOT_STOP:
      shooter_power(nue_shootMT, stop_shoot, 0, 0, 0); // หยุดยิง
      if (stop_shoot == 0) {
        currentState = STATE_IDLE;
      }
      break;
  }

//เปิดพน้อมกันปิดตัวบนและยิง
// Serial.print("Speed: "); Serial.print(speed);
// Serial.print(" | Strafe: "); Serial.print(strafe);
// Serial.print(" | Turn: "); Serial.println(turn);

delay(70);

}

