#include <iostream>
using namespace std;
int arr[365];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", arr+i);
    }
    long long p=100,ns=0;
    for(int i=0;i<n-1;i++){
        if(ns==0){
            //I want to buy
            if(arr[i+1]<arr[i])
            //I will buy tomorrow
                continue;
            ns=min(100000LL,p/arr[i]);
            p-=ns*arr[i];
        }
        else {
            //I want to sell
            if(arr[i+1]>arr[i])
            //I will sell tomorrow
                continue;
            p+=ns*arr[i];
            ns=0;
        }
    }
    p+=ns*arr[n-1];
    printf("%lld\n", p);
}