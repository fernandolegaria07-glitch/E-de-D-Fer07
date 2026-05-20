#include<stdio.h>
#include<stdlib.h>
#define ERROR -1000

int exponente(int m, int n){


    if(m < 1 || n < 0){
        printf("Error");
        return ERROR;
    }
    if(n == 1) {
        return m;
    }
    return m * exponente(m, n-1);
}

int suma(int m, int n){

    if(m < 0 || n < 0){
        return ERROR;
    }
    if(n == 0) return m;
    return 1 + suma(m,n -1);
}

int main(){

    printf("%d \n", exponente(4,5));
    printf("%d \n", suma(26653, 2382));
}