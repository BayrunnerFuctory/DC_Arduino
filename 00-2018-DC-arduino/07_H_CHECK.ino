bool horizon_check_right(){
  bool result;
  bool h1;
  bool h2;

  h1 = get_di(horizon1_in);
  h2 = get_di(horizon2_in);

  if(h1==false && h2==true){
    result = true;
    led_off(led3);
    led_on(led4);
  }else{
    result = false;
  }
  
  return result;
}

bool horizon_check_left(){
  bool result;
  bool h1;
  bool h2;

  h1 = get_di(horizon1_in);
  h2 = get_di(horizon2_in);

  if(h1==true && h2==false){
    result = true;
    led_on(led3);
    led_off(led4);
  }else{
    result = false;
  }


  return result;
}

bool horizon_check_other(){
  bool result;
  bool h1;
  bool h2;

  h1 = get_di(horizon1_in);
  h2 = get_di(horizon2_in);
  
 if(h1==true && h2==true){
    result = true;
    led_on(led3);
    led_on(led4);
  }else if(h1==false && h2==false){
    result = true;
    led_off(led3);
    led_off(led4);
  }else{
    result = false;
  }


  return result;
}

