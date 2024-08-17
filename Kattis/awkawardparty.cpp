#include <iostream>
#include <unordered_map>
using namespace std;

#define REP(i,n) for (int i=0;i<n;i++)

int main(){
    int n,d;
    unordered_map<int,int>mp;
    scanf("%d", &n);
    int ans=n;
    REP(i,n){
        scanf("%d", &d);
        if(mp.count(d)!=0){ans = min(ans,i-mp[d]);}
        mp[d] = i;
    }
    printf("%d", ans);
}