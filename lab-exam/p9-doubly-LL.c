// insertEnd , status , insertFront , deleteFront , search , exit

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
};   

struct Node*head = NULL;

void insertFront(int data){
    struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    if(head == NULL){
        head = temp;
        temp->next = NULL;
        temp->prev = NULL;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
}


void insertEnd(int data){
    struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    if(head == NULL){
        head = temp;
        temp->next = NULL;
        temp->prev = NULL;
        return;
    }
    if(head->next == NULL){
        head->next = temp;
        temp->prev = head;
        temp->next = NULL;
        return;
    }
    struct Node * help = head;
    while(help->next!=NULL){
        help = help->next;
    }
    help->next = temp;
    temp->prev = help;
    temp->next = NULL;
}


void deleteFront(){
    if(head == NULL){
        printf("empty list");
        return;
    }
    struct Node * temp = head;
    head = temp->next;
    head->prev = NULL;
    temp->next = NULL;
    printf("Deleted item = %d\n",temp->data);
    free(temp);
    temp = NULL;
}

void search(int item){
    struct Node * temp = head;
    int count = 0;
    while(temp != NULL){
        if(temp->data == item){
            printf("%d found at index %d\n",item,count);
            return;
        }
        temp = temp->next;
        count++;
    }
    printf("%d not found\n",item);
}

void display(){
    struct Node * temp = head;
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main(){
    int choice, item;
    while(1){
        printf("1. insertFront, 2. insertEnd, 3. Display, 4. deleteFront, 5. Search, 6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                printf("Enter item to insert: ");
                scanf("%d",&item);
                insertFront(item);
                break;
            case 2:
                printf("Enter item to insert: ");
                scanf("%d",&item);
                insertEnd(item);
                break;
            case 3:
                display();
                break;
            case 4:
                deleteFront();
                break;
            case 5:
                printf("Enter item to search: ");
                scanf("%d",&item);
                search(item);
                break;
            case 6:
                printf("Exitting...");
                exit(0);
            default :
                printf("Invalid choice. Please try again!");
                break;
        }
    }
    return 0;
}