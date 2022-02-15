#include "cinstr.h"
#include "ainstr.h"
#include <string.h>

void jump(char jump[], int out[]){
  int i = 0;
  int found = 0;
  while(i < strlength(jump) && found == 0){
    if(jump[i] == 'J'){
      found = 1;
    } else{
      i++;
    }
  }

  if (found == 1){
    if(jump[i + 1] == 'G'){
        out[13] = 0;
        out[15] = 1;
      if(jump[i + 2] == 'E'){
        out[14] = 1;
      } else if(jump[i + 2] == 'T'){
        out[14] = 0;
      }
    } else if(jump[i + 1] == 'L'){
          out[13] = 1;
          out[15] = 0;
        if(jump[i + 2] == 'E'){
          out[14] = 1;
        } else if(jump[i + 2] == 'T'){
          out[14] = 0;
        }
    } else if(jump[i + 1] == 'E'){
        out[13] = 0;
        out[14] = 1;
        out[15] = 0;
    } else if(jump[i + 1] == 'N'){
        out[13] = 1;
        out[14] = 0;
        out[15] = 1;
    } else if(jump[i + 1] == 'M'){
        out[13] = 1;
        out[14] = 1;
        out[15] = 1;
    }
  } else {
    out[13] = 0;
    out[14] = 0;
    out[15] = 0;
  }
}

int cerca_simbol(char sym[], char symbol){
  int i = 0;
  int found = 0;
  while(found == 0 && sym[i] != '\0'){
    if(sym[i] == symbol){      
      found = 1;
    } else{
      i++;
    }
  }
  return i;
}

