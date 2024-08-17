#include <iostream>
#include <vector>
using namespace std;

vector<int>adj[10000];
int indeg[10000];
bool vis[10000];

void dfs(int u){
    if(vis[u])return ;
    vis[u]=true;
    for(auto &v:adj[u]){
        if(!vis[v])dfs(v);
    }
}
int main(){
    int n,m;
    while (scanf("%d%d", &n,&m),n!=0){
        for(int i=0;i<n;i++)adj[i].clear(), indeg[i]=0, vis[i]=false;
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            indeg[v]++;
        }
        int inv=-1,outv=-1;
        bool pos=true;
        for(int i=0;i<n;i++){
            if(indeg[i]==adj[i].size())continue;
            else if(indeg[i]==adj[i].size()+1 && inv==-1)inv=i;
            else if(indeg[i]+1==adj[i].size() && outv==-1)outv=i;
            else{
                pos=false;
                break;
            }
        }
        if(!pos){
            printf("Impossible\n");
            continue;
        }
        if(outv==-1){
            for(int i=0;i<n;i++)if(!adj[i].empty()){outv=i;break;}
        }
        dfs(outv);
        for(int i=0;i<n;i++)if((indeg[i]||!adj[i].empty() )&& !vis[i])pos= false;
        if(!pos){
            printf("Impossible\n");
        }
        else {
            vector<int>st,ans;
            for(int i=0;i<n;i++)indeg[i]=0;
            st.push_back(outv);
            while(!st.empty()){
                int u=st.back();
                if(indeg[u]==adj[u].size()){
                    ans.push_back(u);
                    st.pop_back();
                }
                else{
                    int v=adj[u][indeg[u]++];
                    st.push_back(v);
                }
            }
            for(int i=ans.size()-1;i>0;i--)printf("%d ",ans[i]);
            printf("%d\n",ans[0]);
        }
    }
}