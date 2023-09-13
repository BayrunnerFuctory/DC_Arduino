int Camera1_surbo1=A5;
int Camera1_surbo2=A1;
int Camera1_motor=13;
int Camera1_PWM=6;       //キャメラ１PWM制御設定
int Camera1_seiten=0;
int Camera1_gyaten=0;
int Camear1_current_PWM=0;
int Camera2_surbo1=A2;
int Camera2_surbo2=A3;
int Camera2_motor=11;
int Camera2_PWM=20;       //キャメラ２PWM制御設定
int Camera2_seiten=0;
int Camera2_gyaten=0;
int Camear2_current_PWM=0;
int Arm_surbo=A0;
int Arm_surbo_output=10;
int Arm_current_PWM=0;
int Arm_condition;
int Arm_PWM=20;
int max_PMW=255;  //PWM制御最大値
int min_PWM=0;    //PWM制御最小値
void Camera1_PWM_control(){
  Camera1_seiten=digitalRead(Camera1_surbo1);
  Camera1_gyaten=digitalRead(Camera1_surbo2);
    //正転で最大値を超えたら止まる
    if(Camera1_seiten==0 && Camera1_gyaten==1 && Camear1_current_PWM<max_PMW){
      //digitalWrite(LED,HIGH);
        Camear1_current_PWM=Camear1_current_PWM+Camera1_PWM;
      analogWrite(Camera1_motor,Camear1_current_PWM);
    }
    //逆転で最小値になったら止まる
    else if (Camera1_seiten==1 && Camera1_gyaten==0 && Camear1_current_PWM >min_PWM) {
    Camear1_current_PWM=Camear1_current_PWM-Camera1_PWM;
      analogWrite(Camera1_motor,Camear1_current_PWM);
    }
    else{
      Camear1_current_PWM=Camear1_current_PWM;
    }
}
void Camera2_PWM_control(){
  Camera2_seiten=digitalRead(Camera2_surbo1);
  Camera2_gyaten=digitalRead(Camera2_surbo2);
    //正転で最大値を超えたら止まる
    if(Camera2_seiten==0 && Camera2_gyaten==1 && Camear2_current_PWM<max_PMW){
        Camear2_current_PWM=Camear2_current_PWM+Camera2_PWM;
      analogWrite(Camera2_motor,Camear2_current_PWM);
    }
    //逆転で最小値になったら止まる
    else if (Camera2_seiten==1 && Camera2_gyaten==0 && Camear2_current_PWM >min_PWM) {
    Camear2_current_PWM=Camear2_current_PWM-Camera2_PWM;
      analogWrite(Camera2_motor,Camear2_current_PWM);
    }
    else{
      //digitalWrite(LED,LOW);
      Camear2_current_PWM=Camear2_current_PWM;
    }
}
void Arm_servo_control(){
  if (digitalRead(Arm_surbo)==0 ){
    if (Arm_condition=0){
    }
          Arm_current_PWM=Arm_current_PWM+Arm_PWM;
          analogWrite(Arm_surbo_output,Arm_current_PWM); 
          Arm_condition=1;
  }
  else{
    Arm_current_PWM=0; 
     analogWrite(Arm_surbo_output,Arm_current_PWM); 
    //Arm_condition=0;
  }
}
void setup() {
   // ピンの入力
  pinMode(Arm_surbo,INPUT_PULLUP);
  pinMode(Camera1_surbo1,INPUT_PULLUP);
  pinMode(Camera1_surbo2,INPUT_PULLUP);
  pinMode(Camera1_surbo2,INPUT_PULLUP);
  //ピンの出力
  pinMode(Camera1_motor,OUTPUT);
  pinMode(Camera2_motor,OUTPUT);
  pinMode(Arm_surbo_output,OUTPUT);
}
void loop() {
  //main 処理
  while(1){
    Camera1_PWM_control();
    Camera2_PWM_control();
    Arm_servo_control();
    delay(10);
  }
}