void computation_eq(char comp[], int out[], int length){
  int i = 0;
  int k = 0;
  int j = 0;
  char simboli[5];
  int found = 0;
  strcpy(simboli, "+-&|");
  i = cerca_simbol(comp, '=');
  
  if(cerca_simbol(comp, ';') < strlength(comp)){
	   i = -1;
  }
  
  while(comp[k] != '\0' && found == 0 && j < 5 && comp[k] != ';'){    
    if((cerca_simbol(comp, simboli[j])) < strlength(comp) && comp[k] != ' '){  
      found = 1;   
    } else {        
      k++;
      j++;
    }
  }
  
  if(found == 0){
    if(comp[i + 1] == '!' || comp[i+2] == '!' && comp[i+1] == ' '){
      if(comp[i + 2] == 'D'|| comp[i+3]== 'D'  && comp[i+1] == ' '){
        out[3] = 0;
        out[4] = 0;
        out[5] = 0;
        out[6] = 1;
        out[7] = 1;
        out[8] = 0;
        out[9] = 1;
      }else if(comp[i + 2] == 'A'|| comp[i+3]== 'A'  && comp[i+1] == ' '){
        out[3] = 0;
        out[4] = 1;
        out[5] = 1;
        out[6] = 0;
        out[7] = 0;
        out[8] = 0;
        out[9] = 1;
      } else if(comp[i + 2] == 'M'|| comp[i+3]== 'M'  && comp[i+1] == ' '){
        out[3] = 1;
        out[4] = 1;
        out[5] = 1;
        out[6] = 0;
        out[7] = 0;
        out[8] = 0;
        out[9] = 1;
      }
    }else if(comp[i+1] == '0' || comp[i+2] == '0' && comp[i+1] == ' '){
      out[3] = 0;
      out[4] = 1;
      out[5] = 0;
      out[6] = 1;
      out[7] = 0;
      out[8] = 1;
      out[9] = 0;
    }else if(comp[i + 1] == '1' || comp[i+2] == '1' && comp[i+1] == ' '){
      out[3] = 0;
      out[4] = 1;
      out[5] = 1;
      out[6] = 1;
      out[7] = 1;
      out[8] = 1;
      out[9] = 1;
    }
    else if(comp[i + 1] == 'A' || comp[i+2] == 'A' && comp[i+1] == ' '){
      out[3] = 0;
      out[4] = 1;
      out[5] = 1;
      out[6] = 0;
      out[7] = 0;
      out[8] = 0;
      out[9] = 0;
    }
    else if(comp[i + 1] == 'M' || comp[i+2] == 'M' && comp[i+1] == ' '){
      out[3] = 1;
      out[4] = 1;
      out[5] = 1;
      out[6] = 0;
      out[7] = 0;
      out[8] = 0;
      out[9] = 0;
    }else if(comp[i + 1] == 'D' || comp[i+2] == 'D' && comp[i+1] == ' '){
      out[3] = 0;
      out[4] = 0;
      out[5] = 0;
      out[6] = 1;
      out[7] = 1;
      out[8] = 0;
      out[9] = 0;
    }
  } else if(found == 1){    
    if(comp[i + 1] == 'A' || comp[i+2] == 'A' && comp[i+1] == ' '){
      if(comp[i + 2] == '-' || comp[i+4] == '-' && comp[i+3] == ' '){
        if(comp[i + 3] == 'D' || comp[i+6] == 'D' && comp[i+5] == ' '){
          out[3] = 0;
          out[4] = 0;
          out[5] = 0;
          out[6] = 0;
          out[7] = 1;
          out[8] = 1;
          out[9] = 1;
        } else if (comp[i + 3] == '1' || comp[i+6] == '1' && comp[i+5] == ' '){
          out[3] = 0;
          out[4] = 1;
          out[5] = 1;
          out[6] = 0;
          out[7] = 0;
          out[8] = 1;
          out[9] = 0;
        }
      }else if(comp[i + 2] == '+' || comp[i+4] == '+' && comp[i+3] == ' '){
        if (comp[i + 3] == '1' || comp[i+6] == '1' && comp[i+5] == ' '){
            out[3] = 0;
            out[4] = 1;
            out[5] = 1;
            out[6] = 0;
            out[7] = 1;
            out[8] = 1;
            out[9] = 1;
          }
      }
    } else if(comp[i + 1] == 'D' || comp[i+2] == 'D' && comp[i+1] == ' '){
    if(comp[i + 2] == '-' || comp[i+4] == '-' && comp[i+3] == ' '){
        if(comp[i + 3] == 'A' || comp[i+6] == 'A' && comp[i+5] == ' '){
          out[3] = 0;
          out[4] = 0;
          out[5] = 1;
          out[6] = 0;
          out[7] = 0;
          out[8] = 1;
          out[9] = 1;
        } else if (comp[i + 3] == '1' || comp[i+6] == '1' && comp[i+5] == ' '){
          out[3] = 0;
          out[4] = 0;
          out[5] = 0;
          out[6] = 1;
          out[7] = 1;
          out[8] = 1;
          out[9] = 0;
        }else if (comp[i + 3] == 'M' || comp[i+6] == 'M' && comp[i+5] == ' '){
          out[3] = 1;
          out[4] = 0;
          out[5] = 1;
          out[6] = 0;
          out[7] = 0;
          out[8] = 1;
          out[9] = 1;
        }
	  }else if(comp[i + 2] == '+' || comp[i+4] == '+' && comp[i+3] == ' '){
		 if(comp[i + 3] == 'A' || comp[i+6] == 'A' && comp[i+5] == ' '){
          out[3] = 0;
          out[4] = 0;
          out[5] = 0;
          out[6] = 0;
          out[7] = 0;
          out[8] = 1;
          out[9] = 0;
        }else if(comp[i + 3] == 'M' || comp[i+6] == 'M' && comp[i+5] == ' '){
          out[3] = 1;
          out[4] = 0;
          out[5] = 0;
          out[6] = 0;
          out[7] = 0;
          out[8] = 1;
          out[9] = 0;
        }else if(comp[i + 3] == '1' || comp[i+6] == '1' && comp[i+5] == ' '){
          out[3] = 0;
          out[4] = 0;
          out[5] = 1;
          out[6] = 1;
          out[7] = 1;
          out[8] = 1;
          out[9] = 1;
       }
	}else if(comp[i + 2] == '&' || comp[i+4] == '&' && comp[i+3] == ' '){
	  if(comp[i + 3] == 'A' || comp[i+6] == 'A' && comp[i+5] == ' '){
          out[3] = 0;
          out[4] = 0;
          out[5] = 0;
          out[6] = 0;
          out[7] = 0;
          out[8] = 0;
          out[9] = 0;
        }else if(comp[i + 3] == 'M' || comp[i+6] == 'M' && comp[i+5] == ' '){
          out[3] = 1;
          out[4] = 0;
          out[5] = 0;
          out[6] = 0;
          out[7] = 0;
          out[8] = 0;
          out[9] = 0;
        }
	}else if(comp[i + 2] == '|' || comp[i+4] == '|' && comp[i+3] == ' '){
	  if(comp[i + 3] == 'A' || comp[i+6] == 'A' && comp[i+5] == ' '){
          out[3] = 0;
          out[4] = 0;
          out[5] = 1;
          out[6] = 0;
          out[7] = 1;
          out[8] = 0;
          out[9] = 1;
        }else if(comp[i + 3] == 'M' || comp[i+6] == 'M' && comp[i+5] == ' '){
          out[3] = 1;
          out[4] = 0;
          out[5] = 1;
          out[6] = 0;
          out[7] = 1;
          out[8] = 0;
          out[9] = 1;
        }
	}
  

    }else if(comp[i + 1] == 'M' || comp[i+2] == 'M' && comp[i+1] == ' '){
        if(comp[i + 2] == '+' || comp[i+4] == '+' && comp[i+3] == ' '){
        if(comp[i + 3] == '1' || comp[i+6] == '1' && comp[i+5] == ' '){
      out[3] = 1;
      out[4] = 1;
      out[5] = 1;
      out[6] = 0;
      out[7] = 1;
      out[8] = 1;
      out[9] = 1;
}
        }else if(comp[i + 2] == '-' || comp[i+4] == '-' && comp[i+3] == ' '){
if(comp[i + 3] == '1' || comp[i+6] == '1' && comp[i+5] == ' '){
      out[3] = 1;
      out[4] = 1;
      out[5] = 1;
      out[6] = 0;
      out[7] = 0;
      out[8] = 1;
      out[9] = 0;
}else if(comp[i + 3] == 'D' || comp[i+6] == 'D' && comp[i+5] == ' '){
      out[3] = 1;
      out[4] = 0;
      out[5] = 0;
      out[6] = 0;
      out[7] = 1;
      out[8] = 1;
      out[9] = 1;
}
}
    } else if(comp[i + 1] == '-' || comp[i+2] == '-' && comp[i+1] == ' '){   
      if(comp[i+2] == '1' ||comp[i+3] == '1'){
          out[3] = 0;
          out[4] = 1;
          out[5] = 1;
          out[6] = 1;
          out[7] = 0;
          out[8] = 1;
          out[9] = 0;
      }else if(comp[i+2] == 'D' || comp[i+3] == 'D'){
          out[3] = 0;
          out[4] = 0;
          out[5] = 0;
          out[6] = 1;
          out[7] = 1;
          out[8] = 1;
          out[9] = 1;
      }else if(comp[i+2] == 'A' || comp[i+3] == 'A'){
          out[3] = 0;
          out[4] = 1;
          out[5] = 1;
          out[6] = 0;
          out[7] = 0;
          out[8] = 1;
          out[9] = 1;
      }else if(comp[i+2] == 'M' || comp[i+3] == 'M'){
          out[3] = 1;
          out[4] = 1;
          out[5] = 1;
          out[6] = 0;
          out[7] = 0;
          out[8] = 1;
          out[9] = 1;
      }
 }
 }
}


