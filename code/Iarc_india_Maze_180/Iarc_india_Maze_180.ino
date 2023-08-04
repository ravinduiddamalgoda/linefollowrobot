#include <QTRSensors.h>
#include <Encoder.h>
#include <NewPing.h>
#include <EEPROM.h>
#include <SharpIR.h>
#include <LiquidCrystal.h>

#define irL  A6  // ir sharp
#define model 430
#define model_1 1080
#define model_2 20150
#define irR  A1  // ir sharp

#define r_lim 11
#define c_lim 12
#define l_lim 10

#define s1 A8
#define s2 A9
#define s3 A10

#define NUM_SENSORS   8     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2


char path[30] = {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'};
char path_array[30] = {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'};

int path_length = 0;
int arrayCnt = 0;
int ii = 0;
int myCnt = 0;
unsigned short pathIndex = 0;

int wall_cnt = 0;

int f_panel[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int x_panel[8] = {0, 0,0, 0,0, 0,0, 0};
//int ex_panel[]={0,0,0,0,0,0,0,0};
// sensors 0 through 7 are connected to digital pins 3 through 10, respectively
/*QTRSensorsRC qtrrcBack((unsigned char[])
  {
  22, 24, 26, 28, 30, 32, 34, 36
  }, NUM_SENSORS, TIMEOUT, EMITTER_PIN);
  unsigned int sensorValuesBack[NUM_SENSORS];
  unsigned int f_panel[8];
*/
const int rs = 52, en = 50, d4 = 48, d5 = 46, d6 = 44, d7 = 42;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define ENA 5  // ENable Left
#define LN1 29// l_f
#define LN2 27 //l_b
#define ENB 4 //right motor
#define LN3 25  //r_f
#define LN4 23 //r_b

int RLED =  11;
int GLED1 = 13;
int GLED2 = 9;
int BUZZ = 8;

int sCnt;
int lCnt;
int rCnt;


int S0_flg = 0; //right corner
int S1_flg = 0;
int S2_flg = 0;
int S3_flg = 0;
int S4_flg = 0;
int S5_flg = 0;
int S6_flg = 0;
int S7_flg = 0;

int error;
int Last_Error;
int sum;
int BS =  180;
int BS_1 =  100;
int SPEEDR;
int SPEEDL;

int errorSum;
int LastError;
int dis_f;
int dis_r;
int dis_RF;
int dis_LF;
int dis_l;
int dis_c;
int wall_s =  150;
int x = 0;
boolean wall_1st = false;
int wall_left = 0;
int wall_right = 0;
int wall_center = 0;

char current_wall = 'X';

long duration, cm_l, cm_r, inches;


boolean nd = false;
float dis_cal = 0;
int tn=0;
int fn=0;

Encoder knobLeft(2, 3);      // interrupts
Encoder knobRight(21, 20);    // interrupts

long positionLeft  = -999;
long positionRight = -999;


SharpIR SharpL(irL, model);
SharpIR SharpR(irR, model);
SharpIR SharpR_f(A11, model_1);
SharpIR Sharpl_f(A2, model_1);
SharpIR Sharp_f(A7, model);

#define TRIGGER_PINR 33  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PINR     7 // Arduino pin tied to echo pin on the ultrasonic sensor.
#define TRIGGER_PINL 31
#define ECHO_PINL    6
//#define TRIGGER_PINM 38
//#define ECHO_PINM    12

//NewPing sonarR(TRIGGER_PINR, ECHO_PINR, 100);
//NewPing sonarL(TRIGGER_PINL, ECHO_PINL, 100);
//NewPing sonarM(TRIGGER_PINM, ECHO_PINM, 100);

void setup() {

  pinMode(f_panel[0], INPUT); pinMode(f_panel[1], INPUT); pinMode(f_panel[2], INPUT); pinMode(f_panel[3], INPUT); pinMode(f_panel[4], INPUT); pinMode(f_panel[5], INPUT); pinMode(f_panel[6], INPUT); pinMode(f_panel[7], INPUT); pinMode(f_panel[8], INPUT); pinMode(f_panel[9], INPUT); pinMode(f_panel[10], INPUT); pinMode(f_panel[11], INPUT); pinMode(f_panel[12], INPUT); pinMode(f_panel[13], INPUT); pinMode(f_panel[14], INPUT); pinMode(f_panel[15], INPUT); // IR inputs
  pinMode(ENA, OUTPUT); // motors
  pinMode(ENB, OUTPUT);
  pinMode(LN1, OUTPUT);
  pinMode(LN2, OUTPUT);
  pinMode(LN3, OUTPUT);
  pinMode(LN4, OUTPUT);
  pinMode(37, INPUT);
  pinMode(33, INPUT);
  pinMode(35, INPUT);
  Serial.begin(9600);

  pinMode(RLED, OUTPUT);
  pinMode(GLED1, OUTPUT);
  pinMode(GLED2, OUTPUT);
  pinMode(BUZZ, OUTPUT);

  pinMode(r_lim, INPUT);
  pinMode(l_lim, INPUT);
  pinMode(c_lim, INPUT);

  pinMode(TRIGGER_PINR, OUTPUT);
  pinMode(ECHO_PINR, INPUT);
  pinMode(TRIGGER_PINL, OUTPUT);
  pinMode(ECHO_PINL, INPUT);

  digitalWrite(TRIGGER_PINR, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIGGER_PINL, LOW);
  delayMicroseconds(5);
  lcd.begin(16, 2);

  lcd.print("MARK_50");

  //RobotTurnLeft_single();
  //robotHardStop();
  //while(1);
  //RobotTurnRight_single();

  while (1) {
     if (digitalRead(s1) == 0){
      delay(1000);
    New_maze_solve();
    delay(1);
    full_wall_follow();
    delay(1);
    smooth();
    task_3();
    robotHardStop();
     final_display();
    buzzer_end();
     
    break;
  }
  }


}
void loop() {
  
//smooth();
  // New_maze_solve();
 //updateSensors_x();
  //Update_dis_R ();
  // Update_dis_L ();
  // task_3();
  //ultra_dis_r();
  //smooth();
  calculateShortpath();
  /*
     if (digitalRead(s1) == 0){
      delay(1000);
      while(1){
      wall_f_f_right();}
    }
    if (digitalRead(s2) == 0){
      delay(1000);
      while(1) {
      wall_f_f_left();}
    }
    if (digitalRead(s3) == 0){
    delay(1000);
    while(1){
    New_maze_solve();
     }
    }
  */
}
//Update_dis_R ();
// wall_propotional_R();
