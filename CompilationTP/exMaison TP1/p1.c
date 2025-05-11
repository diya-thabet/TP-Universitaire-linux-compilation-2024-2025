#include <stdio.h>
#include <math.h>

int somme(int i);
double racineCarree(int j);

int main() {
    int i, j;
    
    printf("Entrez la valeur de i : ");
    scanf("%d", &i);
    printf("Entrez la valeur de j : ");
    scanf("%d", &j);

    int resultat1 = somme(i);
    double resultat2 = racineCarree(j);
    double produit = resultat1 * resultat2;

    printf("Produit de (i + 3) et sqrt(j) : %.2f\n", produit);
    
    return 0;
}
