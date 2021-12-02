#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

struct node *head,*tail = NULL;


//Insert element at End -------------------------------------->
void insertAtEnd(int val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next = temp;
    if(head == NULL){
        head = temp;
        tail = temp;
        temp->next = head;
    }else{
        tail->next = temp;
        tail = tail->next;
        tail->next = head;
    }
}
//Insert Element at Beginning ---------------------------------------->
void insertAtBegin(int val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next = temp;
    if(head == NULL){
        head = temp;
        tail = temp;
        temp->next = head;
    }else{
        tail->next = temp;
        temp->next = head;
        head = temp;
    }
}
//Insert At a Specific Position --------------------->
void insertAtPos(int val,int k){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next = temp;
    if(k<1){
        printf("Position doesn't exits");
    }
    if(head == NULL){
        head = temp;
        tail = temp;
        temp->next = head;
        printf("Position doesn't exits , but you created a new Linked List with your input ");
    }else{
        struct node* cur = head;
        for(int i=1;i<k-1;i++){
            cur = cur->next;
        }
        temp->next = cur->next;
        cur->next = temp;
    }
}




//Print the Linked List-------------------------------------->
void printList(){
    if(head==NULL){
        printf("List is Empty!!");
    }
    struct node* temp=head;
    do
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }while(temp->next!=head);
    printf("Head\n");
}
// void printList(){  
//     struct node *current = head;  
//     if(head == NULL){  
//         printf("List is empty");  
//     }  
//     else{  
//         printf("Nodes of the circular linked list: \n");  
//          do{  
//              //Prints each node by incrementing pointer.  
//             printf("%d ", current->data);  
//             current = current->next;  
//         }while(current != head);  
//         printf("\n");  
//     }  
// }

//delete From Begin ---------------------------->
void deleteBegin(){
    if(head==NULL){
        printf("List is already Empty!!");
        return;
    }
    struct node* temp=head;
    tail->next = head->next;
    head = head->next;
    free(temp);
}
//Delete from the End ----------------------------------->
void deleteEnd(){
    if(head==NULL){
        printf("List is already Empty!!");
        return;
    }
    struct node* temp=head;
    while(temp->next!=tail){
        temp = temp->next;
    }
    struct node* toDelete = tail;
    tail = temp;
    tail->next = head;
    free(toDelete);
}
//Delete from a Specific Position ------------------------------------->
void deletePos(int pos){
    if(head==NULL){
        printf("List is already Empty!!");
        return;
    }
    struct node* cur = head;
    struct node* prev = NULL;
    for(int i=1;i<pos;i++){
        
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur->next;
    free(cur);
}

int main(int argc, char const *argv[])
{
    int v;
    for(int i=0;i<5;i++){
        scanf("%d",&v);
        insertAtEnd(v);
    }
    printf("\n\nInsert element at the End ----------------->\n");
    printList();

    printf("\n\nInsert element at the Beginning ----------------->\n");
    insertAtBegin(12);
    printList();
    printf("\nHere new HEAD is <<< %d >>>",head->data);
    
    printf("\n\nInsert element at the specific Position(Here position is 3)----------------->\n");
    insertAtPos(200,3);
    printList();
    
    printf("\n\nDelete Element from beginning----------------->\n");
    deleteBegin();
    printList();

    printf("\n\nDelete Element from End----------------->\n");
    deleteEnd();
    printList();

    printf("\n\nDelete Element from a Specific Position(_Here the position is 4_)----------------->\n");
    deletePos(4);
    printList();


    return 0;
}
