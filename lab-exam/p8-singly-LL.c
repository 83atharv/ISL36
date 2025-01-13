#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node*head = NULL;

void insertFront(int data){
    // int * ptr = (int*)malloc(sizeof(int));
    struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void insertRearEnd(int data){
    struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = NULL;
    if(head == NULL){
        temp->next = head;
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

void insertAtPosition(int data, int position){
    if(position == 0){
        insertFront(data);
        return;
    }
    int cnt = 0;
    struct Node * temp;
    temp = head;
    while(cnt < position-1 && temp!=NULL){
        temp = temp->next;
        cnt++;
    }

    if(temp == NULL){
        insertRearEnd(data);
        return;
    }

    struct Node * node = (struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->next = temp->next;
    temp->next = node;

}

void deleteFrontEnd(){
    if(head == NULL){
        printf("empty LL");
        return;
    }
    else{
        struct Node * temp;
        temp = head;
        head = head->next;
        free(temp);
        
    }
}

void deleteLastNode(){
    struct Node * temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    struct Node * del = temp->next;
    temp->next = NULL;
    printf("Deleted node = %d\n",del->data);
    free(del);

}

void deleteNodeAtIndex(int index){
    if(index == 0){
        deleteFrontEnd();
        return;
    }
    int cnt = 0;
    struct Node * temp = head;
    while(cnt < index - 1){
        temp = temp->next;
        cnt++;
    } 
    struct Node * del = temp -> next;
    temp->next = del->next;
    printf("Deleted node = %d\n",del->data);
    free(del);

}

void display(){
    if(head == NULL){
        printf("Empty list");
    }
    else{
        struct Node*cur;
        cur = head;
        while(cur!=NULL){
            printf("%d ", cur->data);
            cur=cur->next;
        }
    }
}

int main(){
    insertFront(10);
    insertRearEnd(20);
    insertRearEnd(30);
    insertRearEnd(40);
    insertRearEnd(50);
    insertRearEnd(60);
    insertRearEnd(70);
    insertAtPosition(25,2);
    deleteNodeAtIndex(3);
    display();
}