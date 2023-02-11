/* Si definisca la funzione C in forma ricorsiva che crea la copia di una lista collegata con puntatori*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0

struct LinkedPlist{
    int value;
    struct List *next_ptr;
};

void init(struct LinkedPlist **ptrptr);
void preInsert(struct LinkedPlist **ptrptr, int value);
void postInsert(struct LinkedPlist **ptrptr, int value);
void ordInsert(struct LinkedPlist **ptrptr, int value);
void visit(struct LinkedPlist *ptr);
Boolean preDelete(struct LinkedPlist **ptrptr);
Boolean postDelete(struct LinkedPlist **ptrptr);
Boolean search(struct LinkedPlist *ptr, int target);

void copy(struct LinkedPlist *src, struct LinkedPlist **dst);

int main(void){
struct LinkedPlist *src;
struct LinkedPlist *dst;
    init(&src);
    int itemValue;
    int sizeLista;

    printf("inserisci la dimensione della lista: \n");
    scanf("%d", &sizeLista);
    for (int i = 0; i < sizeLista; ++i) {
        printf("inserisci un value: \n");
        scanf("%d", &itemValue);
        postInsert(&src,itemValue);
    }
    printf("Lista: \n");
    visit(src);

    printf("\n");


    copy(src,&dst);
    printf("Lista copiata: \n");
    visit(dst);


    return 0;
}

void copy(struct LinkedPlist *src, struct LinkedPlist **dst){
    if(src != NULL){
        copy(src->next_ptr, dst);
        preInsert(dst, src->value);
    }else{
        init(dst);
    }
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  FUNCTION DECLARATION:

void init(struct LinkedPlist **ptrptr){
    *ptrptr = NULL;
}

void preInsert(struct LinkedPlist **ptrptr, int value){
    struct LinkedPlist *new = (struct LinkedPlist *)malloc(sizeof(struct LinkedPlist));
    new->value = value;
    new->next_ptr = *ptrptr;
    *ptrptr = new;
}

void postInsert(struct LinkedPlist **ptrptr, int value){
    while(*ptrptr != NULL){
        ptrptr = &(*ptrptr)->next_ptr;
    }

    preInsert(ptrptr, value);
}

Boolean preDelete(struct LinkedPlist **ptrptr){
    if(*ptrptr != NULL){
        struct list *tmp_ptr;
        tmp_ptr = *ptrptr;
        *ptrptr = (*ptrptr)->next_ptr;
        free(tmp_ptr);
        return TRUE;
    }
    return FALSE;
}

Boolean postDelete(struct LinkedPlist **ptrptr){
    if(*ptrptr != NULL){
        while((*ptrptr)->next_ptr != NULL){
            ptrptr = &(*ptrptr)->next_ptr;
        }
        preDelete(ptrptr);
        return TRUE;
    }
    return FALSE;
}

void ordInsert(struct LinkedPlist **ptrptr, int value){
    while(*ptrptr != NULL && (*ptrptr)->value < value)
        ptrptr = &(*ptrptr)->next_ptr;

    preInsert(ptrptr, value);
}

void visit(struct LinkedPlist *ptr){
    while(ptr != NULL){
        printf("%d ", ptr->value);
        ptr = ptr->next_ptr;
    }
}

Boolean search(struct LinkedPlist *ptr, int target){
    Boolean found = FALSE;

    while(!found && ptr != NULL){
        if(ptr->value == target)
            found = TRUE;

        ptr = ptr->next_ptr;
    }

    return found;
}




