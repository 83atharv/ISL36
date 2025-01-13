#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int q[5];
int size= 5;
int f = 0;
int r= -1;
int count = 0;

void enqueue(int item){
    if(count == size){
        printf("circular overflow\n");
    }
    else{
        r=(r+1)%size;
        q[r] = item;
        count++;
    }
}

void dequeue(){
    if(count == 0){
        printf("circular underflow\n");
    }
    else{
        printf("deleted item = %d\n",q[f]);
        f = (f+1)%size;
        count--;
    }
}
void display(){
    for(int i= 0; i<count; i++){
        printf("%d ",q[(f+i)%size]);
    }
    printf("\n");
}

void checkStatus(){
    if(count == size){
        printf("circular overflow\n");
    }
    else if(count == 0){
        printf("circular underflow\n");
    }
    else{
        printf("Number of items that can be inserted = %d\n",size-count);
    }
}

int main() {
    int item, choice;
    for(;;){
        printf("1. Enqueue, 2. Dequeue, 3. Display, 4. Display Status, 5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter item to be inserted: ");
                    scanf("%d",&item);
                    enqueue(item);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: checkStatus();
                    break;
            case 5: return 0;
            default: printf("Invalid command. Please try again!\n");
                    break;
        }

    }
}