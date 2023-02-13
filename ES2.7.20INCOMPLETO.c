/*Si consideri il caso del sistema informativo per la gestione di un parcheggio al quale accedono autoveicoli autorizzati da un insieme
di dipartimenti. Ciascun dipartimento è rappresentato da un descrittore che include il numero di telefono della segreteria del
 dipartimento e una lista di targhe automobilistiche autorizzate. Si definiscano le strutture che rappresentano il descrittore del
 dipartimento e un  numero di targa e verifica che essa sia registrata almeno su un dipartimento, restituendo in caso positivo il numero di telefono
 del dipartimento a cui è associata la targa.*/

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

struct Deposito{
    int NumeroTelefono;
    struct listTarghe *ptr
};
struct listTarghe{
    int numeroTarga;
    struct listTarghe *next_ptr;
};

Boolean searchTargaMacchina(struct Deposito *V, int targa, int *numeroTelefono);



Boolean searchTargaMacchina(struct Deposito *V, int targa, int *numeroTelefono){
Boolean found=FALSE;
int count=0;
while(count<10 && found==FALSE){
    if(search(V[count].ptr, targa)==TRUE){
        *numeroTelefono=V[count].NumeroTelefono;
        found=TRUE;
    }else{
        count++;
    }
}
    return found;
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

