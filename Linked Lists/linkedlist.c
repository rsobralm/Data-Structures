#include <stdio.h>
#include <stdlib.h>


struct Node { 
    int data; 
    struct Node* next; 
}; 

struct List{
    struct node *head;
    int size;
};


void append(struct Node** node, int value){
    
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *node;

    newNode->data = value;
    newNode->next = NULL; // inserindo na ultima posicao, proximo ponteiro null

    if(*node == NULL){
        *node = newNode; // insere em lista vazia;
    }
    else{
        while(last->next != NULL) // percorre a lista e insere na ultima posicao O(n)
            last = last->next;

        last->next = newNode;
    }
}

void prepend(struct Node** node, int value){

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if(*node == NULL){  // insere em lista vazia;
        newNode->data = value;
        newNode->next = NULL;
        *node = newNode;
    }
    else{
        newNode->data = value;
        newNode->next = *node;
        *node = newNode;
    }
}

void insertAfter(struct Node* previous, int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if(previous == NULL){
        printf("erro, nó anterior nulo");
    }
    else{
        newNode->data = value;
        newNode->next = previous->next;
        previous->next = newNode;
    }


}

void printList(struct Node *node) 
{ 
    while (node != NULL){ 
        printf("%d ", node->data); 
        node = node->next; 
    } 
}


int main(int argc, char **argv){
    

    struct Node *test = NULL;
    append(&test, 10);
    append(&test, 20);
    insertAfter(test->next, 50);
    append(&test, 30);
    prepend(&test,40);
   
    struct Node *t2 = test;
    prepend(&test, 60);

    printList(test);
    printf("\n");
    printList(t2);
    //printf("%s","teste");
    return 0;
}