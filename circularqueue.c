#include<stdio.h>
#define MAX 5
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
    
    printf("%d\n",isEmpty());
    display();
    printf("%d",isFull());
    printf("%d",isEmpty());
    return 0;
    return 0;
}
//whenever front or rear are updated in circular queues,ensure that mod divisiob is used
//to maintrain the circularity-euclids division lemma
void enqueue(int a){
    if(!isFull()){      //either partially empty or completely empty
        if(isEmpty()){       //completely empty
            front+=1;
        }
        rear=(rear+1)%MAX;
        q_arr[rear]=a;
    }
    else{
        printf("queue is full");
    }
}
void dequeue(){
    if(!isEmpty()){
        if(front==rear){
            //both pointing to same element, then only one element is there
            front=rear=-1;
        }
        else{//more than one element
            front=(front+1)%MAX;
        }
    }
    else{
        printf("queue is already empty");
    }
}
void display(){
    if(!isEmpty()){     //normal loops wont work
        int i=front;
        do{
            printf("%d\t",q_arr[i]);
            i=(i+1)%MAX;
        }while(i!=(rear+1)%MAX);
        printf("\n");
    }
    else{
        printf("queue is empty");
    }
    printf("\n");
}
int isFull(){
    return ((front==0 &&rear==MAX-1)||(front==rear+1));
    //this is same as writing return (rear+1)%MAX==front;
}
int isEmpty(){
    return (front==-1 && rear==-1);
    //because front can be> rear in circular queue
}