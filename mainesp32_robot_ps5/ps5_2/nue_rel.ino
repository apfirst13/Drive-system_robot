void rel(int go_shoot) {
  // Serial.println(go_shoot);
  if (go_shoot ==1 )
  {
    digitalWrite(gogo_shoot,HIGH);
    // Serial.println("open");
  }
  else{
    digitalWrite(gogo_shoot,LOW);
    // Serial.println("off");
  }

}

void rel1(int protect ) {
  if (protect ==1 )
  {
    digitalWrite(pro_tect,HIGH);
    // Serial.println("open");
  }
  else{
    digitalWrite(pro_tect,LOW);
    // Serial.println("off");
  }

}