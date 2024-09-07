#include <iostream>
using namespace std;

bool isPrime[1000000];
int reverse(int n){
    int r=0;
    while(n){
        r*=10;
        r+=n%10;
        n/=10;
    }
    return r;
}

int main() {
    for(int i=2;i<1000000;i++)isPrime[i]= true;
    for(int i=2;i*i<1000000;i++){
        if(isPrime[i]){
            for(int j=i*i;j<1000000;j+=i){
                isPrime[j]= false;
            }
        }
    }
    int n,temp;
    while (scanf("%d", &n)==1){
        if(!isPrime[n])printf("%d is not prime.\n", n);
        else {
            temp=reverse(n);
            if(temp!=n && isPrime[temp])printf("%d is emirp.\n", n);
            else printf("%d is prime.\n", n);
        }
    }
}
