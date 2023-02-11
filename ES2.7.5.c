/* Si definisca la funzione C in forma ricorsiva che cancella una lista collegata con puntatori rilasciando la memoria*/

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

void delete_f(struct LinkedPlist **ptrptr);
void delete(struct LinkedPlist **ptrptr);

int main(void){
    struct LinkedPlist *ptr;
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

    printf("lista: \n");
    visit(ptr);
    printf("\n");

    delete_f(&ptr);
    printf("lista dopo delete: \n");
    visit(ptr);


    return 0;
}

void delete_f(struct LinkedPlist **ptrptr){
    delete(ptrptr);
    init(ptrptr);
}

void delete(struct LinkedPlist **ptrptr){
    if(*ptrptr != NULL){
        delete(&(*ptrptr)->next_ptr);
        free(*ptrptr);
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

void copy(struct LinkedPlist *src, struct LinkedPlist **dst){
    if(src != NULL){
        copy(src->next_ptr, dst);
        preInsert(dst, src->value);
    }else{
        init(dst);
    }
}



