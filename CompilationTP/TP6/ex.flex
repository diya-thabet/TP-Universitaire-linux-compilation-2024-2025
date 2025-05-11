%{
    #include <stdio.h>
    #include <ctype.h>
    
    int char_count = 0;
    int line_count = 0;
    int word_count = 0;
    %}
    
    %%
    
    \n              { char_count++; line_count++; }
    [ \t\r]+        { char_count += yyleng; }                
    [a-zA-Z0-9]+   { char_count += yyleng; word_count++; }  
    .               { char_count++; }                   
    %%
    
    int main(void) {
        yylex();
        printf("number of characters: %d\n", char_count);
        printf("number of words: %d\n", word_count);
        printf("number of lines: %d\n", line_count);
        return 0;
    }
    