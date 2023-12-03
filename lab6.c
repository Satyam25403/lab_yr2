#include<stdio.h>
#include<stdlib.h>
//a self referential data structure
struct node{
    int data;
    struct node* next;
};
struct node* addatend(struct node* head,int data);
struct node* addtoempty(struct node* head,int data);
struct node* dellast(struct node* head);
void print (struct node* head);

int main(){
    struct node* head =NULL;
    head=addtoempty(head,23);
    head=addatend(head,77);
    head=addatend(head,90);
    print(head);
    head=dellast(head);
    print(head);
    return 0;
}
struct node* addtoempty(struct node* head,int data){
    //function to create a node in an empty list
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}
struct node* addatend(struct node* head,int data){
    //function to add nodes at the end of the list
    struct node* temp,*tp;
    temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    tp=head;        //pointer to traverse to the end node of the given list
    while(tp->next!=NULL){
        tp=tp->next;
    }
    tp->next=temp;
    return head;
}
struct node* dellast(struct node* head){
    //delete the last node of a list
    struct node* temp=head,*temp2=NULL;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp2=temp->next;
    temp->next=NULL;
    free(temp2);
    temp2=NULL;
    return head;
}
void print (struct node* head){
    struct node* ptr=head;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}