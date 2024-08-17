#include <iostream>
#include <map>
using namespace std;

int A[100001];
int main(){
    int n,b, l,r;
    scanf("%d %d", &n, &b);
    long long ans=1;
    for(int i=0;i<n;i++){
        scanf("%d", &A[i]);
        if(A[i]==b)l=r=i;
    }
    map<int,int>mp;
    for(int i=l-1,cur=0;i>=0;i--){
        cur+=A[i]<b?-1:1;
        mp[cur]++;
    }
    ans+=mp[0];
    for(int i=r+1,cur=0;i<n;i++){
        cur+=A[i]<b?-1:1;
        ans+=mp[-cur];
        if(cur==0)ans++;
    }
    printf("%lld\n", ans);

}