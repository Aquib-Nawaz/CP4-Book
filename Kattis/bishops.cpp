#include<iostream>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n)!=-1){
        printf("%d\n", n==1?1:(n-1)*2);
    }

}