#include <stdio.h>

void left(int size,int *arr,int len){

    for(int i = 0;i < len; ++i){
        printf("%d ",arr[(i+size)%len]);
    }
    putchar(10);
}
int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9};

    for(int i = 0;i < 9; ++i){
        left(i,arr,9);
    }




    return 0;
}
