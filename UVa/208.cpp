#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>E[21];
int cur[21], used,ans,D,vis,cnt=0;
void dfs(int u){
    vis|=1<<u;
    if(u==0)return;
    for(int i : E[u]){
        if(1<<i&vis)continue;
        dfs(i);
    }
}

void solve(int u,int l){

    if(u==D){
        ans++;
        for(int i=0;i<l;i++)
        {   if(i!=0)printf(" ");
            printf("%d",cur[i]+1);
        }
        printf("\n");
        return;
    }
    if(!(vis&1<<u)){cnt++;return;}
    used^=1<<u;

    for(int i : E[u]){
        if(1<<i&used)continue;
        cur[l]=i;
        solve(i,l+1);
    }
    used^=1<<u;
}

int main(){
    int u,v,C=0;
    cur[0]=0;
    while (scanf("%d",&D)!=EOF){
        vis=0;
        D--;
        for(int i=0;i<20;i++)E[i].clear();
        while(scanf("%d %d",&u,&v),u){
            u--,v--;
            E[u].push_back(v);
            E[v].push_back(u);
        }
        for(int i=0;i<20;i++)sort(E[i].begin(),E[i].end());

        ans=0,used=0;
        dfs(D);
        printf("CASE %d:\n",++C);
        if(vis&1)
            solve(0,1);
        printf("There are %d routes from the firestation to streetcorner %d.\n",ans,D+1);
    }
    fprintf(stderr,"%d\n",cnt);
    return 0;
}