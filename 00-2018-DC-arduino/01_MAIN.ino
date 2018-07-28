void mainloop() {
  bool offErr = true;
  //Main Loop(ENDLESS)
  //NoError Loop
  while (offErr) {
    if (mainmetro.check() == 1 ) {
      //mainloop
      offErr = verticalmotor();
      if (horizontalmode == true) {
        offErr = horizontalmotor();
      }
    }
  }

  //Error Loop
  while (1){
    delay(500);
    out_do(led1, 'H');
    out_do(led2, 'H');
    out_do(led3, 'H');
    out_do(led4, 'H');
    delay(500);
    out_do(led1, 'L');
    out_do(led2, 'L');
    out_do(led3, 'L');
    out_do(led4, 'L'); 
  }
}

//verticalmotor check&move
bool verticalmotor() {
  bool offErr = true;
  if (vertical_check_other() == false) {
    if (vertical_check_up() == true) {
      vertical_moter_out('u');
    } else if (vertical_check_down() == true) {
      vertical_moter_out('d');
    } else {
      offErr = false;
    }
  } else {
    vertical_moter_out('s');
  }
  return offErr;
}

//horizontalmotor check&move
bool horizontalmotor() {
  bool offErr = true;
  if (horizon_check_other() == false) {
    if (horizon_check_right() == true) {
      horizon_moter_out('r');
    } else if (horizon_check_left() == true) {
      horizon_moter_out('l');
    } else {
      offErr = false;
    }
  } else {
    horizon_moter_out('s');
  }
  return offErr;
}

