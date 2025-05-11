#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file;
    char filename[100], ch;
    int wordCount = 0, lineCount = 0, spaceCount = 0, separatorCount = 0;
    int inWord = 0; 

    printf("Entrez le nom du fichier : ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier.\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lineCount++;
        }

        if (ch == ' ') {
            spaceCount++;
        }

        if (ch == ';' || ch == ':' || ch == ',' || ch == '.' || ch == '/') {
            separatorCount++;
        }

        if (isalnum(ch)) {
            inWord = 1; 
        } else {
            if (inWord) {
                wordCount++; 
            }
            inWord = 0; 
        }
    }

    if (inWord) {
        wordCount++;
    }

    printf("Nombre de mots : %d\n", wordCount);
    printf("Nombre de lignes : %d\n", lineCount);
    printf("Nombre d'espaces : %d\n", spaceCount);
    printf("Nombre de séparateurs : %d\n", separatorCount);

    // Fermer le fichier
    fclose(file);
    return 0;
}
