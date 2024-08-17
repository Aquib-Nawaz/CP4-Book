#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<string>g[26];
int indeg[26];
bool vis[26];

void dfs(int u){
    if(vis[u])return;
    vis[u]=true;
    for(auto &v:g[u])dfs(v.back()-'a');
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        char a,b;
        string s;
        scanf("%d",&n);
        for(int i=0;i<26;i++)indeg[i]=0, vis[i]= false, g[i].clear();
        for(int i=0;i<n;i++){
            cin>>s;
            a = s.front(),b=s.back();
            g[a-'a'].push_back(s);
            indeg[b-'a']++;
        }
        bool pos=true;
        int inv=-1, outv=-1;
        for(int i=0;i<26;i++){
            if(indeg[i]==g[i].size())continue;
            else if(indeg[i]==g[i].size()+1 && inv==-1)inv=i;
            else if(indeg[i]+1==g[i].size() && outv==-1)outv=i;
            else{
                pos=false;
                break;
            }
        }
        if(!pos){
            printf("***\n");
            continue;
        }
        if(outv==-1){
            for(int i=0;i<26;i++)if(!g[i].empty()){outv=i;break;}
        }
        dfs(outv);
        for(int i=0;i<26;i++)if((indeg[i]||!g[i].empty() )&& !vis[i])pos= false;
        if(!pos){
            printf("***\n");
        }
        else {
            for(auto & i : g)sort(i.begin(), i.end());
            vector<string>st;
            vector<string>ans;
            vector<int>deg(26,0);
            st.emplace_back(1,outv+'a');
            while(!st.empty()){
                s = st.back();
                int u = s.back()-'a';
                if(deg[u]==g[u].size()){
                    ans.push_back(s);
                    st.pop_back();
                }
                else{
                    st.emplace_back(g[u][deg[u]] );
                    deg[u]++;
                }
            }
            for(int i=ans.size()-2;i>0;i--)printf("%s.", ans[i].c_str());
            printf("%s\n", ans[0].c_str());
        }
    }
}