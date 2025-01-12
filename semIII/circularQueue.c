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
        printf("qo\n");
    }
    else{
        r=(r+1)%size;
        q[r] = item;
        count++;
    }
}

void dequeue(){
    if(count == 0){
        printf("qu\n");
    }
    else{
        printf("del = %d\n",q[f]);
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

int main() {
    int item, choice;
    for(;;){
        printf("1. Enqueue, 2. Dequeue, 3. Display, 4. Exit\n");
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
            case 4: return 0;
        }

    }
}