%{
#include <stdio.h>
#include <stdlib.h>

int i = 0; 
%}

%%
"(" { 
    i++; 
    printf("debut\n");
}
")" { 
    i--; 
    if (i < 0) {
        printf("erreur de paranthesage\n");
        exit(1);  
    }
    printf("fin\n");
}
.|\n {  }

%%

int main() {
    
    yylex();  
    if (i != 0) {
        printf("erreur de paranthesage\n");
        return 1;
    }
    printf("*** tres bien *** \n");
    return 0;
}

int yywrap() {
    return 1;
}
