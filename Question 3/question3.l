%option noyywrap

%{
    int lineNum = 1;
%}

%%

.*\n    { printf("%5d %s", lineNum++, yytext);}
