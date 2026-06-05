#include <PS4Controller.h>

int speed = 0, strafe = 0, turn = 0;
int slow_mode = 0 , SWmode = 0 , shootMT = 0;

char messageToSend[64];

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
  Serial.println("PS4 Controller Connected.");
}

void onDisconnect() {
  Serial.println("PS4 Controller Disconnected.");
}

void onEvent();

void setup() {
  Serial.begin(115200);
  Serial.println("Booting...");
  PS4.begin("D4:8A:FC:CF:BC:26");  // ใส่ MAC Address ของ ESP32
  PS4.attach(onEvent);
  PS4.attachOnConnect(onConnect);
  PS4.attachOnDisconnect(onDisconnect);
  set_pin();

  // Serial.println("Waiting for PS4 controller...");
}

void loop() {
  // if (PS4.isConnected()) {
  //   Serial_joy();
  //   drive_manual(speed, strafe, turn);
  // }
    Serial_joy();
    drive_manual(speed, strafe, turn);
}
