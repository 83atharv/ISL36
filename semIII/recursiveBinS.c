#include <stdio.h>
#include <stdlib.h>
int binS(int arr[],int target, int s, int e){
    if(s>e) return -1;
    int mid = s + (e-s)/2;
    if(arr[mid] == target){
        return mid;
    }
    else if( arr[mid] > target){
        binS(arr, target, s, mid-1);
    }
    else{
        binS(arr, target, mid+1, e);
    }
}

int main(){
    int arr[10] = {2,5,7,9,20,30,41,67,78,99};
    int target = 78;
    int res = binS(arr,target,0,sizeof(arr)-1);
}