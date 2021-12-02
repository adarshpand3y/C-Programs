#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

//Insert Element At the End
void insertAtEnd(struct node** head,int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if(*head==NULL){
        *head = temp;
        return;
    }
    struct node* cur = *head;
    
    while(cur->next!=NULL){
        cur = cur->next;
    }
    temp->prev = cur;
    cur->next = temp;
    return;
}

//Insert Element At the Beginning
void insertAtBegin(struct node** head,int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if(*head==NULL){
        *head = temp;
        return;
    }else{
        temp->next = *head;
        (*head)->prev = temp;
        *head = temp;
    }

}
//Insert Element at a specific index
void insertAtPosition(struct node** head,int data,int pos){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if(*head==NULL){
        *head = temp;
        return;
    }
    struct node* cur = *head;
    for(int i=1;i<pos;i++){
        cur = cur->next;
    }
    cur->prev->next = temp;
    temp->prev = cur->prev;
    cur->next->prev = temp;
    temp->next = cur->next; 

}
//Delete From the Begin
void deleteAtBegin(struct node** head){
    if(*head==NULL){
        printf("Linked List is Empty !!!!");
        return;
    }
    struct node* temp=*head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
}

//Delete from the End
void deleteAtEnd(struct node** head){
    if(*head==NULL){
        printf("Linked List is Empty !!!!");
        return;
    }
    struct node* temp=*head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

//Delete from a specific Position
void deleteAtPos(struct node** head,int pos){
    if(*head==NULL){
        printf("Linked List is Empty !!!!");
        return;
    }
    struct node* cur = *head;
    for(int i=1;i<pos;i++){
        cur = cur->next;
    }
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    free(cur);
    
    
}

//Print the Linked List
void printList(struct node* head){
    if(head==NULL){
        printf("List is Empty!!");
    }
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }printf("NULL");
}

int main()
{
    struct node* head = NULL;
    int v;
    printf("Enter 5 values\n");
    for(int i=0;i<5;i++){
        scanf("%d",&v);
        insertAtEnd(&head,v);
    }
    printf("\n\nInsert element at the End>\n");
    printList(head);
    printf("\n\nInsert element at the Beginning>\n");
    insertAtBegin(&head,50);
    printList(head);

    printf("\n\nOur new LinkedList\n");
    printList(head);
    printf("\n\nInsert element at a Specific Position>(Here the position is 3)\n");
    insertAtPosition(&head,45,3);
    printList(head);
    
    printf("\n\nDelete element from the Beginning>\n");
    deleteAtBegin(&head);
    printList(head);

    printf("\n\nDelete element from the End>\n");
    deleteAtEnd(&head);
    printList(head);

    printf("\n\nDelete element from the Specific Position>(Here the position is 3)\n");
    deleteAtPos(&head,3);
    printList(head);
    return 0;
}
