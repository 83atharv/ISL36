#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int q[5];
int size= 5;
int f = 0;
int r= -1;

void enqueue(int item){
    if(r == size-1){
        printf("qo\n");
    }
    else{
        q[++r] = item;
    }
}

void dequeue(){
    if(f>r){
        printf("qu\n");
    }
    else{
        printf("del = %d\n",q[f++]);
    }
}
void display(){
    for(int i= f; i<=r; i++){
        printf("%d ",q[i]);
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