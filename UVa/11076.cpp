#include <iostream>
#include <unordered_map>
using namespace std;

typedef unsigned long long ull;
int fac[13];

void init(){
    fac[0]=1;
    for(int i=1;i<13;++i){
        fac[i]=fac[i-1]*i;
    }
}

int main(){
    int n,a;
    init();
    while (scanf("%d", &n), n){
        ull sum=0;
        unordered_map<int,int>mp;
        ull m=0,t=1;
        for(int i=0;i<n;i++)m+=t, t*=10;
        for(int i=0;i<n;++i)scanf("%d",&a), mp[a]++;
        for(auto i:mp){
            ull tmp=fac[n-1];
            for(auto j:mp){
                if(j.first==i.first)
                    tmp/=fac[j.second-1];
                else
                    tmp/=fac[j.second];
            }
            sum+=tmp*i.first*m;
        }
        printf("%llu\n",sum);
    }
}