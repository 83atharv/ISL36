//insertFront , status , insertEnd , deleteEnd , search , exit
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * head = NULL;
struct Node * tail = NULL;

void insertFront(int data){
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    if(head == NULL){
        head = temp;
        tail = temp;
        temp->next = temp;
    }
    
    tail->next = temp;
    temp->next = head;
    head = temp;

}

void insertEnd(int data){
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    if(head == NULL){
        head = temp;
        tail = temp;
        temp->next = temp;
    }

    tail->next = temp;
    temp->next = head;
    tail = temp;

}

void deleteFront(){
    struct Node * temp = head;
    if(head == NULL){
        printf("Empty list\n");
        return;
    }
    if(head->next == NULL){
        head = NULL;
        tail = NULL;
        printf("Deleted node = %d\n",temp->data);
        free(temp);
        return;
    }
    tail->next = head->next;
    head = head->next;
    temp->next = NULL;
    printf("Deleted node = %d\n",temp->data);
    free(temp);    
}

void deleteEnd(){
    struct Node * temp = head;
    if(head == NULL || head->next == NULL){
        deleteFront();
        return;
    }
    while(temp->next!=tail){
        temp = temp->next;
    }
    tail = temp;
    temp = temp->next;
    tail->next = temp->next;
    temp->next = NULL;
    printf("Deleted item = %d\n",temp->data);
    free(temp);
}

void search(int item){
    struct Node * temp = head;
    int count = 0;
    if(head == NULL){
        printf("Empty list\n");
        return;
    }
    do{
        if(temp->data == item){
            printf("Item found at node %d\n",count+1);
            return;
        }
        count++;
        temp=temp->next;
    }while(temp->next != head);
}

void display(){
    struct Node * temp = head;
    if(head == NULL){
        printf("Empty list\n");
        return;
    }
    do{
        printf("%d->",temp->data);
        temp=temp->next;
    }while(temp!= head);
    printf("NULL\n");
}



int main(){
    int choice, item;
    while(1){
        printf("1. insertFront, 2. insertEnd, 3. deleteFront, 4. deleteEnd, 5. Search, 6. Display, 7. Exit\n");
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
                deleteFront();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                printf("Enter item to search: ");
                scanf("%d",&item);
                search(item);
                break;
            case 6:
                display();
                break;
            case 7:
                printf("Exitting...");
                exit(0);
            default :
                printf("Invalid choice. Please try again!");
                break;
        }
    }
    return 0;
}