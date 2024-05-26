#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    map<string, vector<int>> mp;
    int t;
    scanf("%d", &t);
    char w1[21], w2[21];
    int found=0;
    int ans=0;
    for(int i=0; i<t; i++){
        int f,s;
        scanf("%d %d %s %s", &f, &s, w1, w2);
        if(strcmp(w1,w2)==0){
            mp.erase(w1);
            found++;
            continue;
        }
        if(mp[w1].empty() || (mp[w1].size()==1 && mp[w1][0]!=f)){
            mp[w1].push_back(f);
        }

        if(mp[w2].empty()||(mp[w2].size()==1 && mp[w2][0]!=s)){
            mp[w2].push_back(s);
        }

    }
    int singles=0;
    for(auto it=mp.begin(); it!=mp.end(); it++){
        if(it->second.size()==2){
            ans++;
        }
        else
            singles++;
    }
    if(found+ans==n/2-1)
        ans++;
    else if(2*(found+ans+singles)==n)
        ans = n/2-found;
    printf("%d\n", ans);

}