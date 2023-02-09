/*Si definisca la funzione che verifica se due liste di interi rappresentate in forma collegata con puntatori sono uguali*/



#include <stdio.h>
#include <stdlib.h>
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

Boolean areThoseEqual(struct LinkedPlist *ptr1, struct LinkedPlist *ptr2);

int main(void){
    struct LinkedPlist *ptr1, *ptr2;
    /* inizializzazione prima lista*/
    init(&ptr1);
    int size1;
    int value1;
    printf("inserisci size1: \n");
    scanf("%d", &size1);
    for (int i = 0; i < size1; ++i) {
        printf("inserisci un value1: \n");
        scanf("%d", &value1);
        postInsert(&ptr1,value1);
    }
    printf("Lista1: ");
    visit(ptr1);

    /* inizializzazione seconda lista:*/
    init(&ptr2);
    int size2;
    int value2;
    printf("\n\ninserisci size2: \n");
    scanf("%d", &size2);
    for (int i = 0; i < size2; ++i) {
        printf("inserisci un value2: \n");
        scanf("%d", &value2);
        postInsert(&ptr2,value2);
    }
    printf("Lista2: ");
    visit(ptr2);

    if(size1!=size2){
        printf("\n\nNO BRO HANNO DIMENSIONE DIVERSA");
        printf("\nLista1: \n");
        visit(ptr1);
        printf("\nLista2: \n");
        visit(ptr2);
    }else{
        /* utilizzo della funzione "areThoseEqual" */
        Boolean Result= areThoseEqual(ptr1,ptr2);
        if(Result==1){
            printf("\n\nSI BRO SONO IDENTICHE!\n");
        }
        else if(Result==0){
            printf("\n\nNO BRO SONO DIVERSE\n");
        }
        printf("\nLista1: \n");
        visit(ptr1);
        printf("\nLista2: \n");
        visit(ptr2);
    }

    return 0;
}


Boolean areThoseEqual(struct LinkedPlist *ptr1, struct LinkedPlist *ptr2){
    Boolean found;
    found=FALSE;
    if(ptr1==NULL && ptr2==NULL && found==FALSE){
        found=TRUE;
    }else while (ptr1!=NULL && ptr2!=NULL){
        if(ptr1->value!=ptr2->value){
            found=FALSE;
            ptr1=ptr1->next_ptr;
            ptr2=ptr2->next_ptr;
        } else{
            found=TRUE;
            ptr1=ptr1->next_ptr;
            ptr2=ptr2->next_ptr;
        }
        }
    return found;
    }


// Made by Lorenzo ChadSittaro






////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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