#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * head = NULL;

void push(int data){
    struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void pop(){
    if(head == NULL){
        printf("empty stack");
        return;
    }
    else{
        struct Node * temp;
        temp = head;
        head = head->next;
        printf("Item popped = %d\n",temp->data);
        free(temp);
        
    }
}


void display(){
    if(head == NULL){
        printf("Empty stack");
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
    push(10);
    push(20);
    push(30);
    push(40);
    push(60);
    display();
    pop();
    display();
    pop();
    display();
    pop();
}