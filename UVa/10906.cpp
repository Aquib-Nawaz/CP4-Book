#include <iostream>
#include <cstring>
#include <unordered_map>
#include <utility>
using namespace std;

int main(){
    int t,C=1;
    scanf("%d",&t);
    char v[11],l[11],op[2],r[11];
    while(C++<=t){
        unordered_map<string,pair<string,char>>mp;
        int n;
        scanf("%d", &n);
        while(n--){
            scanf("%s %*[=] %s %s %s",v,l,op,r);
            string s;
            if(l[0]<='9'&&l[0]>='0')
                s+=l;
            else if (op[0]=='*'&&mp[l].second=='+')
                s+='('+mp[l].first+')';
            else
                s+=mp[l].first;
            s+=op;
            if(r[0]<='9'&&r[0]>='0')
                s+=r;
            else if (op[0]=='+'&&mp[r].second=='*')
                s+=mp[r].first;
            else
                s+='('+mp[r].first+')';
            mp[v]=make_pair(s,op[0]);
        }

        printf("Expression #%d: %s\n", C-1, mp[v].first.data());
    }

}