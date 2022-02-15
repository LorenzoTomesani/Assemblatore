#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char  nome[100];
    int valore;
    struct node *next;
} *node_t;

node_t crea_lista();
int ricerca_valore(node_t head, char str[]);
int strcomp(char str1[], char str2[]);
void aggiunta_valore(node_t head, char nome[], int value); //dipende da 
void stampa_lista(node_t p1);
int strlength(char str1[]);
int returnValue(node_t head, char nome[]);
