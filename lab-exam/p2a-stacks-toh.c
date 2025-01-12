#include <stdio.h>

void toh(int n, char source, char aux, char dest){
    if(n>0){
        toh(n-1,source,dest,aux);
        printf("Move disc %d from %c to %c\n",n,source,dest);
        toh(n-1,aux,source,dest);
    }
}

int main(){
    toh(3,'A','B','C');
    return 0;
}