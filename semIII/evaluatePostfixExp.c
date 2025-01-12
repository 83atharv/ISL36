#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


double calc(char symbol, double op1, double op2){
    switch(symbol){
        case '^':
        case '$': return pow(op1,op2);
        case '*': return op1*op2;
        case '/': return op1/op2;
        case '-': return op1-op2;
        case '+': return op1+op2;
        default: return -1;
    }
}

double evaluatePostfixExp(char postfix[]){
    double stack[30];
    double op1, op2, result;
    int top = -1;
    for(int i = 0; postfix[i] != '\0'; i++){
        char symbol = postfix[i];
        if(isdigit(symbol)){
            stack[++top] = symbol - '0';
        }
        else{
            op2 = stack[top--];
            op1 = stack[top--];
            result = calc(symbol, op1, op2);
            stack[++top] = result;
        }
    }
    return stack[top--];
}

void main(){
    char postfix[30];
    printf("Enter valid postfix expression : ");
    scanf("%s", postfix);
    double result = evaluatePostfixExp(postfix);
    printf("Answer = %lf\n",result);
}