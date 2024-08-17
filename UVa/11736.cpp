#include <iostream>
#include <map>
#include <string>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
int main(){
    int b,v;
    while(scanf("%d %d", &b, &v)!=EOF){

        map<string, ull>mp;
        char var[21];int id;
        char varid[v][21];
        int idx=0;
        while(idx<v){
            scanf("%s %d",var,&id);

            mp[var]=id;
            strcpy(varid[idx++],var);

        }
        char bytes[b+1];
        for(idx=0;idx<v;idx++){
            ull ans=0;
            for(int j=0; j<mp[varid[idx]]; j++){
                scanf("%s", bytes);
                ans = (ans<<b) + strtol(bytes, nullptr, 2);
            }
            mp[varid[idx]]=ans;
        }
        int q;
        scanf("%d",&q);
        while(q--){
            scanf("%s", var);
            printf("%s=", var);
            if(mp.find(var)!=mp.end())
                printf("%llu", mp[var]);
            printf("\n");
        }
        char last;

    }
}