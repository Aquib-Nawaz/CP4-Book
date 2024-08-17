#include <iostream>
#include <unordered_map>
using namespace std;
char G[100][101];
char seq[50001];
unordered_map<char,int>mp={{'N', 0}, {'S', 2}, {'O', 1}, {'L', 3}};
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};

int N,M,S;
bool inRange(int x, int y){
    return x>=0 && x<N && y>=0 && y<M && G[x][y]!='#';
}

int main(){
    int cx,cy,cd;
    while(scanf("%d%d%d", &N,&M,&S), N){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                scanf(" %c", &G[i][j]);
                if(G[i][j]!='.' && G[i][j]!='*' && G[i][j]!='#')cx=i,cy=j,cd=mp[G[i][j]];
            }
        }
        scanf(" %s", seq);
        int ans=0;
        for(int i=0,nx,ny;i<S ;i++){
            if(seq[i]=='D')cd=(cd+3)%4;
            else if(seq[i]=='E')cd = (cd+1)%4;
            else{
                nx=cx+dir[cd][0];
                ny=cy+dir[cd][1];
                if(inRange(nx,ny)){
                    cx=nx,cy=ny;
                    if(G[cx][cy]=='*')G[cx][cy]='.',ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
}