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

void printList(struct List *list){ 
    struct Node* node = list->head;
    for(int i = 0; i < list->size; i++){ 
        printf("%d ", node->data); 
        node = node->next; 
    } 
}

int main(int argc, char **argv){
    struct Node * n0 = NULL;
    struct List *l0 = (struct List*)malloc(sizeof(struct List));
    //prepend(l0, 10);
    //prepend(l0, 20);
    append(l0, 20);
    append(l0, 30);
    prepend(l0 , 0);
    //append(l0, 40);
    insertAfter(l0, l0->tail, 25);

    printList(l0);

return 0;
}