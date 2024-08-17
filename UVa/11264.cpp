#include <iostream>
#include <algorithm>
using namespace std;

int A[1000];


int main(){
    int n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&A[i]);
        int cs=0,ans=1;
        for(int i=0;i<n-1;i++){
            if(cs+A[i]<A[i+1])cs+=A[i],ans++;
        }
        printf("%d\n",ans);
    }
}