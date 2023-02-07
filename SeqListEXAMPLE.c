
#include <stdio.h>
#include <stdlib.h>
typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0

struct Seqlist{
    int *buffer;
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
Boolean search(struct Seqlist *ptr, int target);

int main(void){
struct Seqlist list1;
int size;
    printf("inserisci size: \n");
    scanf("%d", &size);
    init(&list1, size);
    visit(&list1);
    for (int i = 0; i < size; ++i) {
        postInsert(&list1,i);
        printf("%d ", i);
    }
    printf("  l'elemento uguale a size-1 == tail\n");
    printf("\n");
    printf("lista dopo un inserimento in coda:\n");
    visit(&list1);

    int target;
    printf("\nProviamo una ricerca!");
    printf("\nche target vuoi cercare?: ");
    scanf("%d", &target);

    Boolean result = search(&list1, target);

    if(result==1)printf("target trovato!\n");
    else printf("\ntarget NON trovato :(");
    if(result==0 && target==size-1) printf(" in quanto target==tail==position==head\n");


    preDelete(&list1);
    printf("\nlista dopo una cancellazione in testa:\n");
    visit(&list1);
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