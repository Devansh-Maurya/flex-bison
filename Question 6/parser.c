#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lex.yy.c"

int i;
char token;

char nextToken()
{
    return yylex();
}

int check(char ch);

void S();
void S1();
void A();
void A1();

int main()
{
    token = nextToken();

    S();

    if (token == '$')
    {
        printf("valid\n");
    }
    else
    {
        printf("invalid\n");
    }

    return 0;
}

void S()
{
    switch (token)
    {
    case 'a':
    {
        check('a');
        printf("S->aS1c\n");
        S1();
        check('c');
        break;
    }
    default:
    {
        printf("invalid\n");
        exit(1);
    }
    }
}

void S1()
{
    switch (token)
    {
    case 'a':
    {
        check('a');
        printf("S1->aS1c\n");
        S1();
        check('c');
        break;
    }
    case 'b':
    {
        A();
        printf("S1->A\n");
        break;
    }
    default:
    {
        printf("invalid\n");
        exit(1);
    }
    }
    return;
}

void A()
{

    switch (token)
    {
    case 'b':
    {
        check('b');
        printf("A->bA1\n");
        A1();
        break;
    }
    default:
    {
        printf("invalid\n");
        exit(1);
    }
    }
}

void A1()
{
    switch (token)
    {
    case 'b':
    {
        printf("A1->Ac\n");
        A();
        check('c');
        break;
    }
    case 'c':
    {
        check('c');
        printf("A1->c\n");
        break;
    }
    default:
    {
        printf("invalid\n");
        exit(1);
    }
    }
}

int check(char ch)
{
    if (token == ch)
    {
        token = nextToken();
    }
    else
    {
        printf("invalid\n");
        exit(1);
    }
}
