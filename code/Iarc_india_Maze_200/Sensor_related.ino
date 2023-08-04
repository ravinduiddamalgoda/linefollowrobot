void updateSensors()
 {

   f_panel[0]  =digitalRead(53);
   f_panel[1]  =digitalRead(51);
   f_panel[2]  =digitalRead(49);
   f_panel[3]  =digitalRead(47);
   f_panel[4]  =digitalRead(22);
   f_panel[5]  =digitalRead(24);
   f_panel[6]  =digitalRead(26);
   f_panel[7]  =digitalRead(28);
   f_panel[8]  =digitalRead(30);
   f_panel[9]  =digitalRead(32);
   f_panel[10] =digitalRead(34);
   f_panel[11] =digitalRead(36);
   f_panel[12] =digitalRead(45);
   f_panel[13] =digitalRead(43);
   f_panel[14] =digitalRead(41);
   f_panel[15] =digitalRead(39);
   /*
   lcd.clear();
   lcd.setCursor(5,0);
   lcd.print("_MARK_50_");
   lcd.setCursor(0,1);
   lcd.print(f_panel[0]);
    lcd.setCursor(1,1);
   lcd.print(f_panel[1]);
    lcd.setCursor(2,1);
   lcd.print(f_panel[2]);
    lcd.setCursor(3,1);
   lcd.print(f_panel[3]);
    lcd.setCursor(4,1);
   lcd.print(f_panel[4]);
    lcd.setCursor(5,1);
   lcd.print(f_panel[5]);
    lcd.setCursor(6,1);
   lcd.print(f_panel[6]);
    lcd.setCursor(7,1);
   lcd.print(f_panel[7]);
    lcd.setCursor(8,1);
   lcd.print(f_panel[8]);
    lcd.setCursor(9,1);
   lcd.print(f_panel[9]);
    lcd.setCursor(10,1);
   lcd.print(f_panel[10]);
    lcd.setCursor(11,1);
   lcd.print(f_panel[11]);
    lcd.setCursor(12,1);
   lcd.print(f_panel[12]);
    lcd.setCursor(13,1);
   lcd.print(f_panel[13]);
    lcd.setCursor(14,1);
   lcd.print(f_panel[14]);
    lcd.setCursor(15,1);
   lcd.print(f_panel[15]);
   */
  /* if(digitalRead(f_panel[0])==0){S0_flg=1; }else {S0_flg=0; }                    //Reset sensor flags
   if(digitalRead(f_panel[1])==0){S1_flg=1; }else {S1_flg=0; }                    //update ssensor status
   if(digitalRead(f_panel[2])==0){S2_flg=1; }else {S2_flg=0;}
   if(digitalRead(f_panel[3])==0){S3_flg=1; }else {S3_flg=0;}
   if(digitalRead(f_panel[4])==0){S4_flg=1; }else {S4_flg=0;}
   if(digitalRead(f_panel[5])==0){S5_flg=1; }else {S5_flg=0;}
   if(digitalRead(f_panel[6])==0){S6_flg=1; }else {S6_flg=0; }      
                 
   if(digitalRead(f_panel[7])==0){S7_flg=1; }else {S7_flg=0; }
*/
   //backSensors();
  // Serial.println(rCnt);
   
  Serial.print(f_panel[0]);Serial.print(f_panel[1]);Serial.print(f_panel[2]);Serial.print(f_panel[3]);
  Serial.print(f_panel[4]);Serial.print(f_panel[5]);  
  Serial.print(f_panel[6]);Serial.print(f_panel[7]);          
  Serial.print(f_panel[8]);Serial.print(f_panel[9]);Serial.print(f_panel[10]);Serial.print(f_panel[11]);
  Serial.print(f_panel[12]);Serial.print(f_panel[13]);  //debug
  Serial.print(f_panel[14]);Serial.println(f_panel[15]); 
  //Serial.println(lCnt);Serial.println(rCnt);Serial.println(sCnt);
  /*Serial.print(S0_flg);Serial.print(S1_flg);Serial.print(S2_flg);Serial.print(S3_flg);
   Serial.print(S4_flg);Serial.print(S5_flg);  //debug
   Serial.print(S6_flg);Serial.println(S7_flg);*/

 }

void updateSensors_x(){
 
x_panel[0]  =digitalRead(A15);
   x_panel[1]  =digitalRead(A14);
   x_panel[2]  =digitalRead(A13);
   x_panel[3]  =digitalRead(A12);
   x_panel[4]  =digitalRead(A0);
   x_panel[5]  =digitalRead(A3);
   x_panel[6]  =digitalRead(A4);
   x_panel[7]  =digitalRead(A5);
 

    Serial.print(x_panel[0]);
    Serial.print(x_panel[1]);
    Serial.print(x_panel[2]);
    Serial.print(x_panel[3]);
    Serial.print(x_panel[4]);
    Serial.print(x_panel[5]);
    Serial.print(x_panel[6]);
    Serial.println(x_panel[7]);
}
/* void backSensors(){
   qtrrcBack.read(sensorValuesBack);
   
   for (unsigned char i = 0; i < 8; i++)
  {
    f_panel[i]=sensorValuesBack[i];
  }
  for (unsigned char x = 0; x < 8; x++)
  {
    if (f_panel[x] < 1200 ) f_panel[x]=0;
    else (f_panel[x])=1;
  }
 }

*/
void Update_dis_R (){
  
 dis_r= SharpR.distance();
 dis_RF= SharpR_f.distance(); 
 dis_f= Sharp_f.distance();
 dis_LF=Sharpl_f.distance();
 Serial.print( dis_LF); 
 Serial.print("     ");
 Serial.print( dis_RF); 
 Serial.print("     ");
 Serial.println( dis_f); 
  }


void Update_dis_L (){
  
  dis_l= SharpL.distance();   
 dis_RF= SharpR_f.distance(); 
 dis_f= Sharp_f.distance();
 dis_LF=Sharpl_f.distance();
 Serial.print( dis_LF); 
 Serial.print("     ");
 Serial.print( dis_RF); 
 Serial.print("     ");
 Serial.print( dis_f); 
 Serial.print("     ");
 Serial.println( dis_l); 

  }





 
/*void readDisSensor_R(){
   SonarDistanceR = sonarR.ping_cm();
   //SonarDistanceL = sonarL.ping_cm();   
   //SonarDistanceM = sonarM.ping_cm();  
   Serial.println(SonarDistanceR);
  }
void readDisSensor_L(){
   //SonarDistanceR = sonarR.ping_cm();
   SonarDistanceL = sonarL.ping_cm();   
   //SonarDistanceM = sonarM.ping_cm();  
   Serial.println(SonarDistanceL);
  }
*/
