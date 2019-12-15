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

struct Node* mergeList(struct Node *n1, struct Node *n2){
    struct Node dummy;
    struct Node *tail = &dummy;
    dummy.next = NULL;

    while(1){
        if(n1 == NULL){
            tail->next = n2;
            break;
        }
        else if(n2 == NULL){
            tail->next = n1;
            break;
        }
        if(n1->data <= n2->data){
            struct Node *new = n1;
            if(new != NULL){
                n1 = new->next;
                new->next = tail->next;
                tail->next = new;
            }
        }
        else{
            struct Node *new = n2;
            if(new != NULL){
                n2 = new->next;
                new->next = tail->next;
                tail->next = new;
            }
        } 
        tail = tail->next;
    }
    return (dummy.next);
}


int main(int argc, char **argv){
    

    struct Node *test = NULL;
    struct Node *t2 = NULL;
    struct Node *t3 = NULL;
    append(&test, 10);
    append(&test, 20);
    //insertAfter(test->next, 50);
    append(&test, 30);
    append(&test,40);
   
    append(&t2, 15);
    append(&t2, 25);
    append(&t2, 35);
    append(&t2,45);

    printList(test);
    printf("\n");
    printList(t2);
    printf("\n");
    t3 = mergeList(test,t2);

    printList(t3);


    //printf("%s","teste");
    return 0;
}