void dest(char dest[], int out[]){
  if(dest[1] == '=' || dest[2] == '=' && dest[1] == ' '){
    if(dest[0] == 'A'){
      out[10] = 1;
      out[11] = 0;
      out[12] = 0;
    } else if(dest[0] == 'M'){
      out[10] = 0;
      out[11] = 0;
      out[12] = 1;
    } else if(dest[0] == 'D'){
      out[10] = 0;
      out[11] = 1;
      out[12] = 0;
    }
  } else if(dest[2] == '=' || dest[3] == '=' && dest[2] == ' '){
    if(dest[0] == 'A'){
      out[10] = 1;
      if(dest[1] == 'M'){
        out[11] = 0;
        out[12] = 1;
      } else if(dest[1] == 'D'){
        out[11] = 1;
        out[12] = 0;
      }
    } else if(dest[0] == 'M'){
      out[10] = 0;
      out[11] = 1;
      out[12] = 1;
    }
  } else if(dest[3] == '=' || dest[4] == '=' && dest[3] == ' '){
    out[10] = 1;
    out[11] = 1;
    out[12] = 1;
  } else if(cerca_simbol(dest, ';') < strlength(dest)){
    out[10] = 0;
    out[11] = 0;
    out[12] = 0;
  }
}

void crea_instruction(char instruction[], FILE* fout){
  int length = 16;
  int out[length];
  out[0] = 1;
  out[1] = 1;
  out[2] = 1;
  jump(instruction, out);
  dest(instruction, out);
  computation_eq(instruction, out, length);
  //for(int k = 0; k < length; k++){
  //   printf("\n K : %d -> %d \n", k, out[k]);
  // }
  output_file(out, length, fout);
}