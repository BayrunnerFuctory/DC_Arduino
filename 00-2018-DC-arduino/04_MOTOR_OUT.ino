void vertical_moter_out(char uds){

  switch(uds){
    
    case 'u':
      out_do(vertical1_out,'L');
//      out_do(vertical2_out,'H');
      out_ao(vertical2_out);
    break;

    case 'd':
      out_ao(vertical1_out);
//      out_do(vertical1_out,'H');
      out_do(vertical2_out,'L');
    break;

    case 's':
      out_ao(vertical1_out);
      out_ao(vertical2_out);
//      out_do(vertical1_out,'H');
//      out_do(vertical2_out,'H');
    break;

    default:
      //nothing
    break;
    
  }
  
}

void horizon_moter_out(char rls){

    switch(rls){
    
    case 'r':
      out_do(horizon1_out,'L');
      out_ao(horizon2_out);
//      out_do(horizon2_out,'H');
    break;

    case 'l':
//      out_do(horizon1_out,'H');
      out_ao(horizon1_out);
      out_do(horizon2_out,'L');
    break;

    case 's':
      out_ao(horizon1_out);
      out_ao(horizon2_out);
//      out_do(horizon1_out,'H');
//      out_do(horizon2_out,'H');
    break;

    default:
      //nothing
    break;
    
  }
  
}


int Speed(int Speedper){

  int Speedmax = 255;
  int Speedmin = 0;
  int result = 0;
  
  result = Speedmax / (Speedper / 100);


  return result;  
}

