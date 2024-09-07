#include <iostream>
using namespace std;

bool isPrime(int n){
    if(n<=1)return false;
    if(n==2)return true;
    if(n%2==0)return false;
    for(int i=3;i*i<=n;i+=2){
        if(n%i==0)return false;
    }
    return true;
}

int main(){
    int N;
    scanf("%d", &N);
    while(N--){
        int A;
        scanf("%d", &A);
        if(N!=0)
            scanf(" , ");
        printf("%s\n", A<18 && isPrime(A)&& isPrime((1<<A)-1)?"Yes":"No");
    }
}