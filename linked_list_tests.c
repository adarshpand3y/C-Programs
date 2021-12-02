/* #include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int size = 100;

int isFull(struct node *top)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct node *push(struct node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow!!!");
    }
    else
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        size++;
        return top;
    }
}

void pop(struct node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is Empty ");
    }
    struct node *temp = top;
    int x = temp->data;
    top = top->next;
    free(temp);
    size--;
}

int stackTop(struct node *top)
{
    return top->data;
}

void Display(struct node *temp)
{

    while (temp != NULL)
    {
        printf("Element : %d \n", temp->data);
        temp = temp->next;
    }
}

int main(int argc, char const *argv[])
{
    struct node *top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    printf("%d\n", size);
    
    Display(top);
    pop(top);
    // Display(top);
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
int size = 0;

int isEmpty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct node *top)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct node *push(struct node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow!!!");
    }
    else
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        size++;
        return top;
    }
}

int pop(struct node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int stackTop(struct node *top)
{
    return top->data;
}

void Display(struct node *temp)
{
    while (temp != NULL)
    {
        printf("Element : %d \n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct node *top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    printf("%d\n", size);
    Display(top);

    pop(&top);
    Display(top);
    return 0;
}