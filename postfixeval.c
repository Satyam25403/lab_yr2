#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100

void intopos();
int precedence(char ch);
void push(int data);
int pop();
int space(char c);
int isfull();
int isempty();
void print();
int post_eval();

int top=-1;
int stack[MAX];
char infix[MAX],postfix[MAX];
int main(){
    int result;
    printf("enter infix expression:");
    gets(infix);
    intopos();
    result=post_eval();
    print();
    printf("result is %d ",result);
    return 0;
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
int post_eval(){
    int a,b;
    for(int i=0;i<strlen(postfix);i++){
        if(postfix[i]>='0'&&postfix[i]<='9'){
            push(postfix[i]);
        }
        else{
            a=pop();b=pop();
            switch(postfix[i]){
                case '*':
                    push(b*a);
                    break;
                case '-':
                    push(b-a);
                    break;
                case '+':
                    push(b+a);
                    break;
                case '/':
                    push(b/a);
                    break;
                case '^':
                    push(pow(b,a));
                    break;
            }

        }
    }
    return pop();
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
void print(){
   int i=0;
   printf("equivalent postfix expression is: ");
   while(postfix[i]){
    printf("%c",postfix[i++]);
   }
   printf("\n");
}
void push(int data){
    if(isfull()){
        printf("stack overflow:stack is full");
        return;
    }
    top=top+1;         //first increment the index to access the position
    stack[top]=data;
}
int pop(){
    int value;
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
