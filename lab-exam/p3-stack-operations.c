// push pop overflow underflow display 

#include <stdio.h>

int size = 5;
int st[5];
int top = -1;

void push(int n){
    if(top == size-1) printf("\nStack overflow\n");
    else st[++top] = n;
}

void pop(){
    if(top == -1) printf("\nStack underflow\n");
    else printf("\nPopped item = %d\n",st[top--]);
}

void display(){
    if(top == -1) printf("Stack empty");
    else for(int i = top; i>=0 ;i--) printf("%d ", st[i]);
    
}

int popPal(){
    if(top == -1) return 0;
    else return st[top--];
}

void checkPal(int x){
    int n = x;
    int ans = 0;
    while(n > 0){
        push(n%10);
        n = n/10;
        ans = (ans*10)+popPal();
    }

    if(x == ans) printf("It is a palindrome");
    else printf("Not a palindrome");
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    display();
    push(50);
    push(60);
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    checkPal(1221);
}