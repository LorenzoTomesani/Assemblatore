#include <stdio.h>
#include <stdlib.h>
#include "symboltable.h"

long long int numero_bin(int numero);
int strlength(char str1[]); 
void to16bits(long long int num, int array[], int length); 
int lunghezza_int(char str[]);
int fast_atoi(char str[]);
void elimina_chiocciola(char str[]);
void output_file(int array[], int length, FILE *fout);
void crea_bin(int numero, FILE *fout);
void crea_binario(char str[], FILE *fout);
void prendi_str(char str[], char out[]);
int aggiungi_label(char str[], node_t Symbol, int number);
void crea_label(char str[], FILE *fout, node_t Symbol);