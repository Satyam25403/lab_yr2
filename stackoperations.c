#include<stdio.h>
#include<stdlib.h>
#define MAX 5
//global declaration because it can be accessible to all functions
int stack_arr[MAX];
//top variable will keep track(stores index) of the last inserted element
int top=-1;         //indicates empty stack

void push(int data);
int pop();     //deleting an element and returns the deleted element
void print();
int isfull();       //returns 0 or 1
int isempty();      //return 0 or 1


int main(){
    push(3);
    push(9);
    push(67);
    push(78);
    print();
    printf("%d\n",pop());
    print();
    return 0;
}


void push(int data){
    if(isfull()){
        printf("stack overflow:stack is full");
        return;
    }
    top=top+1;         //first increment the index to access the position
    stack_arr[top]=data;
}
int pop(){
    int value;
    if(isempty()){
        printf("stack underflow:no elements to delete");
        exit(1);        //abnormal termination of the program:failure
    }
    value=stack_arr[top];
    top-=1;      //we will decrement the top variable giving the user an illusion of element deletion
    return value;
}
void print(){
    int i;
    if(top==-1){
        printf("stack underflow");
        return;
    }
    for(i=top;i>=0;i--){    //printing elements from top
        printf("%d\t",stack_arr[i]);
    }
    printf("\n");
}
int isfull(){
    if(top==MAX-1)
        return 1;
    else 
        return 0;
}
int isempty(){
    if(top==-1)
        return 1;
    else 
        return 0;
}