#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int dp[26], val[26];
vector<int>adjL[26];

int dfs(int u){
    if(dp[u]!=-1) return dp[u];
    int ch=0;
    for(auto v:adjL[u]){
        ch= max(ch,dfs(v));
    }
    return dp[u]=ch+val[u];
}
int main(){
    int T;
    scanf("%d ", &T);
    string s;
    while(T--){
        for(int i=0;i<26;i++)adjL[i].clear(),dp[i]=-1,val[i]=0;
        while(getline(cin,s) && !s.empty()){
            stringstream ss(s);
            char a;
            int b;
            ss >> a >> b;
            val[a-'A']=b;
            if(ss >> s){
                for(auto v:s){
                    adjL[a-'A'].push_back(v-'A');
                }
            }
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans=max(ans,dfs(i));
        }
        printf("%d\n",ans);
        if(T)
            printf("\n");
    }

}