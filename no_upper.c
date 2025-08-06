#include <ctype.h>
#include <stdio.h>
#include <string.h>

int is_all_upper(const char *word) {
    if (word == NULL)
        return 0;

    if (strlen(word) > 1) {
        return isupper(*word) && isupper(*(word + 1));
    }
    return 0;
}

int main() {
    FILE *fin = fopen("Romeo_nobrackets.txt", "r");
    FILE *fout = fopen("romeo_noupper.txt", "w");

    if (!fin || !fout) {
        perror("Error while opening the files\n");
        return 1;
    }

    char line[1024];
    while(fgets(line, 1024, fin)){
        char *token = strtok(line, " \n,;:_()");
        while(token != NULL){
            if(!is_all_upper(token)){
                fprintf(fout, "%s ", token);
            }
            token = strtok(NULL, " \n,;:_()");
        }
        fprintf(fout, "%s", "\n");
    }
    fclose(fin);
    fclose(fout);
        

}