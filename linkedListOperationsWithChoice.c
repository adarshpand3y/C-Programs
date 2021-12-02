#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

void displayList(struct node* head) {
    if (head == NULL) {
        printf("List empty.");
    }
    while (head != NULL)
    {
        printf("%d\n", head -> data);
        head = head->next;
    }
}

struct node* insertAtBegin(struct node* head, int x) {
    struct node* newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> data = x;
    newNode -> next = head;
    return newNode;
}

void insertAtEnd(struct node *head, int x) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode ->data = x;
    newNode ->next = NULL;
    while(head->next != NULL) {
        head = head->next;
    }
    head->next = newNode;
}

void insertAtIndex(struct node* head, int index, int x) {
    int i=0;
    while (i != index-1) {
        if (head->next != NULL) {
            head = head->next;
            i++;
        }
        else {
            printf("Could not insert data %d at index %d.\n", x, index);
            return;
        }
    }
    struct node* newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = head->next;
    head->next = newNode;
}

void insertAfterIndex(struct node* head, int index, int x) {
    int i=0;
    while (i != index)
    {
        if (head->next != NULL) {
            head = head->next;
            i++;
        }
        else {
            printf("Could not insert data %d at index %d.\n", x, index);
            return;
        }
    }
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = head->next;
    head->next = newNode;
}

struct node* deleteFromBegin(struct node* head) {
    struct node* nextNode = head->next;
    free(head);
    return nextNode;
}

void deleteFromEnd(struct node* head) {
    struct node* currNode = head;
    struct node* nextNode = head->next;
    while (nextNode->next != NULL) {
        currNode = currNode->next;
        nextNode = nextNode->next;
    }
    currNode->next = NULL;
    free(nextNode);
}

void deleteAtIndex(struct node* head, int index) {
    struct node* currNode = head;
    struct node* nextNode = head->next;
    int i=0;
    while (i != index - 1)
    {
        if (nextNode -> next != NULL)
        {
            currNode = currNode->next;
            nextNode = nextNode->next;
            i++;
        }
        else
        {
            printf("Could not delete the node at index %d.\n", index);
            return;
        }
        currNode->next = nextNode->next;
        free(nextNode);
    }
}

void deleteAfterIndex(struct node* head, int index) {
    struct node *currNode = head;
    struct node *nextNode = head->next;
    int i = 0;
    while (i != index)
    {
        if (nextNode->next != NULL)
        {
            currNode = currNode->next;
            nextNode = nextNode->next;
            i++;
        }
        else
        {
            printf("Could not delete the node at index %d.\n", index);
            return;
        }
    }
    currNode->next = nextNode->next;
    free(nextNode);
}

void deleteByValue(struct node* head, int value) {
    // The value to delete should not be the first one
    struct node* currNode = head;
    struct node* nextNode = head->next;
    do {
        currNode = currNode->next;
        nextNode = nextNode->next;
        if (nextNode->next == NULL) {
            printf("Value %d not found.\n", value);
            return;
        }
    } while (nextNode->data != value);
    currNode->next = nextNode->next;
    free(nextNode);
}

int main()
{
    // Creating first node.
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 5;
    head->next = NULL;

    // Insertion Operations.
    head = insertAtBegin(head, 4);
    head = insertAtBegin(head, 3);
    head = insertAtBegin(head, 2);
    head = insertAtBegin(head, 1);
    insertAtEnd(head, 6);
    insertAtEnd(head, 7);
    insertAtEnd(head, 8);
    insertAtEnd(head, 9);
    insertAtEnd(head, 10);
    insertAtIndex(head, 3, 50);
    insertAfterIndex(head, 3, 60);

    // Deletion Operations.
    head = deleteFromBegin(head);
    deleteFromEnd(head);
    deleteAtIndex(head, 1);
    deleteAfterIndex(head, 3);
    deleteByValue(head, 6);

    // Displaying the list.
    displayList(head);
    int ch, data, position;
    while (1) {
        printf(" 1: Print List\n");
        printf(" 2: Insert At Beginning\n");
        printf(" 3: Insert At Index\n");
        printf(" 4: Insert After Index\n");
        printf(" 5: Insert At End\n");
        printf(" 6: Delete From Beginning\n");
        printf(" 7: Delete At Index\n");
        printf(" 8: Delete After Index\n");
        printf(" 9: Delete From End\n");
        printf("10: Exit\n");
        printf("Enter your choice1: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            displayList(head);
            break;
        
        case 2:
            printf("Enter data value: ");
            scanf("%d", &data);
            head = insertAtBegin(head, data);
            break;
        case 3:
            printf("Enter data value: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &position);
            insertAtIndex(head, position, data);
            break;

        default:
            break;
        }
        break;
    }
    return 0;
}