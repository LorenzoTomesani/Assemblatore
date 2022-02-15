#include <stdio.h>
#include <stdlib.h> 

int cerca_simbol(char simbol[],  char symbol); 
void computation_eq(char comp[], int out[], int length);
void jump(char jump[], int out[]);
void dest(char dest[], int out[]); 

void crea_instruction(char instruction[], FILE* fout);