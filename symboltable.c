#include "symboltable.h"

/*  char  nome[100];
  int valore;
  struct node *next; 
  

LOOP E END A SECONDA DELLA RIGA 
LE VARIABILI DA 16 IN POI
*/

// METODO CREAZIONE LISTA.

node_t crea_lista(){
  node_t head, tmp;
  head = NULL; 
  
  tmp = malloc(sizeof(struct node));
  strcpy(tmp->nome, "THAT");
  tmp->valore = 4;
  tmp->next = head;
  head = tmp; 
  
  tmp = malloc(sizeof(struct node));
  strcpy(tmp->nome, "THIS");
  tmp->valore = 3;
  tmp->next = head;
  head = tmp; 
  
  tmp = malloc(sizeof(struct node));
  strcpy(tmp->nome, "ARG");
  tmp->valore = 2;
  tmp->next = head;
  head = tmp; 
  
  tmp = malloc(sizeof(struct node));
  strcpy(tmp->nome, "LCL");
  tmp->valore = 1;
  tmp->next = head;
  head = tmp; 
  
  tmp = malloc(sizeof(struct node));
  strcpy(tmp->nome, "SP");
  tmp->valore = 0;
  tmp->next = head;
  head = tmp; 
  
  tmp = malloc(sizeof(struct node));
  strcpy(tmp->nome, "KBD");
  tmp->valore = 24576;
  tmp->next = head;
  head = tmp;

  tmp = malloc(sizeof(struct node));
  strcpy(tmp->nome, "SCREEN");
  tmp->valore = 16384;
  tmp->next = head;
  head = tmp;
  
  tmp = malloc(sizeof(struct node));
  strcpy(tmp->nome, "R15");
  tmp->valore = 15;
  tmp->next = head;
  head = tmp;
  
  tmp = malloc(sizeof(struct node));
  strcpy(tmp->nome, "R14");
  tmp->valore = 14;
  tmp->next = head;
  head = tmp;
  
  tmp = malloc(sizeof(struct node));
  strcpy(tmp->nome, "R13");
  tmp->valore = 13;
  tmp->next = head;
  head = tmp;
  
  tmp = malloc(sizeof(struct node));
  strcpy(tmp->nome, "R12");
  tmp->valore = 12;
  tmp->next = head;
  head = tmp;
  
  tmp = malloc(sizeof(struct node));
  strcpy(tmp->nome, "R11");
  tmp->valore = 11;
  tmp->next = head;
  head = tmp;
  
  tmp = malloc(sizeof(struct node));
  strcpy(tmp->nome, "R10");
  tmp->valore = 10;
  tmp->next = head;
  head = tmp;
  
  tmp = malloc(sizeof(struct node));
  strcpy(tmp->nome, "R9");
  tmp->valore = 9;
  tmp->next = head;
  head = tmp;
  
  tmp = malloc(sizeof(struct node));
  strcpy(tmp->nome, "R8");
  tmp->valore = 8;
  tmp->next = head;
  head = tmp;
  
  tmp = malloc(sizeof(struct node));
  strcpy(tmp->nome, "R7");
  tmp->valore = 7;
  tmp->next = head;
  head = tmp;
  
  tmp = malloc(sizeof(struct node));
  strcpy(tmp->nome, "R6");
  tmp->valore = 6;
  tmp->next = head;
  head = tmp;
  
  tmp = malloc(sizeof(struct node));
  strcpy(tmp->nome, "R5");
  tmp->valore = 5;
  tmp->next = head;
  head = tmp;
  
  tmp = malloc(sizeof(struct node));
  strcpy(tmp->nome, "R4");
  tmp->valore = 4;
  tmp->next = head;
  head = tmp;

  tmp = malloc(sizeof(struct node));
  strcpy(tmp->nome, "R3");
  tmp->valore = 3;
  tmp->next = head;
  head = tmp;
  
  tmp = malloc(sizeof(struct node));
  strcpy(tmp->nome, "R2");
  tmp->valore = 2;
  tmp->next = head;
  head = tmp;
 
  tmp = malloc(sizeof(struct node));
  strcpy(tmp->nome, "R1");
  tmp->valore = 1;
  tmp->next = head;
  head = tmp; 

  tmp = malloc(sizeof(struct node));
  strcpy(tmp->nome, "R0");
  tmp->valore = 0;
  tmp->next = head;
  head = tmp;
  return(head);
}

// METODO PER LA COMPARAZIONE DI DUE STRINGHE, DALLA LIBRERIA STRING.H 

int strcomp(char str1[], char str2[]){
    int n = 0;
    int found = 0;
    while(str1[n]==str2[n] && found == 0){
      if(str1[n]=='\0'||str2[n]=='\0'){
          found = 1;
      } else {
        n++;
      }
    }
    if(str1[n]=='\0' && str2[n]=='\0'){
        return 1;
    }else{
        return 0;
    }
}

// METODO PER LA RICERCA DI VALORI.
// 0 se non trova valore, 1 se lo trova

int ricerca_valore(node_t head, char str[]){ 
  node_t tmp;
  tmp = head;
  int found = 0;
  while(tmp != NULL && found == 0){
    if((strcomp(str, tmp->nome)) == 1){
      found = 1;
    } else {
      tmp = tmp->next;
    }
  }
  return(found == 1);
}

// AGGIUNTA DEL VALORE ALL'INTERNO DELLA SYMBOL TABLE.

void aggiunta_valore(node_t head, char nome[], int value){
  node_t tmp, new_value;
  tmp = head;  
  while((tmp->next)!= NULL){
    tmp = tmp -> next;
  }    
  new_value = malloc(sizeof(struct node));
  strcpy(new_value->nome, nome);
  new_value->valore = value;
  new_value->next = NULL;
  tmp->next = new_value; 
}

//METODO NON NECESSARIO, MA UTILE PER VEDERE QUALI ELEMENTI INSERITI
// NELLA SYMBOL TABLE.

void stampa_lista(node_t p1){
  node_t tmp = p1;
  while(tmp != NULL){
    printf("\n [%s] : [%d] ; \n ", tmp->nome, tmp->valore);
    tmp = tmp-> next;
  }
}

//METODO PER PRELEVARE IL VALORE IN INTERO CORRISPONDENTE AL NOME PASSATO
int returnValue(node_t head, char str[]){
  node_t tmp;
  tmp = head;
  int found = 0;
  while(tmp != NULL && found == 0){
    if((strcomp(str, tmp->nome)) == 1){
      found = 1;
    } else {
      tmp = tmp->next;
    }
  }
  return(tmp->valore);
}

