#include <stdio.h>

int top = -1;
int s[5];
int size = 5;

void insert(int n){
    if(top == size-1){
        printf("Stack Overflow\n");
    }
    else{
        s[++top] = n;
    }
}

void delete(){
    if(top == -1){
        printf("Stack Underflow\n");
    }
    else{
        printf("Deleted item = %d\n",s[top--]);
    }
}

void display(){
    if(top == -1){
        printf("Stack is empty\n");
    }
    else{
        for(int i = 0; i<=top; i++){
        printf("%d ",s[i]);
        }
        printf("\n");
    }
    
}

int main(){
    int item, choice;
    for(;;){
        printf("1. Insert, 2. Pop, 3. Display, 4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter item to be inserted: ");
                    scanf("%d",&item);
                    insert(item);
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: return 0;
        }

    }
    return 0;

}