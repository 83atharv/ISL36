#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int stack[30];
int top = -1;

int sprecedence(int item){
    switch(item){
        case '^':
        case '$': return 3;
        case '*': 
        case '/': return 2;
        case '+': 
        case '-': return 1;
        default: return -1; 
    }
}

int iprecedence(int item){
    switch(item){
        case '^':
        case '$': return 4;
        case '*': 
        case '/': return 2;
        case '+': 
        case '-': return 1;
        default: return -1; 
    }
}

void infixToPostfix(char infix[], char postfix[]){
    int k = 0;
    for(int i = 0; infix[i]!='\0'; i++){
        char symbol = infix[i];
        if(isalnum(symbol)){
            postfix[k++] = symbol;
        }
        else if(symbol == '('){
            stack[++top] = symbol;
        }
        else if(symbol == ')'){
            while(stack[top] != '('){
                postfix[k++] = stack[top--];
            }
            stack[top--];
        }
        else{
            while(sprecedence(stack[top]) >= iprecedence(symbol)){
                postfix[k++] = stack[top--];
            }
            stack[++top] = symbol;
        }
    }
    while(top != -1){
        postfix[k++] = stack[top--];
    }
    postfix[k] = '\0';
}

void main(){
    char infix[30];
    char postfix[30];
    printf("Enter an infix expression : ");
    scanf("%s",infix);
    infixToPostfix(infix,postfix);
    printf("Postfix expression = %s\n",postfix);
}