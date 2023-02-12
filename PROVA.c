/*Si definisca la funzione c che riceve in ingresso due sequenze di interi s1 e s2 rappresentate come liste in forma collegata
 con puntatori e verifica se s1 è una sottosequenza di s2*/

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
void preInsert(struct linkedPlist **ptrptr, float value);
void postInsert(struct linkedPlist **ptrptr, float value);
void ordInsert(struct linkedPlist **ptrptr, int value);
void visit(struct linkedPlist *ptr);
Boolean preDelete(struct linkedPlist **ptrptr);
Boolean postDelete(struct linkedPlist **ptrptr);
Boolean search(struct linkedPlist *ptr, int target);
void copy(struct linkedPlist *src, struct linkedPlist **dst);
void delete_f(struct linkedPlist **ptrptr);
void delete(struct linkedPlist **ptrptr);


Boolean CheckLists(struct linkedPlist *ptr1, struct linkedPlist *ptr2);
Boolean match(struct linkedPlist *ptr1, struct linkedPlist *ptr2);

int main(void){
    struct linkedPlist *ptr1, *ptr2;


    init(&ptr1);
    float itemValue1;
    int sizeLista1;

    printf("inserisci la dimensione della lista: \n");
    scanf("%d", &sizeLista1);
    for (int i = 0; i < sizeLista1; ++i) {
        printf("inserisci un value: \n");
        scanf("%f", &itemValue1);
        postInsert(&ptr1,itemValue1);
    }
    printf("Lista1: \n");
    visit(ptr1);
    printf("\n");


    init(&ptr2);
    float itemValue2;
    int sizeLista2;

    printf("inserisci la dimensione della lista: \n");
    scanf("%d", &sizeLista2);
    for (int i = 0; i < sizeLista2; ++i) {
        printf("inserisci un value: \n");
        scanf("%f", &itemValue2);
        postInsert(&ptr2,itemValue2);
    }
    printf("Lista2: \n");
    visit(ptr2);
    printf("\n");

    Boolean Result=CheckLists(ptr1,ptr2);
    if(Result==1){
        printf("\nla lista2 appartiene alla lista 1!\n");
    }else{
        printf("\nla lista2 NON appartiene alla lista 1\n");
    }

    return 0;
}

Boolean CheckLists(struct linkedPlist *ptr1, struct linkedPlist *ptr2){
    Boolean Check= FALSE;
    while (ptr1!=NULL && Check==FALSE){
        if(match(ptr1,ptr2)==TRUE){
            Check=TRUE;
        }else{
            ptr1=ptr1->next_ptr;
        }
    }
    return Check;
}

Boolean match(struct linkedPlist *ptr1, struct linkedPlist *ptr2){
    Boolean found=TRUE;
    while(ptr2!=NULL && found==TRUE){
        if(ptr2->value!=ptr1->value || ptr1==NULL){
            found=FALSE;
        } else{
            ptr1=ptr1->next_ptr;
            ptr2=ptr2->next_ptr;
        }
    }
    return found;
}






////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  FUNCTION DECLARATION:

void init(struct linkedPlist **ptrptr){
    *ptrptr = NULL;
}

void preInsert(struct linkedPlist **ptrptr, float value){
    struct linkedPlist *new = (struct linkedPlist *)malloc(sizeof(struct linkedPlist));
    new->value = value;
    new->next_ptr = *ptrptr;
    *ptrptr = new;
}

void postInsert(struct linkedPlist **ptrptr, float value){
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

