#include <iostream>
#include <map>
using namespace std;

int main(){
    int T,C=0;
    scanf("%d", &T);
    map<int,int>mp;
    long long tk;
    long long ans;
    while(T--){
        int n;
        scanf("%d", &n);
        ans=tk=0;
        for(int i=0,k,p;i<n;i++)scanf("%d %d",&k,&p),mp[p]+=k,tk+=k;
        for(auto& [p,k]:mp){
            ans=max(tk*p,ans);
            tk-=k;
        }
        printf("Case %d: %lld\n",++C,ans);
        mp.clear();
    }
}