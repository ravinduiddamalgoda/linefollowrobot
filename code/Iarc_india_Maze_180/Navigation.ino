void Propotional_derivative() {

  int error = f_panel[0] * 0+ f_panel[1] * 0 + f_panel[2] * 0 + f_panel[3] * 0 + f_panel[4] * 50 + f_panel[5] * 30 + f_panel[6] * 20 + f_panel[7] * 10 +f_panel[8] * -10 + f_panel[9] * -20 + f_panel[10] * -30 + f_panel[11] * -50 + f_panel[12] *-0 + f_panel[13] * -0 + f_panel[14] * -0 + f_panel[15] * -0;
  double deri = 60
  * (error - Last_Error);
  int prop = 0.280 * error;
  // sum=+ error+Last_Error;
  //deri = 2*deri;
  Last_Error = error;
  int tot =  prop + deri;

  int SPEEDR = BS - (prop + deri + 0 * sum);
  int SPEEDL = BS + (prop + deri + 0 * sum);

  if (SPEEDL > 255)SPEEDL = 255;
  else if (SPEEDL < 0)SPEEDL = 0;

  if (SPEEDR > 255)SPEEDR = 255;
  else if (SPEEDR < 0)SPEEDR = 0;

  //Serial.print(SPEEDL);Serial.print("     ");Serial.println(SPEEDR);
  RobotFwd(SPEEDL, SPEEDR);
  //call_turn();

}

void Propotional_derivative_slow() {

  int error = f_panel[0] * 0+ f_panel[1] * 0 + f_panel[2] * 0 + f_panel[3] * 0 + f_panel[4] * 15 + f_panel[5] * 10 + f_panel[6] * 8 + f_panel[7] * 5 +f_panel[8] * -5 + f_panel[9] * -8 + f_panel[10] * -10 + f_panel[11] * -15 + f_panel[12] *-0 + f_panel[13] * -0 + f_panel[14] * -0 + f_panel[15] * -0;
  double deri =4.4  //4.5
  * (error - Last_Error);
  int prop =  0.71* error; //0.71
   sum=error+Last_Error;
  //deri = 2*deri;
  Last_Error = error;
  int tot =  prop + deri;
  int it =0.5;
  int SPEEDR = BS_1 - (prop + deri + it*sum);
  int SPEEDL = BS_1 + (prop + deri + it*sum);

  if (SPEEDL > 255)SPEEDL = 255;
  else if (SPEEDL < 0)SPEEDL = 0;

  if (SPEEDR > 255)SPEEDR = 255;
  else if (SPEEDR < 0)SPEEDR = 0;

  //Serial.print(SPEEDL);Serial.print("     ");Serial.println(SPEEDR);
  RobotFwd(SPEEDL, SPEEDR);
  //call_turn();

}



void smooth() {
  while (1) {
    updateSensors();
    int error =f_panel[2] * 12 +f_panel[3] * 10 + f_panel[4] * 8 + f_panel[5] * 5 + f_panel[6] * 3 + f_panel[7] * 1+f_panel[8] * -1 + f_panel[9] * -3 + f_panel[10] * -5 + f_panel[11] * -8 + f_panel[12] * -10 + f_panel[13] * -12;
    if (error < -1) {
      TurnLeft(50);

    } else if (error > 1) {
      TurnRight(50);


    } else {
      robotHardStop();

      break;
    }
  }

}

void encoderForwardGO(float distanceCM) {

  knobRight.write(0);
  knobLeft.write(0);

  while ((abs(knobRight.read()) + abs(knobLeft.read())) / 2 < (distanceCM * 51.48)) {
    RobotFwd(90, 102);
  }

  robotHardStop();
  robotStop();

}



void encoderForwardGO_N(float distanceCM) {

  knobRight.write(0);
  knobLeft.write(0);

  while ((abs(knobRight.read()) + abs(knobLeft.read())) / 2 < (distanceCM * 51.48)) {
    RobotFwd(90, 102);
  }

  

}




void encoderBackwardGO(float distanceCM) {

  knobRight.write(0);
  knobLeft.write(0);

  while ((abs(knobRight.read()) + abs(knobLeft.read())) / 2 < (distanceCM * 51.48)) {
    RobotBkwd(90, 102);
  }

  robotHardStop();
}

/*  void Propotional_derivative1(){
  BS=70;
   int error = S0_flg*15 + S1_flg*10 + S2_flg*7+ S3_flg*3 + S4_flg*-3 + S5_flg*-7 +S6_flg*-10+ S7_flg*-15;
   double deri = 40
    (error - Last_Error);
   int prop= 5.2*error;
   sum=+ error+Last_Error;
   //deri = 2*deri;
   Last_Error= error;

   int SPEEDR = BS+(prop+deri+0*sum);
   int SPEEDL = BS-(prop+deri+0*sum);

   if(SPEEDL>255)SPEEDL=255;
   else if(SPEEDL<0)SPEEDL=0;

   if(SPEEDR>255)SPEEDR=255;
   else if(SPEEDR<0)SPEEDR=0;

   if( S0_flg==0 &&S1_flg==0 &&S2_flg==0 &&S3_flg==0 &&S4_flg==0 &&S5_flg==0 &&S6_flg==0&&S7_flg==0){
   robotHardStop();
    }

  //Serial.print(SPEEDL);Serial.print("     ");Serial.println(SPEEDR);
   RobotFwd(SPEEDR,SPEEDL);
   //call_turn();
    if (S0_flg==0 && S3_flg==1 && S4_flg==1 && S5_flg==1 && S6_flg==1 && S7_flg==1 ){robotHardStop();robotStop();delay(100);encoderForwardGO(3);RobotTurnLeft();}// left turn
   if (S0_flg==1 && S1_flg==1 && S2_flg==1 && S3_flg==1 && S4_flg==1 && S7_flg==0){robotHardStop();robotStop();delay(100);encoderForwardGO(3);RobotTurnRight();}// right turn
  if (S0_flg==0 && S1_flg==1 && S2_flg==1 && S3_flg==1 && S4_flg==1 && S5_flg==1 && S6_flg==1 && S7_flg==0 ){robotHardStop();robotStop(); delay(10000);encoderForwardGO(2);RobotTurnLeft();delay(2);}
  }
*//*
  void wall_follow_from_right(){
  while(1){
    readDisSensor_R();
    wall_propotional_R();

    if (digitalRead(Right_S)==1){break;}
    }
    robotHardStop();
    robotStop();
  }

  void wall_follow_from_left(){
  while(1){
    readDisSensor_L();
    wall_propotional_L();

    if (digitalRead(Left_S)==1){break;}
    }
    robotHardStop();
    robotStop();
  }
*/


