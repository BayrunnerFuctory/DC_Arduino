bool vertical_check_up(){
  bool result;
  bool v1;
  bool v2;

  v1 = get_di(vertical1_in);
  v2 = get_di(vertical2_in);

  if(v1==false && v2==true){
    result = true;
    led_off(led1);
    led_on(led2);
  }else{
    result = false;
  }
  
  return result;
}

bool vertical_check_down(){
  bool result;
  bool v1;
  bool v2;

  v1 = get_di(vertical1_in);
  v2 = get_di(vertical2_in);
  
 if(v1==true && v2==false){
    result = true;
    led_on(led1);
    led_off(led2);
  }else{
    result = false;
  }

  return result;
}

bool vertical_check_other(){
  bool result;
  bool v1;
  bool v2;

  v1 = get_di(vertical1_in);
  v2 = get_di(vertical2_in);
  
 if(v1==true && v2==true){
    result = true;
    led_on(led1);
    led_on(led2);
  }else if(v1==false && v2==false){
     result = true;
     led_off(led1);
     led_off(led2);
  }else{
    result = false;
  }  
  return result;
}

