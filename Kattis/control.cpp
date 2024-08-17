#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;
int S[200001], P[500001],T[500001];

int main(){
    int n,m,d;
    bool err;
    scanf("%d", &n);
    memset(P,0,sizeof P);
//    memset(S,0,sizeof S);
    int cnt=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&m);
        unordered_map<int,int>mp;
        for(int j=0;j<m;j++)
            scanf("%d",&T[j]),mp[P[T[j]]]++;
        err=false;
        for(auto &it:mp){
            if(it.first!=0 &&it.second!=S[it.first]){
                err=true;
                break;
            }
        }
        if(err)
            continue;
        for(int j=0;j<m;j++)
            P[T[j]]=i;
        S[i]=m;
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}