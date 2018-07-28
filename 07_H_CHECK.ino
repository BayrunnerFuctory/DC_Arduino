bool horizon_check_right(){
  bool result;
  bool h1;
  bool h2;

  h1 = get_di(horizon1_in);
  h2 = get_di(horizon2_in);

  if(h1==false && h2==true){
    result = true;
    out_do(led3,'L');
    out_do(led4,'H');
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
    out_do(led3,'H');
    out_do(led4,'L');
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
    out_do(led3,'H');
    out_do(led4,'H');
  }else if(h1==false && h2==false){
    result = true;
    out_do(led3,'L');
    out_do(led4,'L');
  }else{
    result = false;
  }


  return result;
}

