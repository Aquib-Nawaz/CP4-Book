#include <iostream>
#include <algorithm>
using namespace std;

int arr[30];
int main(){
    int T,P,Q,N,C=0;
    scanf("%d",&T);
    while (T--){
        scanf("%d %d %d",&N, &P,&Q);
        for(int i=0;i<N;i++)scanf("%d", arr+i);
        sort(arr,arr+N);
        int ans=0,w=0;
        for(int i=0;i<P && i<N&& w+arr[i]<=Q;i++)ans++,w+=arr[i];
        printf("Case %d: %d\n",++C,ans);
    }
}