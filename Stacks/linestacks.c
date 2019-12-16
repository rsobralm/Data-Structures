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

void line_push(struct Stack *s1, struct Stack *s2 , char c){
    if(s1->top < 5)
        push(s1,c);
    else
        push(s1,c);
            
    
}

char line_pop(struct Stack *s1, struct Stack *s2){
    char c;
    while(s1->top >= 0){
        push(s2,s1->word[s1->top]);
        s1->top--;
    }
    c = pop(s2);
    //s2->top--;

    return c;
}

int main(){

    struct Stack s1 = {.top = -1}; // inicializa stack
    struct Stack s2 = {.top = -1}; // inicializa stack
    char eoq[5] = "toraa";
    int i;

    /*for(i = 0; i < 5; i++){
        push(&s,eoq[i]);
    }
    for(i = 0; i < 5; i++){
        printf("%c",pop(&s));
    }*/
    line_push(&s1,&s2,'t');
    line_push(&s1,&s2,'o');
    line_push(&s1,&s2,'r');
    line_push(&s1,&s2,'a');
    printf("%c",line_pop(&s1,&s2));
    printf("%c",line_pop(&s1,&s2));

    return 0;
}