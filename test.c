#include <stdio.h>
#include <stdlib.h>

/* Declaring a structure to create a node. */
struct node {
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start;
/* INSERTION OPERATIONS */
/*function to insert values from beginning of the the double linked list*/
void insertbeg(void) {
    int a;
    struct node *nn, *temp;
    /*allocating implicit memory to the node*/
    nn = (struct node *)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d", &nn->data);
    a = nn->data;
    if (start == NULL) { /*checking if List is empty*/
        nn->prev = nn->next = NULL;
        start = nn;
    } else {
        nn->next = start;
        nn->prev = NULL;
        start->prev = nn;
        start = nn;
    }
    printf("%d succ inserted \n", a);
}
/*function to insert values from the end of the linked list*/
void insertend(void) {
    int b;
    struct node *nn, *lp;
    nn = (struct node *)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d", &nn->data);
    b = nn->data;
    if (start == NULL) {
        /* assigning first node pointer to next nod pointer to delete a data from the starting of the node*/
        nn->prev = nn->next = NULL;
        start = nn;
    } else {
        lp = start;
        while (lp->next != NULL) {
            lp = lp->next;
        }
        nn->prev = lp;
        lp->next = nn;
        nn->next = NULL;
    }
    printf("%d succ inserted\n", b);
}
/*function to insert values from the middle of the linked list*/
void insertmid(void) {
    struct node *nn, *temp, *ptemp;
    int x, c;
    if (start == NULL) {
        printf("dll is empty\n");
        return;
    }
    printf("enter data before which nn is to be inserted\n");
    scanf("%d", &x);
    if (x == start->data) {
        insertbeg();
    }
    ptemp = start;
    temp = start->next;
    while (temp->next != NULL && temp->data != x) {
        ptemp = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%d does not exit\n", x);
    } else {
        /*allocating implicit memory to the node*/
        nn = (struct node *)malloc(sizeof(struct node));
        printf("enter data");
        scanf("%d", &nn->data);
        c = nn->data;
        nn->data;
        nn->prev = ptemp;
        nn->next = temp;
        ptemp->next = nn;
        temp->prev = nn;
        printf("%d succ inserted\n", c);
    }
}
/*end of insertion operation*/
/*deletion operation*/
void deletion() {
    struct node *pt, *t;
    int x;
    t = pt = start;
    if (start == NULL) {
        printf("dll is empty\n");
    }
    printf("enter data to be deleted:");
    scanf("%d", &x);
    if (x == start->data) {
        t = start;
        t = t->next;
        free(start);
        start = t;
        start = pt;
    } else {
        while (t->next != NULL && t->data != x) {
            pt = t; /*logic for traversing*/
            t = t->next;
        }
        if (t->next == NULL && t->data == x) {
            free(t);
            pt->next = NULL;
        } else {
            if (t->next == NULL && t->data != x)
                printf("data not found");
            else {
                pt->next = t->next;
                free(t);
            }
        } printf("%d is succ deleted\n", x);
    }
}

/* DISPLAYING LIST */
void display()
{
    struct node *temp;
    if (start == NULL)
        printf("stack is empty ");
    temp = start;
    while (temp->next != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

/* MAIN PROGRAM */
int main()
{
    int c, a;
    start = NULL;
    do {
        printf("1.insert\n2.delete\n3.display\n4.exit\nenter choice:");
        scanf("%d", &c);
        switch (c) {
        case 1:
            printf("1.insertbeg\n2.insertend\n3.insertmid\nenter choice:");
            scanf("%d", &a);
            switch (a) {
            case 1:
                insertbeg(); break;
            case 2:
                insertend(); break;
            case 3:
                insertmid(); break;
            }
            break;
        case 2:
            deletion(); break;
        case 3:
            display(); break;
        case 4:
            printf("program ends\n"); break;
        default:
            printf("wrong choice\n"); break;
        }
    } while (c != 4);
    return 0;
}