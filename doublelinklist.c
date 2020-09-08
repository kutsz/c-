
#include <stdio.h>
#include <malloc.h>

//----------------------------------------------------------------------
typedef struct Element {
    int value;
    struct Element* next;
    struct Element* prev;
} Element;

typedef struct List {
    Element* head;
    Element* tail;
} List;

void show(List* list);
void show_reverse(List* list);

void addElement(List* list, int value);

void delete(List* list);

//-------------------------------------------------
int main()
{

    int size;
    printf("Enter size of List (int): ");
    scanf("%d", &size);

    List* list = NULL;
    if (!list) {
        list = malloc(sizeof(List));
        list->head = NULL;
        list->tail = NULL;
    }


    for (int i = 0; i<size; i++) {
        addElement(list, i);
    }

    show(list);
    show_reverse(list);
    delete(list);

    return 0;
}

//--------------------------------------------------
void addElement(List* list, int value)
{
    Element* newEl = malloc(sizeof(Element));
    newEl->next = NULL;
    newEl->prev = NULL;
    newEl->value = value;


    if (list->head) {
        list->tail->next = newEl;
        newEl->prev = list->tail;
        list->tail = newEl;
    }
    else {
        list->head = newEl;
        list->tail = newEl;
    }

}


//----------------------------------------------------
void show(List* list)
{
    Element* Current = list->head;

    if (!list->head)
        printf("List is EMPTY\n");
    else {

        while (Current) {
            printf("%d ", Current->value);
            Current = Current->next;
        }
    }

    printf("\n");
}


 void show_reverse(List* list){
     Element* Current = list->tail;

     while (Current) {
         printf("%d ", Current->value);
         Current = Current->prev;
     }

    printf("\n");
 }



//--------------------------------------------
void delete(List* list)
{

    Element* Current = list->head;
    Element* tmp;

    if (!list->head)
        printf("List is EMPTY\n");
    else {
        while (Current) {
            tmp = Current;
            Current = Current->next;
            free(tmp);
        }
    }

    if (!Current)
        printf("List is DELETED\n");
}
//----------------------------------------------