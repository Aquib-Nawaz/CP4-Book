#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int T,C=0;
    scanf("%d", &T);
    while(T--){
        string a,b,c;
        cin >> a >> b >> c;
        unordered_map<char,int>mp;
        for(char & i : b)mp.insert({i,mp.size()});
        int val=0,pow=1,base=b.size();
        for(int i=a.size()-1;i>=0;i--){
            val+=mp[a[i]]*pow;
            pow*=base;
        }
        base=c.size();
        b="";
        while(val){
            b.push_back(c[val%base]);
            val/=base;
        }
        reverse(b.begin(),b.end());
        if(b.empty())b.push_back(c[0]);
        printf("Case #%d: %s\n",++C ,b.c_str());
    }
}