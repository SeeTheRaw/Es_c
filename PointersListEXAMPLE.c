#include <stdio.h>
#include <stdlib.h>
typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0

struct Poinlist{
    int value;
    struct List *next_ptr;
};

void init(struct Poinlist **ptrptr);
void preInsert(struct Poinlist **ptrptr, int value);
void postInsert(struct Poinlist **ptrptr, int value);
void ordInsert(struct Poinlist **ptrptr, int value);
void visit(struct Poinlist *ptr);
Boolean preDelete(struct Poinlist **ptrptr);
Boolean postDelete(struct Poinlist **ptrptr);
Boolean search(struct Poinlist *ptr, int target);

int main(void){
struct Poinlist *ptr;
    init(&ptr);
    int itemValue;
    printf("inserisci un value: \n");
    scanf("%d", &itemValue);
    postInsert(&ptr,itemValue);

    printf("inserisci un value: \n");
    scanf("%d", &itemValue);
    postInsert(&ptr,itemValue);

    printf("inserisci un value: \n");
    scanf("%d", &itemValue);
    postInsert(&ptr,itemValue);

    printf("lista dopo inserimento in coda: \n");
    visit(ptr);

    printf(" Sembra molto + semplice.....proviamo un inserimento in testa!\n\n");
    printf("inserisci un value: \n");
    scanf("%d", &itemValue);
    preInsert(&ptr,itemValue);

    printf("lista dopo inserimento in testa: \n");
    visit(ptr);

    printf("\nOk EASY BOYS\n");
    printf("Ora inserimento ordinato!\n\n");
    printf("inserisci un value: \n");
    scanf("%d", &itemValue);
    ordInsert(&ptr,itemValue);

    printf("lista dopo inserimento ordinato: \n");
    visit(ptr);

    printf("\n\nDeh toccah fare una Search a sto punto!\n");
    int target;
    printf("inserisci un target: \n");
    scanf("%d", &target);
    Boolean result = search(ptr,target);
    if(result==1)printf("target trovato!\n\n");
    else printf("\ntarget NON trovato :(\n\n");



    return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  FUNCTION DECLARATION:

void init(struct Poinlist **ptrptr){
    *ptrptr = NULL;
}

void preInsert(struct Poinlist **ptrptr, int value){
    struct Poinlist *new = (struct Poinlist *)malloc(sizeof(struct Poinlist));
    new->value = value;
    new->next_ptr = *ptrptr;
    *ptrptr = new;
}

void postInsert(struct Poinlist **ptrptr, int value){
    while(*ptrptr != NULL){
        ptrptr = &(*ptrptr)->next_ptr;
    }

    preInsert(ptrptr, value);
}

Boolean preDelete(struct Poinlist **ptrptr){
    if(*ptrptr != NULL){
        struct list *tmp_ptr;
        tmp_ptr = *ptrptr;
        *ptrptr = (*ptrptr)->next_ptr;
        free(tmp_ptr);
        return TRUE;
    }
    return FALSE;
}

Boolean postDelete(struct Poinlist **ptrptr){
    if(*ptrptr != NULL){
        while((*ptrptr)->next_ptr != NULL){
            ptrptr = &(*ptrptr)->next_ptr;
        }
        preDelete(ptrptr);
        return TRUE;
    }
    return FALSE;
}

void ordInsert(struct Poinlist **ptrptr, int value){
    while(*ptrptr != NULL && (*ptrptr)->value < value)
        ptrptr = &(*ptrptr)->next_ptr;

    preInsert(ptrptr, value);
}

void visit(struct Poinlist *ptr){
    while(ptr != NULL){
        printf("%d ", ptr->value);
        ptr = ptr->next_ptr;
    }
}

Boolean search(struct Poinlist *ptr, int target){
    Boolean found = FALSE;

    while(!found && ptr != NULL){
        if(ptr->value == target)
            found = TRUE;

        ptr = ptr->next_ptr;
    }

    return found;
}


