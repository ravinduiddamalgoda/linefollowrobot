void wall_propotional_R()
{

  int REC_DIS = 10;
  int DIS_ERR = 0;
  int Kp = 4.64;
  errorSum = errorSum + DIS_ERR;
  double Kd = 40  ;
  DIS_ERR = REC_DIS - dis_r;
  int prop = Kp * DIS_ERR + Kd * (DIS_ERR - LastError) + 8 * errorSum;
  int speedL = wall_s - prop;
  int speedR = wall_s + prop;
  LastError = DIS_ERR;

  if (speedL > 255)speedL = 255;
  else if (speedL < 10)speedL = 10;

  if (speedR > 255)speedR = 255;
  else if (speedR < 10)speedR = 10;
  // Serial.println(SonarDistance);
  // Serial.print(speedL);Serial.print(" ");Serial.println(speedR);
  RobotFwd(speedL, speedR) ;
  // delay(1);
}

void wall_propotional_L()
{

  int REC_DIS = 10;
  int DIS_ERR = 0;
  int Kp = 4.65;
  errorSum = errorSum + DIS_ERR;
  double Kd = 40;
  DIS_ERR = REC_DIS - dis_l;
  int prop = Kp * DIS_ERR + Kd * (DIS_ERR - LastError) + 8 * errorSum;
  int speedL = wall_s + prop;
  int speedR = wall_s - prop;
  LastError = DIS_ERR;

  if (speedL > 255)speedL = 255;
  else if (speedL < 10)speedL = 10;

  if (speedR > 255)speedR = 255;
  else if (speedR < 10)speedR = 10;
  //   Serial.println(SonarDistance);
  // Serial.print(speedL);Serial.print(" ");Serial.println(speedR);
  RobotFwd(speedL, speedR) ;

}


void wall_f_f_right()
{
  while (1) {
    Update_dis_R ();
    wall_propotional_R();
    updateSensors();
  
   // if(wall_1st==true){
   if((f_panel[0]==1 && f_panel[1]==1 )||(f_panel[1]==1 && f_panel[2]==1 )||(f_panel[2]==1 && f_panel[3]==1 )||(f_panel[3]==1 && f_panel[4]==1 )||(f_panel[4]==1 && f_panel[5]==1 )||(f_panel[5]==1 && f_panel[6]==1 )||(f_panel[6]==1 && f_panel[7]==1 )||(f_panel[7]==1 && f_panel[8]==1 )||(f_panel[8]==1 && f_panel[9]==1 )||(f_panel[9]==1 && f_panel[10]==1 )||(f_panel[10]==1 && f_panel[11]==1 )||(f_panel[11]==1 && f_panel[12]==1 )||(f_panel[12]==1 && f_panel[13]==1 )||(f_panel[13]==1 && f_panel[14]==1 )||(f_panel[14]==1 && f_panel[15]==1 )){
      robotHardStop(); wall_cnt=2; 
      buzzer_3();
      break;
    }
   //  }
    if ((dis_f == 4 || dis_f == 5 || dis_f == 6 || dis_f == 7 || dis_f == 8 || dis_f == 9 || dis_f == 10 || dis_f == 11 || dis_f == 12 || dis_f == 13 || dis_f == 14 || dis_f == 15  ) ) {

      if (dis_f < 16 && dis_RF < 25) {
        robotHardStop();
        if(dis_f == 4 || dis_f == 5 || dis_f == 6 || dis_f == 7 || dis_f == 8 ){
           encoderBackwardGO(2); 
            }
        RobotTurnLeft_wall();
      }
    }
    if (dis_RF == 0 || dis_RF > 20) {
      robotHardStop();
      detect_wall();
      lcd.clear();
      lcd.print(cm_l);
      lcd.setCursor(0,5);
      lcd.print(cm_r);
       encoderForwardGO(17);
       
       delay(10);
     ultra_dis_l();
     ultra_dis_r();
      ultra_dis_l();
    ultra_dis_r();
      
      if (cm_r > 35 || cm_r == 0) {
        ultra_dis_l();
        ultra_dis_r();
      if (cm_r > 35 || cm_r == 0) {
       if(cm_l < 35 && cm_l!=0){ current_wall='L';wall_cnt++; break;}// wall otherside break
      }
      }
      RobotTurnRight_single();
      encoderForwardGO_N(10);
    }

  }
}


