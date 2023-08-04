void detect_node() {
  while (1) {
    RobotBkwd(50, 60);
    updateSensors();
    if (f_panel[4] == 0 && f_panel[11] == 0) {
      break;
    }
  }
  robotHardStop();
  updateSensors();
  if ((f_panel[6] == 1 && f_panel[7] == 1) || (f_panel[7] == 1 && f_panel[8] == 1) || (f_panel[8] == 1 && f_panel[9] == 1)) {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED1, LOW);
    digitalWrite(GLED2, LOW);
  }
  else {
    digitalWrite(GLED1, HIGH);
    digitalWrite(GLED2, HIGH);
    digitalWrite(RLED, LOW);
  }
}

void detect_node_1(){
  updateSensors_x();
  if ( x_panel[2] == 1 ||  x_panel[3] == 1 || x_panel[4] == 1|| x_panel[4] == 1) {
    if ( x_panel[2] == 1 ||  x_panel[3] == 1 || x_panel[4] == 1|| x_panel[4] == 1) {
    digitalWrite(RLED, HIGH); digitalWrite(GLED1, LOW); digitalWrite(GLED2, LOW);
    fn++;
 lcd.clear();
 lcd.setCursor(2, 0);
 lcd.print("false node");
      
  }
  }else{
    tn++;
   lcd.clear();
 lcd.setCursor(2, 0);
 lcd.print("true node");
      

    digitalWrite(GLED1, HIGH); digitalWrite(GLED2, HIGH); digitalWrite(RLED, LOW);

  }
}
void detect_node_2(){
  updateSensors_x();
  if (x_panel[3] == 1 || x_panel[4] == 1) {
    digitalWrite(RLED, HIGH); digitalWrite(GLED1, LOW); digitalWrite(GLED2, LOW);     
  } else {
 digitalWrite(GLED1, HIGH); digitalWrite(GLED2, HIGH); digitalWrite(RLED, LOW);

  }
}

  void detect_node_t() {

    digitalWrite(GLED1, HIGH); digitalWrite(GLED2, HIGH); digitalWrite(RLED, LOW);

  }


  void detect_node_f() {

    digitalWrite(RLED, HIGH); digitalWrite(GLED1, LOW); digitalWrite(GLED2, LOW);


  }
