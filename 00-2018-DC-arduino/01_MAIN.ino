void mainloop(){
  //Main Loop(ENDLESS)
  while (1) {
    if (mainmetro.check() == 1 ) {
      //mainloop
      if (vertical_check_other() == false) {
        if (vertical_check_up() == true) {
          vertical_moter_out('u');
        } else if (vertical_check_down() == true) {
          vertical_moter_out('d');
        }
      } else {
        vertical_moter_out('s');
        if (horizontalmode == true) {
          if (horizon_check_other() == false) {
            if (horizon_check_right() == true) {
               horizon_moter_out('r');
            } else if (horizon_check_left() == true) {
              horizon_moter_out('l');
            }
          } else {
              horizon_moter_out('s');
          }
        }
      }
    }
  }  
}

