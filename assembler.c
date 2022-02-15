#include <stdio.h>
#include "assemblatore.h"

int main(int argc, char *argv[]){  
    
  if(argv[1] == " " || argv[1] == NULL){
    printf("file non inserito. riprovare.");
    return 0;
  }
  toAssembly(argv);  
  return 0;
}
