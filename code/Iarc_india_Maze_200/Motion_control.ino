void RobotFwd(int LeftSpeed,int RightSpeed)       // Move robot Foward with given Speed ** rightSpeed - speed for Right motor, LeftSpeed - speed for Left motor
{
  analogWrite(ENA,LeftSpeed); analogWrite(ENB,RightSpeed); digitalWrite(LN1,HIGH); digitalWrite(LN2,LOW); digitalWrite(LN3,HIGH); digitalWrite(LN4,LOW); 
}

void RobotBkwd(int LeftSpeed,int RightSpeed)       // Move robot Foward with given Speed ** rightSpeed - speed for Right motor, LeftSpeed - speed for Left motor
{
  analogWrite(ENA,LeftSpeed); analogWrite(ENB,RightSpeed); digitalWrite(LN1,LOW); digitalWrite(LN2,HIGH); digitalWrite(LN3,LOW); digitalWrite(LN4,HIGH); 
}

void robotStop()                                  //Stop robot slowly -free running mode    
{
  analogWrite(ENA,0); analogWrite(ENB,0); digitalWrite(LN1,LOW); digitalWrite(LN2,LOW); digitalWrite(LN3,LOW); digitalWrite(LN4,LOW);
 
}
void robotHardStop()                              //Stop robot Quickly 
{
  analogWrite(ENA,HIGH); analogWrite(ENB,HIGH); digitalWrite(LN1,HIGH); digitalWrite(LN2,HIGH); digitalWrite(LN3,HIGH); digitalWrite(LN4,HIGH); 
  delay(120);
  analogWrite(ENA,0); analogWrite(ENB,0); digitalWrite(LN1,LOW); digitalWrite(LN2,LOW); digitalWrite(LN3,LOW); digitalWrite(LN4,LOW);
}

void TurnLeft(int M_speed)       // Move robot Foward with given Speed ** rightSpeed - speed for Right motor, LeftSpeed - speed for Left motor
{
  analogWrite(ENA,M_speed); analogWrite(ENB,M_speed); digitalWrite(LN1,LOW); digitalWrite(LN2,HIGH); digitalWrite(LN3,HIGH); digitalWrite(LN4,LOW); 
}
void TurnRight(int M_speed)       // Move robot Foward with given Speed ** rightSpeed - speed for Right motor, LeftSpeed - speed for Left motor
{
  analogWrite(ENA,M_speed); analogWrite(ENB,M_speed); digitalWrite(LN1,HIGH); digitalWrite(LN2,LOW); digitalWrite(LN3,LOW); digitalWrite(LN4,HIGH); 
}

void TurnLeft_single(int M_speed)       // Move robot Foward with given Speed ** rightSpeed - speed for Right motor, LeftSpeed - speed for Left motor
{
 
  analogWrite(ENA,0); analogWrite(ENB,M_speed); digitalWrite(LN1,LOW); digitalWrite(LN2,LOW); digitalWrite(LN3,HIGH); digitalWrite(LN4,LOW);

}
void TurnRight_single(int M_speed)       // Move robot Foward with given Speed ** rightSpeed - speed for Right motor, LeftSpeed - speed for Left motor
{

     analogWrite(ENA,M_speed); analogWrite(ENB,0); digitalWrite(LN1,HIGH); digitalWrite(LN2,LOW); digitalWrite(LN3,LOW); digitalWrite(LN4,LOW); 
}


void RobotTurnRight() {

  knobRight.write(0);
  knobLeft.write(0);
  while (abs(knobRight.read()) + abs(knobLeft.read()) < 400) {
    TurnRight(200);
  }
  robotHardStop();
  robotStop();
  //while(1);
  while (1) {
    updateSensors();
    TurnRight(80);
    if (( f_panel[6] == 1 && f_panel[7] == 1) || ( f_panel[7] == 1 && f_panel[8] == 1))break;
  }
  robotHardStop();
  robotStop();
  //smooth();
}