void wall_f_f_left()
{
  while (1) {
    Update_dis_L ();
    wall_propotional_L();
     
    updateSensors();
    //if(wall_1st==true){
    if((f_panel[0]==1 && f_panel[1]==1 )||(f_panel[1]==1 && f_panel[2]==1 )||(f_panel[2]==1 && f_panel[3]==1 )||(f_panel[3]==1 && f_panel[4]==1 )||(f_panel[4]==1 && f_panel[5]==1 )||(f_panel[5]==1 && f_panel[6]==1 )||(f_panel[6]==1 && f_panel[7]==1 )||(f_panel[7]==1 && f_panel[8]==1 )||(f_panel[8]==1 && f_panel[9]==1 )||(f_panel[9]==1 && f_panel[10]==1 )||(f_panel[10]==1 && f_panel[11]==1 )||(f_panel[11]==1 && f_panel[12]==1 )||(f_panel[12]==1 && f_panel[13]==1 )||(f_panel[13]==1 && f_panel[14]==1 )||(f_panel[14]==1 && f_panel[15]==1 )){
     robotHardStop(); wall_cnt=2; 
     buzzer_3();
     break;
      }
   // }

    if ((dis_f == 4 || dis_f == 5 || dis_f == 6 || dis_f == 7 || dis_f == 8 || dis_f == 9 || dis_f == 10 || dis_f == 11  || dis_f == 12 || dis_f == 13 || dis_f == 14 || dis_f == 15 ) ) {
      if (dis_f < 16 && dis_LF < 25) {
        robotHardStop();
          if(dis_f == 4 || dis_f == 5 || dis_f == 6 || dis_f == 7 || dis_f == 8 ){
           encoderBackwardGO(2); 
            }
        RobotTurnRight_wall();
      }
    }
    if (dis_LF == 0 || dis_LF > 17) {
      robotHardStop();
      detect_wall();
      lcd.clear();
      lcd.print(cm_l);
      lcd.setCursor(0,5);
      lcd.print(cm_r);
      encoderForwardGO(15);
     delay(10);
      ultra_dis_l();
      ultra_dis_r();
      ultra_dis_l();
      ultra_dis_r();
      //delay(75);
      
      if (cm_l > 30 || cm_l == 0) {
      ultra_dis_l();
      ultra_dis_r();
         if (cm_l > 30 || cm_l == 0) {
        if(cm_r < 30 && cm_r!=0){ current_wall='R';wall_cnt++; break;}// wall otherside break
      }
      }
      //encoderForwardGO(15);
      RobotTurnLeft_single();
      encoderForwardGO_N(11);
    }

  }
}

void ultra_dis_r() {
  digitalWrite(TRIGGER_PINR, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PINR, LOW);
  duration = pulseIn(ECHO_PINR, HIGH);
  cm_r = (duration / 2) / 29.1; // inches = (duration / 2) / 74;
 // if(cm_r<4){ cm_r=0;}
  Serial.println(cm_r);

}

void ultra_dis_l() {


  digitalWrite(TRIGGER_PINL, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PINL, LOW);
  duration = pulseIn(ECHO_PINL, HIGH);
  cm_l = (duration / 2) / 29.1; 
  


  // inches = (duration / 2) / 74;

  // Serial.print(duration);
  // Serial.print(",");

  Serial.println(cm_l);
  // Serial.print("cm");

  // Serial.print(inches);
  //Serial.print("inches");
  // Serial.println();
}


void detect_wall() {

  wall_right = 0;
  wall_left = 0;
  ultra_dis_r();
  ultra_dis_l();
  



}

void full_wall_follow() {

  dis_RF= SharpR_f.distance();
  dis_LF=Sharpl_f.distance();
    delay(10);
  if (dis_LF< 25 && dis_LF!=0){current_wall = 'L';}
  if (dis_RF < 25 && dis_RF !=0){current_wall = 'R';}
      lcd.clear();
      lcd.print(dis_LF);
      lcd.setCursor(0,5);
      lcd.print(dis_RF);

      //while(1);
  while (1) {
    if (wall_cnt==2){break;}
     if (wall_cnt==1){wall_1st = true;}
      
    if (current_wall == 'L') { // left wall follow
      wall_f_f_left();
    }
    if (current_wall == 'R'){ // right wall follow
      wall_f_f_right();
    }
   if (wall_cnt==1){wall_1st = true;}
   
  }


}
