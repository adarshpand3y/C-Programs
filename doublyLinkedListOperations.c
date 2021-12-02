#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};

void displayListUsingHead(struct node* head) {
    if (head == NULL) {
        printf("List empty.");
        return;
    }
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

void displayListUsingTail( struct node* tail) {
    if (tail == NULL) {
        printf("List empty in reverse direction.");
        return;
    }
    while (tail != NULL) {
        printf("%d\n", tail->data);
        tail = tail->prev;
    }
}

struct node* insertAtBeginUsingHead(struct node* head, int x) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->prev = NULL;
    newNode->data = x;
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

struct node* insertAtBeginUsingTail(struct node *tail, int x)
{
    while (tail->prev != NULL)
    {
        tail = tail->prev;
    }
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->prev = NULL;
    newNode->data = x;
    newNode->next = tail;
    tail->prev = newNode;
    return newNode;
}

struct node* insertAtEndUsingHead(struct node* head, int x) {
    while(head->next != NULL) {
        head = head->next;
    }
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->prev = head;
    newNode->data = x;
    newNode->next = NULL;
    head->next = newNode;
    return newNode;
}

struct node* insertAtEndUsingTail(struct node* tail, int x) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->prev = tail;
    newNode->data = x;
    newNode->next = NULL;
    tail->next = newNode;
    return newNode;
}

void insertAtIndexUsingHead(struct node* head, int index,  int x) {
    int i=0;
    while(i< index-1) {
        head = head->next;
        i++;
    }
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->prev = head;
    newNode->data = x;
    newNode->next = head->next;
    struct node* nextNode = head->next;
    nextNode->prev = newNode;
    head->next = newNode;
}

void insertAfterIndexUsingHead(struct node *head, int index, int x)
{
    int i = 0;
    while (i < index)
    {
        head = head->next;
        i++;
    }
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->prev = head;
    newNode->data = x;
    newNode->next = head->next;
    struct node* nextNode = head->next;
    nextNode->prev = newNode;
    head->next = newNode;
}

void insertAtIndexUsingTail(struct node* tail, int index, int x) {
    int i=0;
    while (i < index-1) {
        tail = tail->prev;
        i++;
    }
    printf("Reached: %d\n", tail->data);
    struct node* newNode = (struct node *)malloc(sizeof(struct node));
    newNode->prev = tail->prev;
    newNode->data = x;
    newNode->next = tail;
    struct node* prevNode = tail->prev;
    prevNode->next = newNode;
    tail->prev = newNode;
}

void insertAfterIndexUsingTail(struct node *tail, int index, int x)
{
    int i = 0;
    while (i < index)
    {
        tail = tail->prev;
        i++;
    }
    printf("Reached: %d\n", tail->data);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->prev = tail->prev;
    newNode->data = x;
    newNode->next = tail;
    struct node *prevNode = tail->prev;
    prevNode->next = newNode;
    tail->prev = newNode;
}

int main()
{
    // Creating first node of the doubly linked list.
    struct node* head = (struct node *)malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 5;
    head->next = NULL;

    // Insertion Operators
    head = insertAtBeginUsingHead(head, 4);
    head = insertAtBeginUsingHead(head, 3);
    head = insertAtBeginUsingHead(head, 2);
    head = insertAtBeginUsingHead(head, 1);

    struct node* tail = insertAtEndUsingHead(head, 6);
    head = insertAtBeginUsingTail(tail, 111);
    tail = insertAtEndUsingHead(head, 7);
    tail = insertAtEndUsingHead(head, 8);
    tail = insertAtEndUsingTail(tail, 123);

    insertAtIndexUsingHead(head, 3, 222);
    insertAfterIndexUsingHead(head, 3, 333);

    insertAtIndexUsingTail(tail, 3, 777);
    insertAfterIndexUsingTail(tail, 3, 888);

    displayListUsingHead(head);
    printf("\n\n");
    displayListUsingTail(tail);
    return 0;
}