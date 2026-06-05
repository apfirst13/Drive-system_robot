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

// #define arm 28
// #define hand 31
// #define drop_ball 26
// #define go_shoot 27

#define pro_tect 25
#define gogo_shoot 13

int8_t pneu_shoot = 0;
int8_t pneu_arm_dribble = 0;
int8_t hand_ball_state = 0;

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



void setup() {
  Serial.begin(115200);
  ps5.attachOnConnect(onConnect);
  ps5.attachOnDisconnect(onDisConnect);
  ps5.attach(onEvent);
  ps5.begin("88:03:4C:79:F5:36"); // เปลี่ยนเป็น MAC ของ PS5 Controller

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

  rel(go_shoot);
  rel1(protect);
  int leftX = ps5.LStickX();
  int leftY = ps5.LStickY();
  int rightX = ps5.RStickX();
  int rightY = ps5.RStickY();
  int Circle = ps5.Circle();
  int Square = ps5.Square();
  int L2 = ps5.L2();
  int R2 = ps5.R2();
  int L1 = ps5.L1();
  int R1 = ps5.R1();
  // int Cross = ps5.Cross();
  // int Left = ps5.Left();
  // int Right = ps5.Right();
  // int Options = ps5.Options();
  int touchpad = toggle[11];
  //int Share = ps5.Share();

 String mess = String(leftX) + "," +
                String(rightY) + "," +
                String(rightX) + "," +
                String(toggle[4]) + "," + //l1
                String(toggle[5]) + "," +//l2
                String(toggle[6]) + "," + //r1
                String(toggle[7]) + "," + // r2
                String(toggle[3]) + "," + //cross
                String(toggle[11]) + "\n";  //touch

  // Serial.print(mess);  // แสดง string รวม
  // Serial1.print(mess);      // ✅ ส่งออกไปยัง Mega\

int values[10];
int index = 0;
int lastIndex = 0;
mess.trim();  // ตัด \n และ space ออก

for (int i = 0; i < mess.length(); i++) {
  if (mess.charAt(i) == ',') {
    values[index++] = mess.substring(lastIndex, i).toInt();
    lastIndex = i + 1;
  }
}

values[index++] = mess.substring(lastIndex).toInt();  // ค่าสุดท้าย

// ✅ ดึงค่าจาก values[]
turn      = values[2];
strafe    = values[0];
speed     = values[1]; 
slow_mode = values[7];//corss
nue_shootMT   = values[4];//l2
protect   = values[5];//r1
stop_shoot   = values[6];//r2
SWmode    = values[8]; //touch
go_shoot    = values[3]; //l1

if (SWmode == 1) {
  turn   = -values[2];
  strafe = -values[0];
  speed  = -values[1];
}
// if (sw_mode != SWmode) {  // ถ้าโหมดเปลี่ยน
//     sw_mode = SWmode;
//     setColorBasedOnMode(sw_mode);
//  }
  // Serial.print(nue_shootMT);

if(stop_shoot == 1) {
  shooter_power(nue_shootMT, stop_shoot, 0, 0, 0);
} else if (nue_shootMT == 1) {
  shooter_power(nue_shootMT, stop_shoot, 255, 0, 0);
} else {
  if(toggle[14]) {
    shooter_power(nue_shootMT, stop_shoot, 0, 20, 160);  // สลับ
    Serial.println("shoot");
  } else {
    shooter_power(nue_shootMT, stop_shoot, 0, -60, 255);  // ปกติ
  }
  if(toggle[12]) {
    shooter_power(nue_shootMT, stop_shoot, 0, 255, 255);  // สลับ
    delay(1000);
    shooter_power(nue_shootMT, stop_shoot, 0, 0, -255);  // สลับ
    delay(1200);
    digitalWrite(gogo_shoot,HIGH);
    }
}


//เปิดพน้อมกันปิดตัวบนและยิง
// Serial.print("Speed: "); Serial.print(speed);
// Serial.print(" | Strafe: "); Serial.print(strafe);
// Serial.print(" | Turn: "); Serial.println(turn);

delay(70);

}

