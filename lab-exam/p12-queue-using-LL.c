#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * head = NULL;

void enqueue(int data){
    struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = NULL;
    if(head == NULL){
        head = temp;
        return;
    }else{
        struct Node* cur;
        cur = head;
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = temp;
    }
}

void dequeue(){
    if(head == NULL){
        printf("empty queue");
        return;
    }
    else{
        struct Node * temp;
        temp = head;
        head = head->next;
        printf("Item dequeued = %d\n",temp->data);
        free(temp);
        
    }
}


void display(){
    if(head == NULL){
        printf("Empty queue");
    }
    else{
        struct Node*cur;
        cur = head;
        while(cur!=NULL){
            printf("%d ", cur->data);
            cur=cur->next;
        }
        printf("\n");
    }
}

void main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
}