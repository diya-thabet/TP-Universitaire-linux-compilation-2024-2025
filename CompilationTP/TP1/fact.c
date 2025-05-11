#include<stdio.h>

int facto(int n ){
    if (n==1 || n==0)
        return 1;
    else
        return n*facto(n-1);
}

int main(){
    int n = 5 ; 
    printf("factoriel de %d  est: %d \n",n ,facto(n) ); 
}
