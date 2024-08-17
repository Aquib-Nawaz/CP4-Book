#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<char, int>mp={{'N', 0}, {'W', 1}, {'S', 2}, {'E', 3}};
int G[10][10], vis[10][10], dir[4][2] = {{-1, 0}, {0,-1}, {1, 0}, {0,1}};

int main(){
    int N,M,C;
    char c;
    while(scanf("%d%d%d", &N,&M,&C), N){
        C--;
        for(int i=0;i<N; i++)for(int j=0;j<M;j++)scanf(" %c", &c), G[i][j]=mp[c], vis[i][j]=0;
        int loop=-1, l=1, t;
        for(int cx=0,cy=C; ;l++){
            vis[cx][cy]=l;
            t=G[cx][cy];
            cx+=dir[t][0], cy+=dir[t][1];
            if(cx<0 || cx>=N || cy<0 || cy>=M)break;
            if(vis[cx][cy]){loop=vis[cx][cy]-1; break;}
        }
        if(loop==-1)printf("%d step(s) to exit\n", l);
        else printf("%d step(s) before a loop of %d step(s)\n", loop ,l-loop);
    }
}