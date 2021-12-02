#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void displayList(struct node* head) {
    struct node* ptr = head;
    do {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while(ptr != head);
}

struct node* insertAtBegin(struct node* head, int x) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = x;
    struct node* ptr = head->next;
    while (ptr->next != head) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = head;
    head = newNode;
    return head;
}

void insertAtEnd(struct node* head, int x) {
    struct node* ptr = head->next;
    while (ptr->next != head) {
        ptr = ptr->next;
    }
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    ptr->next = newNode;
    newNode->data = x;
    newNode->next = head;
}

void insertAtIndex(struct node* head, int index, int x) {
    struct node* currNode = head;
    struct node* nextNode = head->next;
    int i=0;
    while(i != index-1) {
        currNode = currNode->next;
        nextNode = nextNode->next;
        i++;
    }
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = x;
    currNode->next = newNode;
    newNode->next = nextNode;
}

void insertAfterIndex(struct node *head, int index, int x)
{
    struct node *currNode = head;
    struct node *nextNode = head->next;
    int i = 0;
    while (i != index)
    {
        currNode = currNode->next;
        nextNode = nextNode->next;
        i++;
    }
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    currNode->next = newNode;
    newNode->next = nextNode;
}

struct node* deleteFromBegin(struct node* head) {
    struct node* ptr = head;
    do {
        ptr = ptr->next;
    } while (ptr->next != head);
    ptr->next = head->next;
    free(head);
    head = ptr->next;
    return head;
}

void deleteFromEnd(struct node* head) {
    struct node* prevNode = head;
    struct node* nextNode = prevNode->next;
    do {
        prevNode = prevNode->next;
        nextNode = nextNode->next;
    } while (nextNode->next != head);
    free(nextNode);
    prevNode->next = head;
}

void deleteAtIndex(struct node* head, int index) {
    struct node* prevNode = head;
    struct node* nextNode = prevNode->next;
    int i=0;
    while(i < index-1) {
        prevNode = prevNode->next;
        nextNode = nextNode->next;
        i++;
    }
    prevNode->next = nextNode->next;
    free(nextNode);
}

void deleteAfterIndex(struct node *head, int index)
{
    struct node *prevNode = head;
    struct node *nextNode = prevNode->next;
    int i = 0;
    while (i < index)
    {
        prevNode = prevNode->next;
        nextNode = nextNode->next;
        i++;
    }
    prevNode->next = nextNode->next;
    free(nextNode);
}

void deleteByValue(struct node* head, int value) {
    // The value to delete should not be the first one
    struct node* prevNode = head;
    struct node* nextNode = prevNode->next;
    do {
        prevNode = prevNode->next;
        nextNode = nextNode->next;
        if (nextNode->next == head) {
            printf("Value %d not found.\n", value);
            return;
        }
    } while (nextNode->data != value);
    prevNode->next = nextNode->next;
    free(nextNode);
}

int main()
{
    // Creating first node of the circular linked list.
    struct node* head = (struct node*) malloc(sizeof(struct node));
    head->data = 5;
    head->next = head;

    // Insertion Operations.
    head = insertAtBegin(head, 4);
    head = insertAtBegin(head, 3);
    head = insertAtBegin(head, 2);
    head = insertAtBegin(head, 1);
    insertAtEnd(head, 6);
    insertAtEnd(head, 7);
    insertAtEnd(head, 8);
    insertAtIndex(head, 4, 12);
    insertAtIndex(head, 4, 15);
    insertAfterIndex(head, 4, 20);
    insertAfterIndex(head, 4, 30);

    // Deletion Operations.
    head = deleteFromBegin(head);
    deleteFromEnd(head);
    deleteAtIndex(head, 3);
    deleteByValue(head, 155);
    deleteByValue(head, 5);
    deleteByValue(head, 6);

    // Displaying the list.
    displayList(head);
    return 0;
}