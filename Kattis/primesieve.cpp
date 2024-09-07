#include <iostream>
#include <vector>
using namespace std;

vector<bool> isPrime;
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    isPrime.resize(n+1,true);
    int cnt=0;
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=i)isPrime[j]=false;
        }
    }
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<=n;i++)cnt+=isPrime[i];
    printf("%d\n",cnt);
    while(q--){
        int x;
        scanf("%d",&x);
        printf("%d\n",isPrime[x]?1:0);
    }
}