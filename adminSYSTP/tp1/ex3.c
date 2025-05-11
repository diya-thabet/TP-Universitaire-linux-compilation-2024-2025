#include<stdio.h>
void  main()
{
	FILE *fichier ; 
	int n ; 
	fichier = fopen("nombre.dat", "wb+"); 
	for(int i=0; i<10 ;i++ ){
		printf("N="); 
		scanf("%d", &n);
		putw(n, fichier); 
	}
	rewind(fichier); 
	while((n=getw(fichier))!=EOF)
		printf("%d \n", n); 
	fclose(fichier);
        	
}
