#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* next;
};
struct node* head=NULL;
//here head must be declared globally
void enqueue(int n);
int dequeue();
void display();
int main(){
    enqueue(9);
    enqueue(10);
    enqueue(16);
    enqueue(23);
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    return 0;
}
void enqueue(int n){
    //means add at end of list
    struct node* temp=malloc(sizeof(struct node));
    struct node* tp=head;
    temp->info=n;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        return;
    }
    //pointer to traverse to the end node of the given list
    while(tp->next!=NULL){
        tp=tp->next;
    }
    tp->next=temp;
}
int dequeue(){
    //means to delete at first
    if(head==NULL){
        printf("queue is empty");
        return -1;
    }
    int data=head->info;
    //pointer to delete the first node
    struct node* ptr=head;
    head=head->next;
    free(ptr);
    ptr=NULL;
    return data;
}