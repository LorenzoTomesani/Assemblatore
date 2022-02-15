#include "assemblatore.h"
#include "ainstr.h"
#include "cinstr.h"

// NOME DA DARE AL FILE HACK.

void nome_output(char *str[], char out[], int length){
  int i = 0;
  while(str[1][i] != '.'){
    out[i] = str[1][i];
    i++;
  }
  char tipo[6] = ".hack";
  int j = 0;
  while(i <length && j<6){
    out[i] = tipo[j];
    j++;
    i++;
  }
}

// METODO PER LA LUNGHEZZA FILE.

int lunghezza_file(FILE *fout){
  int i = 0;
  char array[100];
  while(fgets(array, 100,fout)){    
    if(strlength(array)>0 && array[0] != '/'){
      i++;
    }
  }
  return i;
}

// METODO PER AVANZARE NEL FILE.
// RICONOSCE SE È STATO PRELEVATO QUALCOSA.

void advance(FILE* fin, char array[], int length){
    fgets(array, length, fin);
}

// QUALE COMANDO È STATO PRELEVATO DAL FILE ASM.

int commandType(char array[]){
  if(array[0] == '@'){
    if(array[1] >= '0' && array[1] <= '9'){
      return 0;
    } else {
      return 1;
    }
  } else if(array[0] == '('){
    return 1;
  } else if(array[0] == '/' && array[1] == '/'){
    return 2;
  } else {
    return 3;
  }
} // 0 per ainstr, 1 per labelinstr,2 per commenti, 3 per cinstr.

//metodo per eliminazione spazi all'inizio

void elimina_spazi(char array[]){
  int i = 0;
  int j = 0;
  while(array[i] != '\0' && array[0] == ' '){    
    j = 0; 
    while(array[j] != '\0'){    
      if(array[j] == '/' && array[j+1] == '/'){
        array[j] = '\0';
      }
      array[j] = array[j+1];
      j++;      
    }
    i++;      
  }  
  if(last_space(array, strlength(array)) == 1){
    int p = strlength(array);
    while(p>=0 && array[p-1] == ' '){
      p--;
    }
    array[p+1] = '\0';
  }
  
}

int last_space(char array[], int length){
  if(array[length -1] == ' '){
    return 1;
  } else {
    return 0;
  }
}

//METODO PER GENERALE IL FILE HACK.

void toAssembly(char *argv[]){
  int length = 85;
  char nome[length];

  FILE* fin;
  FILE* fout;


  nome_output(argv, nome, length);
  fin = fopen(argv[1], "r");
  fout = fopen(nome, "w");
  int lunghezza = lunghezza_file(fin);
  node_t Symbol = crea_lista();


  int i = 1;
  int value_var = 16;

  fclose(fin);
  fin = fopen(argv[1], "r");


  int number = 0;
  int n = lunghezza;



  //AGGIUNTA LABEL ALLA SYMBOL TABLE

  while(i<=n){
    char instruction[length];
    advance(fin, instruction, length);
    if(!(commandType(instruction) == 2)){
      if(instruction[0] == ' ' && strlength(instruction)>0){
        elimina_spazi(instruction);
      } 
      if(instruction[0] == '('){
        number = i - 1;      
        aggiungi_label(instruction, Symbol, number);
        n = n -1;
      } else if(strlength(instruction)>1){
        i++;
      }
    }
  }

  fclose(fin);
  fin = fopen(argv[1], "r");

  int x = lunghezza;
  i = 1;

  //AGGIUNTA VARIABILI ALLA SYMBOL TABLE

while(i<=x){
    char instruction[length];
    advance(fin, instruction, length);
    if(!(commandType(instruction) == 2)){
    if(instruction[0] == ' ' && strlength(instruction)>0){
        elimina_spazi(instruction);        
    }
      if(instruction[0] == '@' && commandType(instruction) == 1){
        number = value_var;
        int is_in = aggiungi_label(instruction, Symbol, number);      
        if(is_in == 0){
          value_var = value_var + 1;
        }
      }
      if(strlength(instruction)>0){
        i++;
      }
    }
  }
  


  fclose(fin);
  fin = fopen(argv[1], "r");

  i = 1;
  int k = lunghezza;
  // DA ASM A BIN.

 while(i <= k){
    char instruction[length];
    advance(fin, instruction, length);    
    int label = 0;
    if(instruction[0] != '('  && !(commandType(instruction) == 2)){
      if(instruction[0] == ' ' && strlength(instruction)>0){
          elimina_spazi(instruction);
      }   
      
      //printf("%c \n", instruction[0]);
      if(strlength(instruction) > 1){
        if(commandType(instruction) == 0){
            crea_binario(instruction, fout);
        } else if(commandType(instruction) == 1){
          if(instruction[0] == '('){
            label = 1;
          }
            crea_label(instruction, fout, Symbol);
        } else if(commandType(instruction) == 3){
            crea_instruction(instruction, fout);
        }
      }
      if(label == 0 && strlength(instruction)>0){      
        i++;
      } 
    } else if(instruction[0] == '('){
      k--;
    }
  }  
  stampa_lista(Symbol);

  fclose(fin);
  fclose(fout);
}
