void vertical_moter_out(char uds){

  switch(uds){
    
    case 'u':
      out_do(vertical1_out,'L');
      out_do(vertical2_out,'H');
    break;

    case 'd':
      out_do(vertical1_out,'H');
      out_do(vertical2_out,'L');
    break;

    case 's':
      out_do(vertical1_out,'H');
      out_do(vertical2_out,'H');
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
      out_do(horizon2_out,'H');
    break;

    case 'l':
      out_do(horizon1_out,'H');
      out_do(horizon2_out,'L');
    break;

    case 's':
      out_do(horizon1_out,'H');
      out_do(horizon2_out,'H');
    break;

    default:
      //nothing
    break;
    
  }
  
}

