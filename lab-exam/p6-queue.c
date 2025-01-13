#include <stdio.h>
#include <stdlib.h>

int size = 5;
int q[5];
int r = -1, f = 0;

void enqueue(int pId){
    if(r == size - 1) printf("Overflown\n");
    else{
        q[++r] = pId;
        printf("Added id = %d\n",pId);
    }
}

void dequeue(){
    if(r<f) printf("Underflown\n");
    else{
        printf("Removed id = %d\n",q[f++]);
    }
}

void display(){
    if(r<f) printf("Queue is empty\n");
    else{
        for(int i = f; i<=r ; i++){
            printf("%d ",q[i]);
        }
    }
}

int main(){
    int choice, processId;
    while(1){
        printf("Select operation : \n");
        printf("1 : Add an operation to queue\n");
        printf("2 : Remove operation from queue\n");
        printf("3 : Display queue\n");
        printf("4 : Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                printf("Enter process id: ");
                scanf("%d",&processId);
                enqueue(processId);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exitting..");
                exit(0);
            default :
                printf("Invalid choice. Please try again!");
                break;
        }
    }
    return 0;
}