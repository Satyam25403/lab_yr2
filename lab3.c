//infix to postfix conversion
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

void intopos();
int precedence(char ch);
void push(char data);
char pop();
int space(char c);
int isfull();
int isempty();

int top=-1;
char stack[MAX],infix[MAX],postfix[MAX];

void main(){
    printf("enter infix expression: ");
    gets(infix);
    intopos();
    puts(postfix);
    return;
}
void intopos(){
    int i,j=0;  //j used for operations on postfix
    char sym,next;
    for(i=0;i<strlen(infix);i++){
        sym=infix[i];
        if(!space(sym)){    //skips if spaces are encountered
            switch(sym){
                case '(':
                    push(sym);
                    break;
                case ')':
                    //till we dont encounter a left paranthesis pop all items
                    while((next=pop())!='('){
                        postfix[j++]=next;  //use and then assign   
                    }
                    break;//this loop will automatically discard the left paranthesis
                    //first it is popped and then checked
                case '^':
                case '/':
                case '*':
                case '+':
                case '-': 
                    while(!isempty()&& precedence(stack[top])>=precedence(sym)){
                        postfix[j++]=pop();
                    }
                    push(sym);
                    break;
                default:
                    postfix[j++]=sym;
            }
        }//after completion of the loop we may be left with some symbols in stack,so we should pop all of them out
    }
    while(!isempty()){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
int precedence(char ch){
    //higher value higher precedence
    switch(ch){
        case '^':
            return 3;
        case '/':
        case '*':       // since there is no break statement in b/w
            return 2;
        case '+':
        case '-':
            return 1;
        default:        //here this is for paranthesis or any other operator 
            return 0;
    }
}
void push(char data){
    if(isfull()){
        printf("stack overflow:stack is full");
        return;
    }
    top=top+1;         //first increment the index to access the position
    stack[top]=data;
}
char pop(){
    char value;
    if(isempty()){
        printf("stack underflow:no elements to delete");
        exit(1);        //abnormal termination of the program:failure
    }
    value=stack[top];
    top-=1;      //we will decrement the top variable giving the user an illusion of element deletion
    return value;
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
int space(char c){
    if(c==' '||c=='\t'){
        return 1;
    }
    return 0;
}
