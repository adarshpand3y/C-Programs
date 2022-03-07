#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Contact {
    unsigned long number;
    char name[50];
    struct Contact* next;
};

// a utility func, just to
// consume previous nextline character
// then, do a gets()
void _gets(char* str) {
    char newline;
    scanf("%c", &newline);
    gets(str);
}

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
    if (head == NULL) {
        printf("No Contacts to Update.");
        return head;
    }
    struct Contact* originalHead = head;
    char conName[50];
    printf("Enter the name of the contact to update: ");
    _gets(conName);
    while(head != NULL) {
        if (strcmp(head->name, conName) == 0) {
            char newName[50];
            printf("Enter the new name to update (Enter an uderscore to update number only): ");
            gets(newName);
            if (strcmp(newName, "_") != 0) {
                strcpy(head->name, newName);
            }
            printf("Enter the new number to update: ");
            int num;
            scanf("%d", &num);
            head->number = num;
            printf("Contact Updated Successfully!");
            return originalHead;
        }
        head = head->next;
    }
    printf("No contact with that name found.\n");
    printf("Please refine your search.");
    return originalHead;
}

struct Contact* createContact(struct Contact* head) {
    char ContactName[50];
    printf("Enter the name of the Contact: ");
    _gets(ContactName);
    struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));
    strcpy(newContact->name, ContactName);
    printf("Enter number to save: ");
    unsigned long num;
    scanf("%lu", &num);
    newContact->number = num;
    newContact->next = head;
    printf("Contact Saved Successfully");
    return newContact;
}

struct Contact* deleteContact(struct Contact* head) {
    if (head == NULL) {
        printf("Contact List is empty.");
        return head;
    }
    struct Contact* currentContact = head;
    char conName[50];
    printf("Enter the name of the contact to delete: ");
    _gets(conName);

    // special case for 1st node
    if (strcmp(currentContact->name, conName) == 0) {
        head = head->next;
        free(currentContact);
        printf("Contact deleted.\n");
        return head;
    }

    while(currentContact->next != NULL) {
        if (strcmp(currentContact->next->name, conName) == 0) {
            struct Contact* temp = currentContact->next;
            currentContact->next = currentContact->next->next;
            free(temp);
            printf("Contact deleted.\n");
            return head;
        }
        currentContact = currentContact->next;
    }
    printf("Contact could not be found.\n");
    return head;
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
        char choice[50];
        scanf("%s", &choice);
        if (strcmp(choice, "1") == 0) {
            showContacts(head);
        }
        else if (strcmp(choice, "2") == 0) {
            head = createContact(head);
            bubbleSort(head);
        }
        else if (strcmp(choice, "3") == 0) {
            head = updateContact(head);
        }
        else if (strcmp(choice, "4") == 0) {
            head = deleteContact(head);
        }
        else if (strcmp(choice, "5") == 0) {
            printf("Exit\n");
            return 0;
        }
        else {
            printf("Wrong Choice.\n");
        }
        printf("\n");
    }
    return 0;
}