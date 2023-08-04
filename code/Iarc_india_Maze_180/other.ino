

/* 
updateSensors_x();
updateSensors();
Update_dis_R ();
c_lim_v=digitalRead(c_lim);
Serial.println(r_lim_v);
Update_dis_L ();
wall_propotional_L();
Update_dis_R();
wall_propotional_R();
Update_wall_lim();
*/
/*

if(c_lim_v == 1 && l_lim_v == 1 && r_lim_v == 1 ){
    robotStop();
    robotHardStop();
    RobotTurnLeft180();
    //while(1);
    }
if(c_lim_v == 1 && l_lim_v == 0 && r_lim_v == 1  ){
    robotStop();
    robotHardStop();
    RobotTurnLeft_wall();
    //while(1);
    }
    
if( c_lim_v == 0 && r_lim_v == 0  ){
    robotStop();
    robotHardStop();
   encoderForwardGO(10);
   RobotTurnRight_wall();
    //while(1);
    }
*/
//updateSensors();

/*
updateSensors();
 Propotional_derivative();


 if (f_panel[1] == 0 && f_panel[2] == 0 && f_panel[3] == 0 && f_panel[4] == 0 && f_panel[5] == 0 && f_panel[6] == 0 && f_panel[7] == 0 && f_panel[8] == 0 && f_panel[9] == 0 && f_panel[10] == 0 && f_panel[11] == 0 && f_panel[12] == 0)
{
  robotStop();
  robotHardStop();
  }
  */
  //Maze_solve();



  //analogWrite( ENB,200);
  //digitalWrite(LN4,HIGH);
  // TurnLeft(200);
/*
  updateSensors();
  Propotional_derivative();

  if ( f_panel[2] == 1 && f_panel[3] == 1 && f_panel[4] == 1 && f_panel[5] == 1 && f_panel[6] == 1 && f_panel[13] == 0) //right turn
  {
    robotHardStop();
    robotStop();
     buzzer_1();
      //while(1);
    //encoderForwardGO(1);
    // encoderBackwardGO();
    RobotTurnRight();
     //while(1);
    //delay(100);
  }

  if (f_panel[15] == 1 && f_panel[14] == 1 && f_panel[13] == 1 && f_panel[12] == 1 && f_panel[11] == 1 && f_panel[2] == 0) //left turn
  {
    robotHardStop();
    robotStop();
    buzzer_1();
     //while(1);
    //encoderForwardGO(1);
     //encoderBackwardGO(1);
    // while(1);
    RobotTurnLeft();
     //while(1);
    // delay(100);

  }
 
  if ( f_panel[1] == 0 && f_panel[2] == 0 && f_panel[3] == 0 && f_panel[4] == 0 && f_panel[5] == 0 && f_panel[6] == 0 && f_panel[7] == 0 && f_panel[8] == 0&& f_panel[9] == 0 && f_panel[10] == 0 && f_panel[11] == 0 && f_panel[12] == 0 && f_panel[13] == 0)
  {
    robotHardStop();
    robotStop();
    buzzer_4();
    //while(1);
    encoderBackwardGO(1);
    //while(1);
    RobotTurnLeft180();
    // while(1);
  }

  if ( f_panel[0] == 1  && f_panel[2] == 1 && f_panel[3] == 1 && f_panel[4] == 1 && f_panel[5] == 1 &&  f_panel[7] == 1)
  {
    robotHardStop();
    robotStop();
    encoderForwardGO(0.5);
    updateSensors();
   // delay(500);
    if ( f_panel[0] == 0 && f_panel[1] == 0 && f_panel[2] == 0 && f_panel[3] == 0 && f_panel[4] == 0 && f_panel[5] == 0 && f_panel[6] == 0 && f_panel[7] == 0) {
      // encoderBackwardGO(0.75);
      //while(1);
      RobotTurnRight();
      updateSensors();
    } if ( f_panel[0] == 1 && f_panel[1] == 1 && f_panel[2] == 1 && f_panel[3] == 1 && f_panel[4] == 1 && f_panel[5] == 1 && f_panel[6] == 1 && f_panel[7] == 1)
    {
      robotStop();
      digitalWrite(37, HIGH);
      delay(200);
      digitalWrite(37, LOW);
      delay(100);
      digitalWrite(37, HIGH);
      delay(200);
      digitalWrite(37, LOW);
      delay(100);
      while (1);
    }

  }
*/
