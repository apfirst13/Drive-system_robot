void update_joy(){
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
turn      = -values[2];
strafe    = -values[0];
speed     = values[1]; 
slow_mode = values[7];//corss
nue_shootMT   = values[4];//l2
protect   = values[5];//r1
stop_shoot   = values[6];//r2
SWmode    = values[8]; //touch
go_shoot    = values[3]; //l1

if (SWmode == 1) {
  turn   = values[2];
  strafe = values[0];
  speed  = -values[1];
}
}