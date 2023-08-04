void task_3() {
  while (1) {

    updateSensors();
    Propotional_derivative_slow();

    if (f_panel[4] == 1 && f_panel[5] == 1 && f_panel[6] == 1 && f_panel[7] == 1 && f_panel[8] == 1 && f_panel[9] == 1 && f_panel[10] == 1 && f_panel[11] == 1) {
      robotHardStop();
      robotStop();
      encoderForwardGO(1);
      if (f_panel[2] == 1 &&f_panel[3] == 1 &&f_panel[4] == 1 && f_panel[5] == 1 && f_panel[6] == 1 && f_panel[7] == 1 && f_panel[8] == 1 && f_panel[9] == 1 && f_panel[10] == 1 && f_panel[11] == 1&& f_panel[12] == 1&& f_panel[13] == 1) {
        robotHardStop();
        robotStop();
        buzzer_end();
        break;
      }

    }

    if ((  (f_panel[3] == 1 || f_panel[4] == 1 ) && f_panel[6] == 0 && f_panel[7] == 0 &&  (f_panel[11] == 1 || f_panel[12] == 1 )) || ((f_panel[3] == 1 || f_panel[4] == 1 ) && f_panel[7] == 0 && f_panel[8] == 0 && (f_panel[11] == 1 || f_panel[12] == 1 )) || ((f_panel[3] == 1 || f_panel[4] == 1 ) && f_panel[8] == 0 && f_panel[9] == 0 && (f_panel[11] == 1 || f_panel[12] == 1 ))) {
      updateSensors();
      detect_node_2();
      robotHardStop();
      nd = true;
      //encoderForwardGO_N(0.1);
      buzzer_2();
      encoderForwardGO(4.9);
      robotHardStop();
      //  while(1);
      // delay(100);
      digitalWrite(GLED1, LOW); digitalWrite(GLED2, LOW); digitalWrite(RLED, LOW);
      //encoderForwardGO(8.5);
      // robotHardStop();
      smooth();
      //while(1);
      robotHardStop();
      if (nd == true) {
        dis_Cal();
      }
      encoderForwardGO(7);
    }
  }
}

void dis_Cal() {
  knobRight.write(0);
  knobLeft.write(0);
  while (1) {
    updateSensors();
    Propotional_derivative_slow();

    if ((  (f_panel[3] == 1 || f_panel[4] == 1 ) && f_panel[6] == 0 && f_panel[7] == 0 &&  (f_panel[11] == 1 || f_panel[12] == 1 )) || ((f_panel[3] == 1 || f_panel[4] == 1 ) && f_panel[7] == 0 && f_panel[8] == 0 && (f_panel[11] == 1 || f_panel[12] == 1 )) || ((f_panel[3] == 1 || f_panel[4] == 1 ) && f_panel[8] == 0 && f_panel[9] == 0 && (f_panel[11] == 1 || f_panel[12] == 1 )))
    {
      dis_cal = ((abs(knobRight.read()) + abs(knobLeft.read())) / 2) / 51.48;
      break;
    }
  }
  robotHardStop();
  robotHardStop();
  robotStop();
  buzzer_2();
  Serial.println(dis_cal);
  lcd.clear();
  lcd.print(dis_cal);
  lcd.setCursor(5, 0);
  lcd.print("cm");
  delay(50);
  nd = false;
}


/////////////////////////////////////////////////////////////////////test////////////////////////////////////////////////
void test_slow() {
  updateSensors();
  Propotional_derivative_slow();
  if (f_panel[4] == 1 && f_panel[5] == 1 && f_panel[6] == 1 && f_panel[7] == 1 && f_panel[8] == 1 && f_panel[9] == 1 && f_panel[10] == 1 && f_panel[11] == 1) {
    robotHardStop();
    robotStop();
    encoderForwardGO(1);
    if (f_panel[4] == 1 && f_panel[5] == 1 && f_panel[6] == 1 && f_panel[7] == 1 && f_panel[8] == 1 && f_panel[9] == 1 && f_panel[10] == 1 && f_panel[11] == 1) {
      robotHardStop();
      robotStop();
      buzzer_end();
      while (1);
    }

  }


}

//////////////////////////////////////////////////////final///////////////////////////////////////////////////////////////

void final_display() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("t_n=");
  lcd.print(tn);
  lcd.setCursor(7, 0);
  lcd.print("f_n=");
  lcd.print(fn);
  lcd.setCursor(0, 1);
  lcd.print("distance=");
  lcd.setCursor(10, 2);
  lcd.print(dis_cal);

}

