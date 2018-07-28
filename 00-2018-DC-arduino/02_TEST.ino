void testloop() {
  //Test Loop(ENDLESS)

  for (int i = 0; i <= 2 ; i++) {
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


  while (1) {
    if (mainmetro.check() == 1 ) {
      //mainloop
      if (vertical_check_other() == false) {
        Serial.println("vertical_other_false");
        if (vertical_check_up() == true) {
          Serial.println("Vertical_up");
//          vertical_moter_out('u');
        } else if (vertical_check_down() == true) {
          Serial.println("Vertical_down");
//          vertical_moter_out('d');
        }
      } else {
        Serial.println("Vertical_Stop");
//        vertical_moter_out('s');
        if (horizontalmode == true) {
          Serial.println("horizon_mode_ON");
          if (horizon_check_other() == false) {
            Serial.println("horizon_other_false");
            if (horizon_check_right() == true) {
              Serial.println("horizon_right");
//               horizon_moter_out('r');
            } else if (horizon_check_left() == true) {
              Serial.println("horizon_left");
//              horizon_moter_out('l');
            }
          } else {
            Serial.println("horizon_Stop");
//              horizon_moter_out('s');
          }
        }
      }
      delay(1000);
    }
  }
}


