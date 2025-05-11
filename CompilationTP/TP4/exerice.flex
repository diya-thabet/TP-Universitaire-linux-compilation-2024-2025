%{
#include <stdio.h>

int a = 0, b = 0;
%}

%%

[a-zA-Z]*    { a++; }
z    { b++; }
.    { /* Ignore other characters */ }
\n   { return 0; }  /* Stop on newline */

%%

int main() {
    printf("Enter a string (press Enter to stop):\n");
    yylex();
    printf("Nombre de 'a' est: %d\n", a);
    printf("Nombre de 'z' est: %d\n", b);
    return 0;
}

int yywrap() {
    return 1;
}
