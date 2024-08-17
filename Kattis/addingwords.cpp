#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>
using namespace std;

char cmd[7];char var[31];


int main(){
    unordered_map<string, int>mp;
    unordered_map<int,string>mp1;
    int v; char c;
    bool f=0;
    while(scanf("%s", cmd)!=EOF){
        if(cmd[0]=='d'){
            scanf("%s %d",var,&v);

            if(mp.count(var)!=0)
                mp1.erase(mp[var]);
            mp[var]=v;
            mp1[v]=var;
        }
        else if(cmd[1]=='l')mp.clear(), mp1.clear();
        else {
            int ans=0;
            bool err= false;
            char prevc=0;
            if(f)printf("\n");f=1;

            while(scanf(" %s %c", var, &c)!=-1){
                if(mp.count(var)==0)err=true;
                else if(prevc=='+' ||prevc==0)ans+=mp[var];
                else ans-=mp[var];
                prevc=c;
                printf("%s %c ",var,c);
                if(c=='=')break;
            }
            if(err||mp1.count(ans)==0)printf("unknown");
            else printf("%s",mp1[ans].c_str());
        }
    }
}