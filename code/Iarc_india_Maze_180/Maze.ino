void calculateShortpath() {

  while (1) {

    path[path_length] = path_array[ii];
    path_length++;
    simplify_path();
    ii ++;
    //     Serial.print(i);
    if (path_array[ii] == 'X') {
      myCnt = ii ;
      break;
    }
  }
}





void updateturn(char turn) {

  path_array[pathIndex] = turn;
  pathIndex++;

}



void Solved_maze() {


  int path_cnt = 0;

  while (1) {
    updateSensors();
    Propotional_derivative();

    if (sCnt > 6) {
      robotHardStop();
      updateSensors();
      if (sCnt > 6) {
        encoderForwardGO(3.5);  // end
        break;
      }
      if (path[path_cnt] == 'R') {
        encoderForwardGO(3.5);
         RobotTurnRight_SP();
        path_cnt++;
      }
      else if (path[path_cnt] == 'L') {
        encoderForwardGO(3.5);
       RobotTurnLeft_SP();
        path_cnt++;
      }
      else if (path[path_cnt] == 'S') {
        encoderForwardGO(3.5);
        path_cnt++;
      }
    }

    else if (lCnt > 2 && S7_flg == 0) {
      robotHardStop();
      updateSensors();

      if (sCnt != 0) {
        if (path[path_cnt] == 'S') {
          encoderForwardGO(3.5);
          path_cnt++;
        }
        else if (path[path_cnt] == 'L') {
          encoderForwardGO(3.5);
         RobotTurnLeft_SP();
          path_cnt++;
        }
      }
      else {
        encoderForwardGO(3.5);
       RobotTurnLeft_SP();
      }
    }

    else if (rCnt > 2 && S0_flg == 0) {
      robotHardStop();
      updateSensors();
      if (sCnt != 0) {
        if (path[path_cnt] == 'S') {
          encoderForwardGO(3.5);
          path_cnt++;
        }
        else if (path[path_cnt] == 'R') {
          encoderForwardGO(3.5);
           RobotTurnRight_SP();
          path_cnt++;
        }
      }
      else {
        encoderForwardGO(3.5);
         RobotTurnRight_SP();
      }
    }



  }
  robotHardStop();


}

