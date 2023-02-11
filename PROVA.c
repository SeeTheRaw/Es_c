/* Si definisca la funzione C che verifica se una lista in forma collegata con puntatori contiene due valori uguali
 consecutivi */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0

struct linkedPlist{
    int value;
    struct linkedPlist *next_ptr;
};

void init(struct linkedPlist **ptrptr);
void preInsert(struct linkedPlist **ptrptr, int value);
void postInsert(struct linkedPlist **ptrptr, int value);
void ordInsert(struct linkedPlist **ptrptr, int value);
void visit(struct linkedPlist *ptr);
Boolean preDelete(struct linkedPlist **ptrptr);
Boolean postDelete(struct linkedPlist **ptrptr);
Boolean search(struct linkedPlist *ptr, int target);
void copy(struct linkedPlist *src, struct linkedPlist **dst);
void delete_f(struct linkedPlist **ptrptr);
void delete(struct linkedPlist **ptrptr);


Boolean Sameshit(struct linkedPlist *ptr);



int main(void){
    struct linkedPlist *ptr;
    init(&ptr);
    int itemValue;
    int sizeLista;

    printf("inserisci la dimensione della lista: \n");
    scanf("%d", &sizeLista);
    for (int i = 0; i < sizeLista; ++i) {
        printf("inserisci un value: \n");
        scanf("%d", &itemValue);
        postInsert(&ptr,itemValue);
    }
    printf("Lista: \n");
    visit(ptr);
    printf("\n");

Boolean Result= Sameshit(ptr);
if(Result==1){
    printf("\nBro che combini ce ne sono 2 consecutivi uguali!!!(ha funzionato)\n");
} else printf("\nTutto nella norma(Nessun valore consecutivo uguale)\n");

    return 0;
}


Boolean Sameshit(struct linkedPlist *ptr){
    Boolean Gotcha = FALSE;
    while(ptr != NULL && ptr->next_ptr!=NULL && Gotcha == FALSE){
        if(ptr->value==ptr->next_ptr->value){
            Gotcha=TRUE;
        }
        ptr=ptr->next_ptr;
    }
    return Gotcha;
}













////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  FUNCTION DECLARATION:

void init(struct linkedPlist **ptrptr){
    *ptrptr = NULL;
}

void preInsert(struct linkedPlist **ptrptr, int value){
    struct linkedPlist *new = (struct linkedPlist *)malloc(sizeof(struct linkedPlist));
    new->value = value;
    new->next_ptr = *ptrptr;
    *ptrptr = new;
}

void postInsert(struct linkedPlist **ptrptr, int value){
    while(*ptrptr != NULL){
        ptrptr = &(*ptrptr)->next_ptr;
    }

    preInsert(ptrptr, value);
}

Boolean preDelete(struct linkedPlist **ptrptr){
    if(*ptrptr != NULL){
        struct list *tmp_ptr;
        tmp_ptr = *ptrptr;
        *ptrptr = (*ptrptr)->next_ptr;
        free(tmp_ptr);
        return TRUE;
    }
    return FALSE;
}

Boolean postDelete(struct linkedPlist **ptrptr){
    if(*ptrptr != NULL){
        while((*ptrptr)->next_ptr != NULL){
            ptrptr = &(*ptrptr)->next_ptr;
        }
        preDelete(ptrptr);
        return TRUE;
    }
    return FALSE;
}

void ordInsert(struct linkedPlist **ptrptr, int value){
    while(*ptrptr != NULL && (*ptrptr)->value < value)
        ptrptr = &(*ptrptr)->next_ptr;

    preInsert(ptrptr, value);
}

void visit(struct linkedPlist *ptr){
    while(ptr != NULL){
        printf("%d ", ptr->value);
        ptr = ptr->next_ptr;
    }
}

Boolean search(struct linkedPlist *ptr, int target){
    Boolean found = FALSE;

    while(!found && ptr != NULL){
        if(ptr->value == target)
            found = TRUE;

        ptr = ptr->next_ptr;
    }

    return found;
}

void copy(struct linkedPlist *src, struct linkedPlist **dst){
    if(src != NULL){
        copy(src->next_ptr, dst);
        preInsert(dst, src->value);
    }else{
        init(dst);
    }
}

void delete_f(struct linkedPlist **ptrptr){
    delete(ptrptr);
    init(ptrptr);
}

void delete(struct linkedPlist **ptrptr){
    if(*ptrptr != NULL){
        delete(&(*ptrptr)->next_ptr);
        free(*ptrptr);
    }
}

