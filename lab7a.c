#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* next;
};
struct node* head=NULL;
//here head must be declared globally
void push(int n);
int peek();     //jump to the top element
int pop();

int main(){
    push(8);
    push(9);
    push(80);
    push(7);
    push(69);
    printf("%d\n",pop());
    printf("%d\n",peek());
    return 0;
}
void push(int n){
    //push in linked stack means insert at begining
    struct node* ptr=malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("out of memory");
        exit(EXIT_FAILURE);
    }
    ptr->info=n;ptr->next=NULL;
    if(head==NULL){
        head=ptr;
        return;
    }
    ptr->next=head;
    head=ptr;
}
int pop(){
    //to delete at first
    if(head==NULL){
        printf("stack is empty");
        return -1;
    }
    int data=head->info;
    //pointer to delete the first node
    struct node* ptr=malloc(sizeof(struct node));
    ptr=head;
    head=head->next;
    free(ptr);
    ptr=NULL;
    return data;
}
int peek(){
    //return the top element
    return head->info;
}
