/*Si consideri il caso di una anagrafe di cittadini rappresentati su un vettore di records. Ciascun record è composto da un nome
 un cognome, un codice ed una lista di parentele. A sua volta ciascuna parentela è rappresentata con un intero che codifica
 il tipo di parentela e con un indice che codifica la posizione nel vettore di anagrafe del cittadino parente. Si definiscano
 le strutture c impiegate nella rappresentazione e la funzione che riceve in ingresso il nome e cognome di un cittadino e stampa
 il nome e cognome dei suoi parenti e la relazione di parentela che li lega.*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
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

struct residente{
    char nome[81];
    char cognome[81];
    int codice;
    struct parentela *ptr;
};

struct parentela{
    int tipo;
    int indice_parente;
    struct parentela *next_ptr;
};

Boolean print_parenti(struct residente *R, int N, char *nome, char *cognome);
void print_parenti1(struct parentela *ptr, struct residente *R);




Boolean print_parenti(struct residente *R, int N, char *nome, char *cognome){
    Boolean found=FALSE;
    int count =0;
    while(count<N && found==FALSE){
        if(strcmp(R[count].nome,nome)==0 && strcmp(R[count].cognome,cognome)==0){
            found=TRUE;
        }else{
            count++;
        }
        if(found==TRUE){
            print_parenti1(R[count].ptr,R);
        }else{
            printf("Non esiste il residente %s %s", nome,cognome);
        }
    }
    return found;
}

void print_parenti1(struct parentela *ptr, struct residente *R){
    while(ptr!=NULL){
        printf("\n %s %s è parente di tipo %d",R[ptr->indice_parente].nome,R[ptr->indice_parente].cognome,ptr->tipo);
        ptr=ptr->next_ptr;
    }
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
