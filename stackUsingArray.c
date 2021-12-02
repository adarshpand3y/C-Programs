#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int* arr;
};

int isEmpty(struct stack* s) {
    if(s->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull(struct stack *s)
{
    if (s->top == s->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct stack* s;
    s->size = 20;
    s->top = -1;
    s->arr = (int*)malloc(s->size * sizeof(int));
    s->arr[0] = 10;
    s->top++;
    if(isEmpty(s)) {
        printf("Stack is empty");
    }
    else {
        printf("Stack is not empty");
    }
    return 0;
}