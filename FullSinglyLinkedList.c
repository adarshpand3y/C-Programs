#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
int sizeOfList=0;

// Insert Node At Specific positon------------------------------------------------>


void insertAtposition(struct node** head,int data,int pos){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if(pos<1){
        printf("Invalid position");
    }
    struct node* cur = *head;
    for(int i=1;i<pos;i++){
        cur = cur->next;
    }
    temp->next = cur->next;
    cur->next = temp;
    sizeOfList++;
}

//Insert Node at Beginning --------------------------------------->
void insertAtBegin(struct node** head,int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if(*head==NULL){
        *head = temp;
    }else{
        temp->next=*head;
        *head = temp;
    }
    sizeOfList++;
}

//Append Node at the End of the list------------------------------------------------>
void append(struct node** head,int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if(*head==NULL){
        *head = temp;
    }else{
        struct node* cur = *head;
        while(cur->next!=NULL){
            cur = cur->next;
        }
        cur->next = temp;
    }
    sizeOfList++;
}

//Print The Linked List -------------------------------------------------------->
void printList(struct node* head){
    if(head==NULL){
        printf("List is Empty !!");
    }
    struct node* temp = head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }printf("NULL");
}

//Delete Node from Beginning------------------------------------------------------->
void deleteFirst(struct node** head){
    if(*head==NULL){
        return;
    }
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
    sizeOfList--;
    return;
}
//Delete Node from End------------------------------------------------------->
void deleteLast(struct node** head){
    if(*head==NULL){
        return;
    }
    struct node* temp = *head;
    struct node* prev = NULL;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next=NULL;
    free(temp);
    sizeOfList--;
    return;
}
//Delete Node from a Specific Position------------------------------------------------------->
void deletePosition(struct node** head,int pos){
    if(*head==NULL){
        return;
    }
    struct node* temp = *head;
    struct node* prev = NULL;
    for(int i=1;i<pos;i++){
        prev = temp;
        temp=temp->next;
    }
    prev->next = temp->next;
    free(temp);
    sizeOfList--;
    return;
}


int main(int argc, char const *argv[])
{
    struct node* head = NULL;
    int v;
    for(int i=0;i<5;i++){
        scanf("%d",&v);
        append(&head,v);
    }
    printList(head);
    insertAtBegin(&head,25);
    printf("\n\nAfter insert at beginning -->\n");
    printList(head);
    insertAtposition(&head,10,3);
    printf("\n\nAfter insert at Position -->\n");
    printList(head);
    printf("\n\nAfter Delete first -->\n");
    deleteFirst(&head);
    printList(head);
    printf("\n\nAfter Delete Last -->\n");
    deleteLast(&head);
    printList(head);
    printf("\n\nAfter Delete at specific position -->\n");
    deletePosition(&head,3);
    printList(head);

    printf("\n\n Now Total Size of the Linked list ------>  %d",sizeOfList);


    return 0;
}
