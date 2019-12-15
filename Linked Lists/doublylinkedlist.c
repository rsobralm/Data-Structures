#include <stdio.h>
#include <stdlib.h>


struct Node { 
    int data; 
    struct Node* prev;
    struct Node* next; 
}; 

struct List {
    struct Node* head;
    struct Node* tail;
    int size;
};

void append(struct List * list , int value){
    
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if(list->tail == NULL){
        list->tail = newNode;
        list->head = list->tail;
        list->tail->data = value;
        list->tail->next = NULL;
        list->tail->prev = NULL;
        list->size = 1;
    }
    else{
        newNode->data = value;
        newNode->prev = list->tail;
        newNode->next = NULL;
        list->tail->next = newNode;
        list->tail = newNode;
        list->size++;
    }
}

void prepend(struct List *list , int value){
    
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if(list->head == NULL){
        list->head = newNode;
        list->tail = list->head;
        list->head->data = value;
        list->head->next = NULL;
        list->head->prev = NULL;
        list->size = 1;
    }
    else{
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
        list->size++;
    }
}

void insertAfter(struct List * list, struct Node * node, int value){

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if(node == list->tail){
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->size++;
    }
    else if(node == list->head->prev){
        newNode ->data = value;
        newNode->next = list->head;
        newNode->prev = NULL;
        list->head->prev = newNode;
        list->size++;
    }else{
        newNode->data = value;
        newNode->next = node->next;
        newNode->prev = node;
        node->next->prev = newNode;
        node->next = newNode;
        list->size++;
    }
    
}

void splitSortedList(struct List *list, struct Node ** n0, struct Node ** n1){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode = list->head;
    *n0 = newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode = list->tail;
    *n1 = newNode;
    //(*n1)->next = (*n1)->prev;
    //(*n1)->prev = NULL;

    for(int i = 1; i < list->size; i++){
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode = (*n0)->next;
        (*n0)->next = newNode;
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode = (*n1)->prev;
        //newNode->prev = (*n1)->next;
        (*n1)->prev = newNode;
    }
}

struct Node * search(struct List *list, int value){
    struct Node * dummy = list->head;
    for(int i = 0; i < list->size; i++){
        if(dummy->data == value)
            return (dummy);
        dummy = dummy->next;
    }
    exit(1);
}

void delete(struct List *list, struct Node *node){

    if(list->head == NULL || node == NULL)
        exit(1);
    
    if(list->head == node)
        list->head = node->next;

    if(node->next != NULL) // caso não for o ultimo no
        node->next->prev = node->prev;

    if(node->prev != NULL) // caso nao for o primeiro
        node->prev->next = node->next;
        
    list->size--;
    free(node);
}

void printList(struct List *list){ 
    struct Node* node = list->head;
    for(int i = 0; i < list->size; i++){ 
        printf("%d ", node->data); 
        node = node->next; 
    } 
}

void printSinglyList(struct Node *node){ 
    while (node != NULL){ 
        printf("%d ", node->data); 
        node = node->next; 
    } 
}

/*void printSinglyList2(struct Node *node){ 
    while (node != NULL){ 
        printf("%d ", node->data); 
        node = node->prev; 
    } 
}*/


int main(int argc, char **argv){
    struct Node * n0 = NULL;
    struct Node * n1 = NULL;
    struct Node * test = NULL;
    struct List *l0 = (struct List*)malloc(sizeof(struct List));
    //prepend(l0, 10);
    //prepend(l0, 20);
    append(l0, 10);
    append(l0, 20);
    prepend(l0 , 0);
    printList(l0);
    printf("\n");
   // test = (struct Node*)malloc(sizeof(struct Node));
    //test = search(l0, 10);
    //printf("%d",test->data);
    delete(l0, l0->head);

    //insertAfter(l0, l0->tail, 25);
    //splitSortedList(l0, &n0, &n1);
    //printSinglyList(n0);
    
    //printSinglyList(n1);
    printList(l0);

return 0;
}