void simplify_path()
{
  // only simplify the path if the second-to-last turn was a 'B'
  if (path_length < 3 || path[path_length - 2] != 'B')
    return;

  int total_angle = 0;
  int i;
  for (i = 1; i <= 3; i++)
  {
    switch (path[path_length - i])
    {
      case 'R':
        total_angle += 90;
        break;
      case 'L':
        total_angle += 270;
        break;
      case 'B':
        total_angle += 180;
        break;
    }
  }

  // Get the angle as a number between 0 and 360 degrees.
  total_angle = total_angle % 360;

  // Replace all of those turns with a single one.
  switch (total_angle)
  {
    case 0:
      path[path_length - 3] = 'S';
      break;
    case 90:
      path[path_length - 3] = 'R';
      break;
    case 180:
      path[path_length - 3] = 'B';
      break;
    case 270:
      path[path_length - 3] = 'L';
      break;
  }

  // The path is now two steps shorter.
  path_length -= 2;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void New_maze_solve() {

  while (1) {
    updateSensors();
    Propotional_derivative();

    if ((  (f_panel[3] == 1 || f_panel[4] == 1 ) && f_panel[6] == 0 && f_panel[7] == 0 &&  (f_panel[11] == 1 || f_panel[12] == 1 )) || ((f_panel[3] == 1 || f_panel[4] == 1 ) && f_panel[7] == 0 && f_panel[8] == 0 && (f_panel[11] == 1 || f_panel[12] == 1 )) || ((f_panel[3] == 1 || f_panel[4] == 1 ) && f_panel[8] == 0 && f_panel[9] == 0 && (f_panel[11] == 1 || f_panel[12] == 1 ))) {
     // updateSensors();
      detect_node_1();
      robotHardStop();
     
      //encoderForwardGO_N(0.1);
      buzzer_2();
      encoderForwardGO(2.5);

      //while(1);
      delay(100);
      digitalWrite(GLED1, LOW); digitalWrite(GLED2, LOW); digitalWrite(RLED, LOW);
      lcd.clear();
      //encoderForwardGO(8.5);
  // robotHardStop();
      smooth();
      //while(1);

    }


    if (f_panel[1] == 0 && (( f_panel[10] == 1 && f_panel[9] == 1 && f_panel[8] == 1 && f_panel[7] == 1 && f_panel[6] == 1 && f_panel[5] == 1) || ( (f_panel[10] == 1 || f_panel[11] == 1) &&   (f_panel[9] == 1 && f_panel[8] == 1 && f_panel[7] == 1 && f_panel[6] == 1) &&  (f_panel[5] == 1 || f_panel[4] == 1)) ) && f_panel[14] == 0 )
    { //Y juc
      robotStop();
      robotHardStop();
      buzzer_2();

      updateturn('L');
      encoderForwardGO(1.7);
     RobotTurnLeft_SP();


      // while(1);
    }


    if (f_panel[4] == 1 && f_panel[5] == 1 && f_panel[6] == 1 && f_panel[7] == 1 && f_panel[8] == 1 && f_panel[9] == 1 && f_panel[10] == 1 && f_panel[11] == 1) {
      robotHardStop();
      updateSensors();
      if (f_panel[3] == 1 && f_panel[6] == 1 && f_panel[7] == 1 && f_panel[8] == 1 && f_panel[9] == 1 && f_panel[12] == 1) {
        buzzer_4();  // End
        updateturn('X');
        
      }
      if ((f_panel[6] == 1 && f_panel[7] == 1) || (f_panel[7] == 1 && f_panel[8] == 1) || (f_panel[8] == 1 && f_panel[10] == 1)) {
        buzzer_2();  // cross
        updateturn('L');
        encoderForwardGO(0.8);
       RobotTurnLeft_SP();
      }
      if (f_panel[4] == 0 && f_panel[6] == 0 && f_panel[7] == 0 && f_panel[8] == 0 && f_panel[9] == 0 && f_panel[12] == 0) {
        buzzer_1();  // T
        updateturn('L');
        encoderForwardGO(0.5);
       RobotTurnLeft_SP();
      }
    }
    if (f_panel[2] == 1 && f_panel[3] == 1 && f_panel[4] == 1 && f_panel[5] == 1 && f_panel[6] == 1 && f_panel[13] == 0) { // right
      robotHardStop();
      updateSensors();
      if ((f_panel[6] == 1 && f_panel[7] == 1) || (f_panel[7] == 1 && f_panel[8] == 1) || (f_panel[9] == 1 && f_panel[10] == 1) || (f_panel[8] == 1 && f_panel[9] == 1)) {
        buzzer_2();  // Side T Right
        updateturn('S');
      }
      if (f_panel[5] == 0 && f_panel[6] == 0 && f_panel[7] == 0 && f_panel[8] == 0 && f_panel[9] == 0 && f_panel[10] == 0) {
        buzzer_1();  // Right
        encoderForwardGO(0.5);
         RobotTurnRight_SP();
      }
      //break;
    }
    if (f_panel[15] == 1 && f_panel[14] == 1 && f_panel[13] == 1 && f_panel[12] == 1 && f_panel[11] == 1 && f_panel[2] == 0) { // left
      robotHardStop();
      updateSensors();
      if ((f_panel[11] == 1 && f_panel[10] == 1) || (f_panel[10] == 1 && f_panel[9] == 1) || (f_panel[9] == 1 && f_panel[8] == 1) || (f_panel[8] == 1 && f_panel[7] == 1)) {
        buzzer_2();  // Side T Left
        updateturn('L');
        encoderForwardGO(0.5);
       RobotTurnLeft_SP();
      }
      if (f_panel[4] == 0 && f_panel[6] == 0 && f_panel[7] == 0 && f_panel[8] == 0 && f_panel[9] == 0 && f_panel[12] == 0) {
        buzzer_1();  // Left
        encoderForwardGO(0.5);
       RobotTurnLeft_SP();
      }
      //break;
    }
    if ( f_panel[1] == 0 && f_panel[2] == 0 && f_panel[3] == 0 && f_panel[4] == 0 && f_panel[5] == 0 && f_panel[6] == 0 && f_panel[7] == 0 && f_panel[8] == 0 && f_panel[9] == 0 && f_panel[10] == 0 && f_panel[11] == 0 && f_panel[12] == 0 && f_panel[13] == 0) {
      robotHardStop();  // deadend   break;
      buzzer_1();
      updateturn('B');
      encoderForwardGO(0.75 );
       dis_RF= SharpR_f.distance(); 
      dis_LF= Sharpl_f.distance();
      //updateturn('B');
      
      robotHardStop();
      if ((dis_LF < 30 && dis_LF != 0) || (dis_RF < 30 && dis_RF != 0))
      {
        buzzer_2();
        led();
        robotHardStop();
        break;
      } else {
       RobotTurnLeft_SP();
      }
     //RobotTurnLeft_SP();
    }
  }

}

