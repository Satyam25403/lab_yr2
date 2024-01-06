#include<stdio.h>
#define MAX 100
void enqueue(int a);
void dequeue();
void display();
int isFull();
int isEmpty();
int q_arr[MAX];
int front=-1,rear=-1;
int main(){
    printf("%d",isFull());
    printf("%d",isEmpty());
    enqueue(23);
    enqueue(2);
    enqueue(34);
    enqueue(76);
    enqueue(5);
    display();
    dequeue();
    display();
    printf("%d",isFull());
    printf("%d",isEmpty());
    return 0;
}
void enqueue(int a){
    if(!isFull()){      //partially empty or completely empty
        if(front==-1){      //if queue is initially empty we should increment both front and rear
            front++;
        }
        rear+=1;
        q_arr[rear]=a;
    }
    else{
        //whole queue filled
        printf("overflow");
    }
    printf("\n");
}
void dequeue(){     // out from starting
    if(!isEmpty()){     //partially filled or completely
        front+=1;
    }
    else{
        printf("underflown");
    }
    printf("\n");
}
void display(){
    if(!isEmpty()){
        for(int i=front;i<=rear;i++){
            printf("%d--->",q_arr[i]);
        }
        printf("\n");
    }
}
int isEmpty(){
    return (front>rear || (front==-1 && rear==-1));
}
int isFull(){
    return (rear==MAX-1);
}