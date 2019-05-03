#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <string.h>

#define MAX 100

typedef struct Node
{
    char *identifier, *type;
    struct Node *next;
} Node;

typedef struct
{
    Node* head[MAX];
} SymbolTable;

int hashf(char *id)
{
    int asciiSum = 0;

    for (int i = 0; i < strlen(id); i++)
    {
        asciiSum = asciiSum + id[i];
    }

    return (asciiSum % 100);
}

int insert(SymbolTable* st,char *id, char *Type)
{
    int index = hashf(id);
    Node *p = (Node*)malloc(sizeof(Node));//new Node(id, scope, Type, lineno);
    p->identifier = id;
    p->type = Type;

    if (st->head[index] == NULL)
    {
        st->head[index] = p;
        st->head[index]->next = NULL;
        printf("\n%s inserted",id);
        return 1;
    }
    else
    {
        Node *start = st->head[index];
        while (start->next != NULL)
        {
            start = start->next;
        }

        start->next = p;
        start->next->next = NULL;
        printf("\n%s inserted",id);
        return 1;
    }

    return 0;
}

void printNode(Node node)
{
    printf("\n%s\t\t%s",node.identifier,node.type);
}

void printST(SymbolTable* st)
{
    printf("\n\nSymbol Table\n%s\t%s\n----------------------------","token id","name");
    for(int i=0; i<MAX;i++)
    {
        Node* start = st-> head[i];
        while( start != NULL)
        {
            printNode(*start);
            start = start->next;
        }
    }
}

void find(SymbolTable* st,char *id)
{
    int index = hashf(id);
    Node* start = st->head[index];

    if (start == NULL)
        printf("%s Not found", id);

    while (start != NULL) {

        if (start->identifier == id) {
            printNode(*start);
        }

        start = start->next;
    }
}

int deleteRecord(SymbolTable *st,char *id)
{
    int index = hashf(id);
    Node* tmp = st->head[index];
    Node* par = st->head[index];

    // no identifier is present at that index
    if (tmp == NULL) {
        return 0;
    }
    // only one identifier is present
    if ( !strcmp(tmp->identifier , id) && tmp->next == NULL) {
        tmp->next = NULL;
        free(tmp);
        return 1;
    }

    while (!strcmp(tmp->identifier , id) && tmp->next != NULL) {
        par = tmp;
        tmp = tmp->next;
    }
    if ((strcmp(tmp->identifier , id)==0? 1:0) && tmp->next != NULL) {
        par->next = tmp->next;
        tmp->next = NULL;
        free(tmp);
        return 1;
    }

    // delete at the end
    else {
        par->next = NULL;
        tmp->next = NULL;
        free(tmp);
        return 1;
    }
    return 0;
}

int main()
{
    SymbolTable st={NULL,NULL,NULL,NULL};
    insert(&st,"if", "keyword");
    insert(&st,"val1", "identifier");
    insert(&st,"if", "keyword");
    insert(&st,"if", "keyword");
    // find(&st,"if");
    deleteRecord(&st,"if");
    printST(&st);
}
