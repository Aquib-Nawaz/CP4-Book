#include <iostream>
using namespace std;
bool isPrime[100001];
int main(){
    int N,k;
    scanf("%d%d", &N,&k);
    for(int i=2;i<=N;i++){
        isPrime[i]=true;
    }
    int cur=0;
    for(int i=2;i<=N;i++){
        if(isPrime[i]){
            cur++;
            if(cur==k){printf("%d\n",i); return 0;}
            for(int j=i<<1;j<=N;j+=i){
                if(isPrime[j]){
                    isPrime[j]=false;
                    cur++;
                    if(cur==k){printf("%d\n",j); return 0;}
                }
            }
        }
    }
}