#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

unordered_map<string,int>mp;
int main(){
    queue<string>q;
    for(int i=0;i<26;i++)q.emplace(1,i+'a');
    int i=1;
    while(!q.empty()){
        string s=q.front();
        q.pop();
        mp[s]=i++;
        if(s.size()==5){
            continue;
        }
        for(char c=s.back()+'\1';c<='z';c++){
            q.emplace(s+c);
        }
    }
    char W[6];
    while(scanf("%s", W)!=-1){
        if(mp.count(W)){
            printf("%d\n", mp[W]);
        }else{
            printf("0\n");
        }
    }
}