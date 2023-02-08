#include <stdio.h>
#include <stdlib.h>
typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0

struct Linkedlist{
    struct record *buffer;
    int size;
    int first;
    int free;
};

struct record{
    int value;
    int next;
};

Boolean init(struct Linkedlist *ptr, int size);
Boolean preInsert(struct Linkedlist *ptr, int value);
Boolean postInsert(struct Linkedlist *ptr, int value);
Boolean ordInsert(struct Linkedlist *ptr, int value);
void visit(struct Linkedlist *ptr);
Boolean preDelete(struct Linkedlist *ptr);
Boolean postDelete(struct Linkedlist *ptr);
Boolean search(struct Linkedlist *ptr, int target);

int main(void){
    struct Linkedlist ptr;
    int size;
    int value;
    printf("inserisci size: ");
    scanf("%d", &size);
    init(&ptr, size);

    //INSERIMENTO DI QUALCHE VALUE:

    printf("inserisci un value: ");
    scanf("%d", &value);
    postInsert(&ptr,value);

    printf("inserisci un value: ");
    scanf("%d", &value);
    postInsert(&ptr,value);

    printf("inserisci un value: ");
    scanf("%d", &value);
    postInsert(&ptr,value);



    printf("\n");
    printf("Lista dopo un inserimento in coda: ");
    visit(&ptr);

    int target;
    printf("\nproviamo una ricerca!");
    printf("che target vuoi cercare?: ");
    scanf("%d", &target);

    Boolean result = search(&ptr, target);

    if(result==1)printf("target trovato!\n\n");
    else printf("\ntarget NON trovato :(\n\n");

    printf("proviamo ora un inserimento in testa:\n");
        printf("inserisci un value: ");
        scanf("%d", &value);
        preInsert(&ptr,value);

    printf("\n");
    printf("lista dopo un inserimento in testa: ");
    visit(&ptr);

    printf("\nproviamo ora un inserimento ordinato(la lista deve essere ordinata bro):\n");
    printf("inserisci un value: ");
    scanf("%d", &value);
    ordInsert(&ptr,value);

    printf("\n");
    printf("lista dopo un inserimento in ordine: ");
    visit(&ptr);

    printf("\n\n");
    preDelete(&ptr);
    printf("lista dopo una cancellazione in testa: ");
    visit(&ptr);

    printf("\n\n");
    postDelete(&ptr);
    printf("lista dopo una cancellazione in coda: ");
    visit(&ptr);


    return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  FUNCTION DECLARATION:

Boolean init(struct Linkedlist *ptr, int size){
    ptr->buffer = (struct record *)malloc(sizeof(struct record) * size);
    ptr->size = size;
    ptr->first = size;
    ptr->free = 0;
    for(int i=0; i<size; i++)
        ptr->buffer[i].next = i + 1;
}

Boolean preInsert(struct Linkedlist *ptr, int value){
//controllo che la lista non sia piena
    if(ptr->free != ptr->size){
        int new = ptr->free;
        ptr->free = ptr->buffer[ptr->free].next;
        ptr->buffer[new].value = value;
        ptr->buffer[new].next = ptr->first;
        ptr->first = new;

        return TRUE;
    }
    return FALSE;
}

Boolean postInsert(struct Linkedlist *ptr, int value){
//controllo che la lista non sia piena
    int new, *index;
    if(ptr->free != ptr->size){
        new = ptr->free;
        index = &ptr->first;

        while(*index != ptr->size)
            index = &(ptr->buffer[*index].next);

        *index = new;
        ptr->free = ptr->buffer[new].next;
        ptr->buffer[new].value = value;
        ptr->buffer[new].next = ptr->size;
        return TRUE;
    }
    return FALSE;
}

Boolean ordInsert(struct Linkedlist *ptr, int value){
    Boolean found = FALSE;
    int moved, * position;

    if ( ptr->free != ptr->size ) { // lista non piena
        printf("\ninsert values %d",value);
        moved = ptr->free;
        ptr->free = ptr->buffer[ptr->free].next;
        position = &(ptr->first);
        while ( *position != ptr->size && ptr->buffer[*position].value < value )
            position = &(ptr->buffer[*position].next);
        // insert
        ptr->buffer[moved].value = value;
        ptr->buffer[moved].next = *position;
        *position = moved;
        return TRUE;
    }
    return FALSE;
}

void visit(struct Linkedlist *ptr){
    int index = ptr->first;
    while(index != ptr->size){
        printf("%d ", ptr->buffer[index].value);
        index = ptr->buffer[index].next;
    }
}

Boolean preDelete(struct Linkedlist *ptr){
//controllo se la lista è vuota
    if(ptr->free != ptr->size){
        int moved = ptr->first;
        ptr->first = ptr->buffer[moved].next;
        ptr->buffer[moved].next = ptr->free;
        ptr->free = moved;
        return TRUE;
    }
    return FALSE;
}

Boolean postDelete(struct Linkedlist *ptr){
    if(ptr->first != ptr->size){
        int *pos = &ptr->first;
        while(ptr->buffer[*pos].next != ptr->size){
            pos = &ptr->buffer[*pos].next;
        }
        ptr->buffer[*pos].next = ptr->free;
        ptr->free = *pos;
        *pos = ptr->size;

        return TRUE;
    }
    return FALSE;
}

Boolean search(struct Linkedlist *ptr, int target){
    int index = ptr->first;
    Boolean found = FALSE;
    while(!found && index != ptr->size){
        if(ptr->buffer[index].value == target)
            found = TRUE;

        index = ptr->buffer[index].next;
    }
    return found;
}
