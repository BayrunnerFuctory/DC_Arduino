void led_on(int lednum){
  out_do(lednum,'H');
}

void led_off(int lednum){
  out_do(lednum,'L');
}

