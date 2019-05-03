%option noyywrap

%{
    int lines=0, words=0, characters=0;
%}

%%

\n          {lines++; characters++;};
[^ \t\n]+   {words++; characters+=yyleng;}
.           {characters++;}

%%

main() {

    yylex();
    printf("Characters: %d\nWords: %d\nLines: %d\n", characters, words, lines);
    return(0);

}
