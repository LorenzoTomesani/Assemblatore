#include "ainstr.h"


//DA BINARIO A DECIMALE

long long int numero_bin(int numero){
  long long int esponente = 1;
  long long int risultato = 0;
  while(numero > 0){
    risultato = risultato + ((numero%2) * esponente);
    esponente = esponente * 10;
    numero = numero/2;
  }
  return risultato;
}

// LUNGHEZZA STRINGA PER NOME VARIABILI

int strlength(char str1[]){
  int j = 0; 
  while(str1[j] != '\0'){
    j++; 
  }
  if(str1[0] == '%'){
    return(j-2);
  } else {
    return (j - 1);
  }
  
}

//CREAZIONE DI UNA OPERAZIONE DI 16 BITS

void to16bits(long long int numero, int array[], int length){
  for(int i = (length - 1); i >= 0; i--){
    array[i] = numero%10;
    numero = numero/10;   
  }
  if(array[0] != 0){
    array[0] = 0;
  }
}

// LUNGHEZZA DI STRINGA PER AINSTRUCTION CON CONSTANTI

int lunghezza_int(char str[]){
  int i = 0;
  int risultato = 0;
  int found = 1;
  while(i < 16 && (found == 1)){
    int stringa = str[i] - '0';
    if(stringa <= 9 && stringa >= 0){
      risultato ++;
      i ++;
    } else {
      found = 0;
    }
  }
  return risultato;
}

// DA STRINGA A INTERO. (IMPLEMENTAZIONE DI ATOI DELLA LIBRERIA STRING.H)

int fast_atoi(char str[]){
  int i = 0;
  int j = 0;
  int risultato = 0;
  int found = 1;
  int mult = 1;
  int length = lunghezza_int(str);
  while(i < (length - 1)){
    mult = mult * 10;
    i ++;
  }
  while(j < 16 && (found == 1)){
    int stringa = str[j] - '0';
    if(stringa <= 9 && stringa >= 0){
      risultato = risultato + (stringa * mult);
      mult = mult/10;
      j ++;
    } else {
      found = 0;
    }
  }
  return risultato;
}

// ELIMINAZIONE_CHIOCCIOLA DA AINSTRUCTION

void elimina_chiocciola(char str[]){
  int length;  
  if(str[1] <= '9' && str[1] >= '0'){  
      str[0] = '0';
      length = lunghezza_int(str); 
  } 
  int i = 0;
  while(str[i] != '\0'){
    str[i] = str[i+1];    
    i++;
  } 
  str[i] = ' ';  
  printf("%s  %d\n", str,strlength(str));    
}

// SCRITTURA SU FILE DEL NUMERO GIÀ IN BINARIO IN 16 BITS.

void output_file(int array[], int length, FILE *fout){
  for(int i = 0; i < length; i++){
    fprintf(fout, "%d", array[i]);
  }
    fprintf(fout, "\n");
}

// METODO COMPLESSIVO DI TRADUZIONE IN BINARIO, IN 16 BITS, E SCRITTURA SU FILE.

void crea_bin(int numero, FILE *fout){
  long long int risultato = numero_bin(numero);
  int length = 16;
  int binario[length];
  to16bits(risultato,binario, length);  
  output_file(binario, length, fout);
}

//METODO PER LA CREAZIONE DEL BINARIO DI UNA AINSTRUCTION CON CONSTANTE. (@2).

void crea_binario(char str[], FILE *fout){
    elimina_chiocciola(str);
    int risultato = fast_atoi(str);
    crea_bin(risultato, fout);    
}

// METODO PER PRELEVARE LA STRINGA DI LABEL : ES -> (NOME_STRINGA).

void prendi_str(char str[], char out[]){
  int i;
  int j = 0;
  if(str[0] == '('){
    i = 1;
  } else {
    i = 0;
  }
  while(str[i] != ')' && i < strlength(str) - 1 && str[i+1] != '/' &&  str[i] != '\0' && str[i] != ' '){
      out[j] = str[i];  
      i++;
      j++;
  }
  out[j] = '\0';
}

// INSERIMENTO DEL LABEL NELLA SYMBOL TABLE -> PRIMA PASSATA E SECONDA PER LE VARIABILI.
// DI TIPO INT PERCHÈ DOBBIAMO PASSARE UN VALORE NEL CASO SIÀ GIA PRESENTE IN SYMBOL TABLE.

int aggiungi_label(char str[], node_t Symbol, int number){
  char out[40];  
  if(str[0] == '@'){
    elimina_chiocciola(str); 
    
  }
  prendi_str(str, out);
  int bool = ricerca_valore(Symbol, out);     
  if(bool == 0 && strlength(out) > 1){
    aggiunta_valore(Symbol, out, number);
    return 0;
  } else{
    return 1;
  }   
}

// PASSATA FINALE DI TRADUZIONE E PRELEVAZIONE VALORI DALLA SYMBOL TABLE.

void crea_label(char str[], FILE *fout, node_t Symbol){
  char out[30]; 
    if(str[0] == '@'){
      elimina_chiocciola(str);
    } 
     prendi_str(str, out);
     int value = returnValue(Symbol, out);
     crea_bin(value, fout);      
}

//void binario_label(char str[], node_t p1){
//}
