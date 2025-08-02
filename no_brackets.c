#include <stdio.h>
#include <stdbool.h>

int main(){
    FILE *fin = fopen("Romeo-and-Juliet_ORIGINAL.txt", "r");
    FILE *fout = fopen("Romeo_nobrackets.txt", "w");

    if(!fin || !fout){
        perror("Error while opening the files\n");
        return 1;
    }

    int ch;
    char inside_brackets = 0;

    while((ch = fgetc(fin)) != EOF){
        if(ch == '['){
            inside_brackets = 1;
        }
        else if(ch == ']'){
            inside_brackets = 0;
        }
        else if(!inside_brackets){
            fputc(ch, fout);
        }
    }

    fclose(fin);
    fclose(fout);
}
