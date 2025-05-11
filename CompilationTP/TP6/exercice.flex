%{
    #include <stdio.h>
    #include <ctype.h>
%}

%%

"+"         { printf("operateur: +\n"); }
"-"         { printf("operateur: -\n"); }
"*"         { printf("operateur: *\n"); }
"/"         { printf("operateur: /\n"); }
[1-9]+\.[1-9]+  { printf("nombre: reel\n"); }
[1-9]+      { printf("nombre: entier\n"); }

%%
int yywrap() {
    return 1;
}
int main() {
    yylex(); 
    return 0;
}
