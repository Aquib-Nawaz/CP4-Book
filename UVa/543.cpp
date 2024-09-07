#include <iostream>
using namespace std;

bool isPrime[1000001];

int main(){
    int n;
    for(int i=2;i<1000001;i++)isPrime[i]=true;
    for(int i=2;i<1000001;i++){
        if(isPrime[i]){
            for(int j=2;i*j<1000001;j++){
                isPrime[i*j]=false;
            }
        }
    }
    while(cin>>n) {
        for(int i=3;i<n;i+=2)if(isPrime[i]&&isPrime[n-i]){
            printf("%d = %d + %d\n",n,i,n-i);
            break;
        }
    }
}