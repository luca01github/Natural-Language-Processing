#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define BUFFER_SIZE 1024

int main(){
    FILE *fin = fopen("romeo_noupper.txt", "r");
    FILE *fout = fopen("romeo_final.txt", "w");
    if(!fin || !fout){
        perror("Error while opening the files\n");
        return 1;
    }

    char line[BUFFER_SIZE];
    while(fgets(line, BUFFER_SIZE, fin)){
        char *token = strtok(line, " =\n\t,;:_()");
        while(token != NULL){
            if(strcmp(token, "Scene") != 0 && !isdigit((unsigned char)*token)){
                for(int i=0; token[i]; i++){
                    token[i] = tolower((unsigned char)token[i]);
                }
                fprintf(fout, "%s ", token);
            }
            token = strtok(NULL, " =\n\t,;:_()");
        }
        fputc('\n', fout);
    }

    fclose(fin);
    fclose(fout);
}