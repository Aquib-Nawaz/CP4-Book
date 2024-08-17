#include <iostream>
#include <vector>
using namespace std;

bool vis[51];
int deg[51], g[51][51];
void dfs(int u){
    vis[u]= true;
    for(int v=1;v<=50;v++){
        if(!vis[v] && g[u][v])dfs(v);
    }
}

int main(){
    int T,N,C=0;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &N);
        for(int i=1;i<=50;i++){
            for(int j=1;j<=50;j++)g[i][j]= 0;
            deg[i]=0;
        }
        for(int i=0,u,v;i<N;i++){
            scanf("%d%d", &u,&v);
            ++g[u][v],++g[v][u];
            deg[u]++, deg[v]++;
        }
        bool pos=true;
        for(int i=1;i<=50;i++)pos&=!(deg[i]&1), vis[i]=deg[i]==0;
        int f=-1;
        for(int i=1;i<=50;i++){
            if(!vis[i]){
                if(f==-1){
                    dfs(i), f=i;
                }
                else {
                    pos= false;
                    break;
                }
            }
        }
        printf("Case #%d\n",++C);
        if(!pos)printf("some beads may be lost\n");
        else {
            vector<int> ans, st;
            st.push_back(f);
            //heirholzer algo to compute eulorian tour
            while(!st.empty()){
                int u=st.back(),v;
                if(deg[u]>0){
                    for(v=1;v<=50;v++)if(g[u][v])break;
                    st.push_back(v);
                    --g[u][v],--g[v][u];
                    deg[u]--, deg[v]--;
                }
                else {
                    ans.push_back(u);
                    st.pop_back();
                }
            }
            N=ans.size();
            for(int i=0;i<N-1;i++) {
                printf("%d %d\n", ans[i], ans[i+1]);
            }
        }
        if(T)printf("\n");
    }
}