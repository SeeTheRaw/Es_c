
#include <stdio.h>
#include <stdlib.h>                                                      //        ******
typedef unsigned short int Boolean;                                     //      *****  *****
#define TRUE 1                                                         //    *****        *****
#define FALSE 0                                                       //  *****              *****
                                                                     //    *****          *****
struct Seqlist{                                                     //       *****      *****
    int *buffer;                                                   //           *** ****
    int head;
    int tail;
    int size;
};
Boolean init(struct Seqlist *ptr, int size);
Boolean preInsert(struct Seqlist *ptr, int value);
Boolean postInsert(struct Seqlist *ptr, int value);
void visit(struct Seqlist *ptr);
Boolean preDelete(struct Seqlist *ptr);
Boolean postDelete(struct Seqlist *ptr);
Boolean ord_insert(struct Seqlist * ptr, int value);
Boolean search(struct Seqlist *ptr, int target);

int main(void){
struct Seqlist ptr;
int size;
    printf("inserisci size: \n");
    scanf("%d", &size);
    init(&ptr, size);
    visit(&ptr);
    for (int i = 0; i < size; ++i) {
        postInsert(&ptr, i);
        printf("%d ", i);
    }
    printf("  l'elemento uguale a size-1 == tail\n");
    printf("\n");
    printf("lista dopo una serie ordinata di inserimenti in coda:\n");
    visit(&ptr);

    int target;
    printf("\nProviamo una ricerca!");
    printf("\nche target vuoi cercare?: ");
    scanf("%d", &target);

    Boolean result = search(&ptr, target);

    if(result==1)printf("target trovato!\n");
    else printf("\ntarget NON trovato :(");
    if(result==0 && target==size-1) printf(" in quanto target==tail==position==head\n");


    preDelete(&ptr);
    printf("\nlista dopo una cancellazione in testa:\n");
    visit(&ptr);

    postDelete(&ptr);
    printf("\nlista dopo una cancellazione in coda:\n");
    visit(&ptr);

    int value;
    printf("proviamo ora un inserimento ordinato!\n\n");
    printf("inserisci un value: \n");
    scanf("%d", &value);
    ord_insert(&ptr,value);
    printf("\nlista dopo un inserimento ordinato:\n");
    visit(&ptr);


    return 0;

}





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  FUNCTION DECLARATION:


Boolean init(struct Seqlist *ptr, int size){
    ptr->buffer=(int *) malloc(sizeof(int)*size);
    ptr->size=size;
    ptr->head=0;
    ptr->tail=0;
    if(ptr->buffer != NULL){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
Boolean preInsert(struct Seqlist *ptr, int value){
    //controllo se la lista è piena
    if(ptr->head != (ptr->tail+1)%ptr->size){
        ptr->head = (ptr->head - 1 + ptr->size)%ptr->size;
        ptr->buffer[ptr->head] = value;
        return TRUE;
    }
    return FALSE;
}
Boolean postInsert(struct Seqlist *ptr, int value){
    //controllo se la lista è piena
    if(ptr->head != (ptr->tail + 1)%ptr->size){
        ptr->buffer[ptr->tail] = value;
        ptr->tail = (ptr->tail + 1)%ptr->size;
        return TRUE;
    }
    return FALSE;
}
void visit(struct Seqlist *ptr){
    int index = ptr->head;
    while(index != ptr->tail){
        printf("%d\n", ptr->buffer[index]);
        index = (index + 1)%ptr->size;
    }
}
Boolean preDelete(struct Seqlist *ptr){
    //controllo se la lista è vuota
    if(ptr->head != ptr->tail){
        ptr->head = (ptr->head + 1)%ptr->size;
        return TRUE;
    }
    return FALSE;
}
Boolean postDelete(struct Seqlist *ptr){
    //controllo se la lista è vuota
    if(ptr->head != ptr->tail){
        ptr->tail = (ptr->tail - 1 + ptr->size) % ptr->size;
        return TRUE;
    }
    return FALSE;
}
Boolean ord_insert(struct Seqlist * ptr, int value)
{
    int position, count, N;

    if (ptr->head!=(ptr->tail+1)%ptr->size) {   // not full
        printf("\nInserted value: %d",value);
        position = ptr->head;
        while ( position != ptr->tail && ptr->buffer[position] <= value )
            position = (position + 1)%ptr->size;
        // number of elements in the list
        N = (ptr->tail - ptr->head + ptr->size)%ptr->size;
        if( (position - ptr->head + ptr->size)%ptr->size > N/2 ) {
            // there are less elements to move from position to tail, so move from the tail
            printf("\nmove elements starting from the tail clockwise");
            // move the elements from position to tail-1 clockwise
            for (count = ptr->tail; count != position; count=(count-1+ptr->size)%ptr->size)
                ptr->buffer[count] = ptr->buffer[(count - 1 + ptr->size) % ptr->size];
            // insert the new value in position
            ptr->buffer[position] = value;
            // update the tail
            ptr->tail = (ptr->tail + 1) % ptr->size;
        }
        else {
            // there are less elements to move from head to position-1, so move from the head
            printf("\nmove elements starting from the head counterclockwise");
            // move the elements from head to position-1 counterclockwise
            for (count = ptr->head; count != position; count = (count + 1)%ptr->size)
                ptr->buffer[(count-1+ptr->size)%ptr->size] = ptr->buffer[count];
            // insert the new value in position-1
            ptr->buffer[(position-1+ptr->size)%ptr->size] = value;
            // update the head
            ptr->head = (ptr->head - 1 + ptr->size) % ptr->size;
        }
        return TRUE;
    }
    else
        return FALSE;
}

Boolean search(struct Seqlist *ptr, int target){
    int position = ptr->head;
    Boolean found = FALSE;
    while(!found && position != ptr->tail){
        if(ptr->buffer[position] == target){
            found = TRUE;
        }
        position = (++position)%ptr->size;
    }
    return found;
}
