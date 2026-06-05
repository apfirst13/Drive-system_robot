void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
#include <ps5Controller.h>

int speed = 0, strafe = 0, turn = 0;
int slow_mode = 0 , SWmode = 0 , shootMT = 0;

bool toggle[16] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};

#define motorLF1 32
#define motorLF2 33

#define motorRF1 23
#define motorRF2 21

#define motorRB1 17
#define motorRB2 16

#define motorLB1 12
#define motorLB2 13

#define motor_shoot_up 27
#define motor_shoot_down 2

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
    Serial.println(toggle[4]);
  }
  if(ps5.event.button_down.r1) {
    toggle[6] = !toggle[6];
    Serial.print("R1: ");
    Serial.println(toggle[6]);
  }
   if(ps5.event.button_down.r2) {
    toggle[7] = !toggle[7];
    Serial.print("R2: ");
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

  ps5.attachOnConnect(onConnect);
  ps5.attachOnDisconnect(onDisConnect);
  ps5.attach(onEvent);
  ps5.begin("14:3A:9A:31:00:13"); // เปลี่ยนเป็น MAC ของ PS5 Controller
  Serial.println("Bluetooth Ready.");
}


void loop() {
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

  // แปลงค่าจากจอยเป็นข้อมูลควบคุม
  // turn   = leftX;
  // strafe = rightX;
  // speed  = -rightY;  // แกน Y กลับค่าตามลอจิกหุ่น

  // slow_mode = toggle[4];  // L1
  // // shootMT   = toggle[6];  // R1
  // // SWmode    = toggle[11]; // Touchpad

  // // if (SWmode == 1) {
  // //   turn   = -leftX;
  // //   strafe = -rightX;
  // //   speed  = rightY;
  // // 
 4                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             1
   String messageToSend = String(leftX) + "," + //String(rightY)
                       String(rightY)+ "," +
                       String(rightX) + "," +
                       String(toggle[4]) + "," +
                       String(toggle[6]) + "," +
                       String(toggle[7]) + "," +
                       String(toggle[11]) + "," +
                       String(toggle[5]) + "," + "\n";
                      //  String(R1) + "," +
                      //  String(L1) + "," +
                      //  String(toggle[13]) + "," +
                      //  String(Square) + 
                      //  String(Circle) + "," +"\n";  
  Serial.print(messageToSend);       // ✅ Debug Monitor
  

  // Serial1.print(messageToSend); // ส่งไปบอร์ดอื่น ถ้ามี

  delay(70); // หน่วงเพื่อความเสถียร
}