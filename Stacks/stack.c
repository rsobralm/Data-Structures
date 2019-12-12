#include <stdio.h>
#include <stdlib.h>

struct Stack {
    char word[5];
    int top;
};

void push(struct Stack *s, char c){
    if(s->top < 5){
        s->top++;
        s->word[s->top] = c;
    }
    else{
        printf("%s", "stack overflow");
    }
}

char pop(struct Stack *s){
    if(s->top >= 0){
        char c = s->word[s->top];
        s->top--;
        return c;
    }
    else{
        printf("%s", "stack underflow");
        exit(1);
    }
}

int main(){

    struct Stack s = {.top = -1}; // inicializa stack
    char eoq[5] = "toraa";
    int i;

    for(i = 0; i < 5; i++){
        push(&s,eoq[i]);
    }
    for(i = 0; i < 5; i++){
        printf("%c",pop(&s));
    }


    return 0;
}