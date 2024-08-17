#include <iostream>
#include <vector>
using namespace std;
typedef vector<int>vi;

vi adjL[26];
bool vis[26];
void dfs(int u){
    vis[u]=true;
    for(auto v:adjL[u]){
        if(!vis[v])dfs(v);
    }
}

int main(){
    int T, N, ret;
    char u,v;
    scanf("%d",&T);
    while(T--){
        scanf(" %c%*c", &u);
        N = u-'A'+1;
        for(int i=0;i<N;i++)adjL[i].clear();
        for(int i=0;i<N;i++)vis[i]=false;
        while(true){
            ret = scanf("%c", &u);
            if(ret==-1||u=='\n')break;
            scanf("%c%*c", &v);
            adjL[u-'A'].push_back(v-'A');
            adjL[v-'A'].push_back(u-'A');
        }
        ret = 0;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                dfs(i);
                ret++;
            }
        }
        printf("%d\n", ret);
        if(T)printf("\n");
    }
}