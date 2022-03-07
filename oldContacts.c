#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// TODO:-
// C - Done
// R - Done
// U
// D

struct Contact {
    unsigned long number;
    char name[50];
    struct Contact* next;
};

void showContacts(struct Contact* head) {
    if (head == NULL) {
        printf("Contact List Empty.");
    }
    while (head != NULL) {
        printf("%s\t%lu\n", head -> name, head->number);
        head = head->next;
    }
}

void swap(struct Contact* a, struct Contact* b)
{
    char tempName[50];
    strcpy(tempName, a->name);
    int tempNum = a->number;
    strcpy(a->name, b->name);
    a->number = b->number;
    strcpy(b->name, tempName);
    b->number = tempNum;
}

void bubbleSort(struct Contact* head)
{
    int swapped, i;
    struct Contact* ptr1;
    struct Contact* lptr = NULL;

    /* Checking for empty list */
    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (strcmp(ptr1->name, ptr1->next->name) > 0) { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

struct Contact* updateContact(struct Contact* head) {
    struct Contact* originalHead = head;
    char conName[50];
    printf("Enter the name of the contact to update: ");
    scanf("%s", &conName);
    while(head != NULL) {
        if (strcmp(head->name, conName) == 0) {
            printf("Enter the number to update: ");
            int num;
            scanf("%d", &num);
            head->number = num;
            break;
        }
    }
    return originalHead;
}

// struct Contact* createContact(struct Contact* head) {
//     struct Contact* originalHead = head;
//     int isUnique = 1;
//     char ContactName[50];
//     printf("Enter the name of the Contact: ");
//     gets(ContactName);
//     if (head == NULL) {
//         struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));
//         strcpy(head->name, ContactName);
//         printf("Enter number to save: ");
//         int num;
//         scanf("%lu", &num);
//         head->number = num;
//         return newContact;
//     }
//     else {
//         while (head != NULL) {
//             int res = strcmp(head->name, ContactName);
//             head = head->next;
//             if(res == 0) {
//                 isUnique = 0;
//                 break;
//             }
//             if (res > 0) {
//                 struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));
//                 strcpy(head->name, ContactName);
//                 printf("Enter number to save: ");
//                 int num;
//                 scanf("%lu", &num);
//                 head->number = num;
//                 newContact -> next = head->next;
//                 head->next = newContact;
//                 return originalHead;
//             }
//             else {
//                 if (head -> next == NULL) {
//                     struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));
//                     strcpy(head->name, ContactName);
//                     printf("Enter number to save: ");
//                     int num;
//                     scanf("%lu", &num);
//                     head->number = num;
//                     newContact -> next = head->next;
//                     head->next = newContact;
//                     return originalHead;
//                 }
//             }
//         }
//     }
// }

struct Contact* createContact(struct Contact* head) {
    char ContactName[50];
    printf("Enter the name of the Contact: ");
    scanf("%s", &ContactName);
    struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));
    strcpy(newContact->name, ContactName);
    printf("Enter number to save: ");
    int num;
    scanf("%lu", &num);
    newContact->number = num;
    newContact->next = head;
    printf("Contact Saved Successfully");
    return newContact;
}

struct Contact* deleteContact(struct Contact* head) {
    printf("deleting Contact");
}

int main() {
    struct Contact* head = NULL;
    while (1) {
        printf("\n");
        printf("Welcome to Contact System using Linked Lists\n");
        printf("1: Show all Contacts\n");
        printf("2: Add a Contact\n");
        printf("3: Update a Contact\n");
        printf("4: Delete a Contact\n");
        printf("5: Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                showContacts(head);
                break;
            case 2:
                head = createContact(head);
                bubbleSort(head);
                break;
            case 3:
                head = updateContact(head);
                break;
            case 4:
                head = deleteContact(head);
                break;
            case 5:
                printf("Exit");
                return 0;
            default:
                printf("Wrong choice");
        }
        printf("\n");
    }
    return 0;
}