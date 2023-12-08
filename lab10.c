#include <stdio.h>
#include <stdlib.h>
struct node{
    int info;
    int priority;
    struct node *next;
};
struct node *head = NULL;
struct node *insert(struct node *head, int data, int priority);
struct node *display(struct node *head);
void delete(int);
void main(){
    head = insert(head, 89, 2);
    head = insert(head, 8, 3);
    head = insert(head, 2, 1);
    head = insert(head, 4, 5);
    display(head);
    delete (89);
    display(head);
    delete (2);
    display(head);
}
struct node *insert(struct node *head, int data, int priority){
    struct node *temp = malloc(sizeof(struct node));
    if (temp == NULL){
        printf("memory error");
        exit(EXIT_FAILURE);
    }
    temp->info = data;
    temp->priority = priority;
    temp->next = NULL;
    if (head == NULL){
        head = temp;
        return head;
    }
    if (head->priority > temp->priority){
        temp->next = head;
        head = temp;
        return head;
    }
    else{
        struct node *t = head;
        while (t->next != NULL && t->next->priority <= temp->priority){
            t = t->next;
        }
        temp->next = t->next;
        t->next = temp;
        return head;
    }
}
void delete(int info){
    if (head == NULL){
        printf("underflow...\n");
        return;
    }

    struct node *temp = head;
    if (head->info == info){
        head = head->next;
        free(temp);
        return;
    }

    struct node *t = head;
    while (t->next != NULL && t->next->info != info){
        t = t->next;
    }

    if (t->next->info == info){
        temp = t->next;
        t->next = t->next->next;
        free(temp);
    }
}
struct node *display(struct node *head){
    struct node *t = head;
    while (t != NULL){
        printf("(%d->%d)", t->info, t->priority);
        t = t->next;
    }
    printf("\n");
}