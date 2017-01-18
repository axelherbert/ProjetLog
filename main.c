#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int write_log (char* logfile, char* text) {
    FILE* fichier = NULL;
    fichier = fopen(logfile, "a+");
    time_t curtime;
    time(&curtime);
    if (fichier) {
        fprintf(fichier, ctime(&curtime));
        fputs(text, fichier);
        fprintf(fichier, "\n");
        fclose(fichier);
    } else {
        printf("Impossible d'ouvrir le fichier");
        return 1;
    }

    return 0;

}


int main() {
    char choix[20];
    printf("Entrez un texte:\n");
    //scanf("%s", choix);
    fgets(choix, 20, stdin);

    write_log("test.log", choix);

    return 0;
}
