%option noyywrap

%%
int                         { printf("KEYWORD: %s\n", yytext);}
float                       { printf("KEYWORD: %s\n", yytext);}
[_a-zA-Z][a-zA-Z0-9_]*      { printf("ID: %s\n", yytext);}
[0-9]+                      { printf("INUM: %s\n", yytext);}
[0-9]*"."[0-9]+             { printf("FNUM: %s\n", yytext);}
.                           {}