void RobotTurnRight180() {

  knobRight.write(0);
  knobLeft.write(0);
  while (abs(knobRight.read()) + abs(knobLeft.read()) < 950) {
    TurnRight(255);
  }
  robotStop();
  //robotHardStop();
  while (1) {
    updateSensors();
    TurnRight(100);
    if (S7_flg == 1)break;
    //if(S7_flg==1 && S6_flg==1)break;
  }
  // SetDirection(3);
  robotHardStop();
  robotStop();
  //smooth();
}
void RobotTurnLeft()
{
  knobRight.write(0);
  knobLeft.write(0);
  while (abs(knobRight.read()) + abs(knobLeft.read()) < 400) {
    TurnLeft(200);
  }
  robotStop();
 robotHardStop();
 // while(1);
  while (1) {
    updateSensors();
    TurnLeft(80);
    if (( f_panel[7] == 1 && f_panel[8] == 1) || ( f_panel[8] == 1 && f_panel[9] == 1) )break;
  }
  robotHardStop();
  robotStop();
 // while(1);
  //smooth();
}

void RobotTurnLeft180()
{

  knobRight.write(0);
  knobLeft.write(0);
  while (abs(knobRight.read()) + abs(knobLeft.read()) < 1900) {
    TurnLeft(255);
  }
  robotHardStop();
  robotStop();
  //while(1);
  //smooth();
}


 
////////////////////////////////////////////////////////wall//////////////////////////////////////////////////////////////////////

void RobotTurnLeft_single()
{
  
  knobRight.write(0);
  knobLeft.write(0);
  while(abs(knobRight.read() <1050)){TurnLeft_single(100);}
  robotHardStop();

  robotHardStop();
  robotStop();
  
}

void RobotTurnLeft_single_1()
{
  
  knobRight.write(0);
  knobLeft.write(0);
  while(abs(knobRight.read() <1300)){TurnLeft_single(100);}
  robotHardStop();

  robotHardStop();
  robotStop();
  
}


 void RobotTurnRight_single()
{
  
  knobRight.write(0);
  knobLeft.write(0);
  while(abs(knobLeft.read() <1050)){TurnRight_single(100);}
  robotHardStop();
 
  //robotHardStop();
  robotStop();
 // while(1);
}


void RobotTurnLeft_wall()
{
  knobRight.write(0);
  knobLeft.write(0);
  while (abs(knobRight.read()) + abs(knobLeft.read()) < 1000) {
    TurnLeft(100);
  }
  robotStop();
 robotHardStop();
 // while(1);
 
 
  //smooth();
}




void RobotTurnRight_wall() {

  knobRight.write(0);
  knobLeft.write(0);
  while (abs(knobRight.read()) + abs(knobLeft.read()) < 1000) {
    TurnRight(100);
  }
  robotHardStop();
  robotStop();
  //while(1);
  
 
  //smooth();
}

void RobotTurnLeft180_wall()
{

  knobRight.write(0);
  knobLeft.write(0);
  while (abs(knobRight.read()) + abs(knobLeft.read()) < 2200) {
    TurnLeft(100);
  }
  robotHardStop();
  robotStop();
  //vwhile(1);
  //smooth();
}

void RobotTurnRight_SP() {

  int variable=0;
  knobRight.write(0);
  knobLeft.write(0);
  
  while (1) {
    TurnRight(200);
    variable= abs(knobRight.read())+ abs(knobLeft.read());
    if ( variable> 400){break;}
  }
  //while(1);
  while (1) {
    updateSensors();
    TurnRight(80);
    if (( f_panel[2] == 1 && f_panel[3] == 1) || ( f_panel[3] == 1 && f_panel[4] == 1))break;
  }
  robotHardStop();
  robotStop();
  //smooth();
}

void RobotTurnLeft_SP() {

  int variable=0;
  knobRight.write(0);
  knobLeft.write(0);
  
  while (1) {
    TurnLeft(200);
    variable= abs(knobRight.read())+ abs(knobLeft.read());
    if ( variable> 400){break;}
  }
  //while(1);
  while (1) {
    updateSensors();
    TurnLeft(80);
    if (( f_panel[13] == 1 && f_panel[12] == 1) || ( f_panel[12] == 1 && f_panel[11] == 1))break;
  }
  robotHardStop();
  robotStop();
  //smooth();
}




