#include <stdio.h>

void nome_output(char *str[], char out[], int length);
int lunghezza_file(FILE *fout);
int commandType(char array[]); // 0 per ainstr, 1 per labelinstr, 2 per cinstr.
void advance(FILE* fin, char array[], int length);
void elimina_spazi(char array[]);
int last_space(char array[], int length);
void toAssembly(char *argv[]);
int lunghezza_file_nolab(FILE *fout);