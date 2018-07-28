//include hedderfile
#include<Metro.h>
#include<Servo.h>

// Define pinname pinnum
#define horizon2_in 14 //A0 水平用入力1bit目
#define horizon1_in 15 //A1　水平用入力2bit目
#define vertical2_in 16 //A2　垂直用入力1bit目
#define vertical1_in 17 //A3　垂直用入力2bit目
//#define non 18 //A4
//#define non 19 //A5
//#define non A6 //Analog onry
//#define non A7 //Analog onry
//#define non 0 //D0
//#define non 1 //D1
#define led4 2 //D2
//#define non 3 //D3
#define led3 4 //D4
#define vertical2_out 5 //D5
#define vertical1_out 6 //D6
#define led2 7 //D7
#define led1 8 //D8
//#define non 9 //D9
//#define non 10 //D10
//#define non 11 //D11
#define horizon1_out 12 //D12
#define horizon2_out 13 //D13

// servo
//Noting Servo

//Mode Setting
//Testing Mode
bool testmode = false; //nomal=false; testingmode=true;
//Start delay Mode
bool startdelay = false; //nomal=false; delaymode=true;
//水平動作モード
bool horizontalmode = false; //horizontalmodeON=true; (nomal)OFF=false; 


//Metro Setting
//Main Loop Timer
Metro mainmetro = Metro(5); //Metro( ms );





void setup() {
  // put your setup code here, to run once:
  // set up pinmode
  //input
  pinMode(horizon1_in,INPUT);
  pinMode(horizon2_in,INPUT);
  pinMode(vertical1_in,INPUT);
  pinMode(vertical2_in,INPUT);
  //output
  pinMode(horizon1_out,OUTPUT);
  pinMode(horizon2_out,OUTPUT);
  pinMode(vertical1_out,OUTPUT);
  pinMode(vertical2_out,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  //start delay = ON is delay 用途不明
  if(startdelay){
    delay(500);
  }
  //if testmode = ON is goto TestLoop else MainLoop
  if(testmode){
    testloop();
  }else{
    mainloop();  
  }
  

}
