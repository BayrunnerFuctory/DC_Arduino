//入力信号PIN設定
int LS1 =10;
int LS2 =A3;
int Zigbee=A2;
int Stop_Mode=12;
int Right_DC1=13;
int Right_DC2=14;
int Left_DC1=15;
int Left_DC2=16;
//LS入力初期値
int input_LS1=0;
int input_LS2=0;
//Zigbee入力初期値
int input_Zigbee=0;
void setup() {
  // 入力出力設定
  pinMode(LS1,INPUT_PULLUP);
  pinMode(LS2,INPUT_PULLUP);
  pinMode(input_Zigbee,INPUT_PULLUP);
  pinMode(Stop_Mode,OUTPUT);
  pinMode(Right_DC1,OUTPUT);
  pinMode(Right_DC2,OUTPUT);
  pinMode(Left_DC1,OUTPUT);
  pinMode(Left_DC2,OUTPUT);
}
void loop() {
 // Zigbee 信号ONまで待つ
  while(1){
    if (digitalRead(input_Zigbee)==0){
      digitalWrite(Stop_Mode, HIGH); 
      break;
    }  
  }
  //Runモード制御
  while(1){
    //待機する
    digitalWrite(Stop_Mode, LOW); 
    int currentLeftLS=digitalRead(LS1);
    int currentRightLS=digitalRead(LS2);
    int c=5;                //SWを押すカウンター
    //chattering filter
    int SW1data[5]={-1,-1,-1,-1,-1};
    int SW2data[5]={-1,-1,-1,-1,-1};
    int LeftLScnt;
    int RightLScnt;
    int check;
    int cnt;
    cnt=LeftLScnt/3;
    if(LeftLScnt==0){
      SW1data[0]=digitalRead(LS1);
      SW1data[1]=digitalRead(LS1);
      SW1data[2]=digitalRead(LS1);
      SW1data[3]=digitalRead(LS1);
      SW1data[4]=digitalRead(LS1);
    }
    if(LeftLScnt==1){
      SW1data[0]=digitalRead(LS1);
      SW1data[1]=digitalRead(LS1);
      SW1data[2]=digitalRead(LS1);
      SW1data[3]=digitalRead(LS1);
      SW1data[4]=digitalRead(LS1);
    }
    if(LeftLScnt==2){
      SW1data[0]=digitalRead(LS1);
      SW1data[1]=digitalRead(LS1);
      SW1data[2]=digitalRead(LS1);
      SW1data[3]=digitalRead(LS1);
      SW1data[4]=digitalRead(LS1);
    }
    check=SW1data[0]+SW1data[1]+SW1data[2]+SW1data[3]+SW1data[4];
    if(check >=4){
      SW1data[0] >>1;
      currentLeftLS=1;
    }
    // LS1もしくはLS2が押された場合停止モードがONになる
    bool isLimitSwitchOn=GetFrontLimitSwitch(currentLeftLS,currentRightLS);
     if (isLimitSwitchOn){
       digitalWrite(Stop_Mode,LOW);
      break;
      }
     else{
        digitalWrite(Right_DC1,LOW);
        digitalWrite(Right_DC2,HIGH);
        digitalWrite(Left_DC1,HIGH);
        digitalWrite(Left_DC2,LOW);
        break;
     }  
  }
  //停止
  digitalWrite(Stop_Mode,HIGH); 
  //リセットボタンを押すまで待つ
}


