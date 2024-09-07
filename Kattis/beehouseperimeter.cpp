#include <iostream>
#include <algorithm>
using namespace std;

int g[101][101],cnt=0, dir[6][2]={{1,0}, {0,1}, {-1,0}, {0,-1},
                                  {1,1}, {-1,-1}};

void dfs(int a, int b){
    g[a][b]=1;
    int nx,ny;
    for(auto d:dir){
        nx = a+d[0], ny=b+d[1];
        if(g[nx][ny]==0)dfs(nx,ny);
        else if(g[nx][ny]==-1)cnt++;
    }
}

void dfs1(int a, int b){
    g[a][b]=-1;
    int nx,ny;
    for(auto d:dir){
        nx = a+d[0], ny=b+d[1];
        if(nx>=0&&ny>=0 && nx<101 && ny <101 && g[nx][ny]==-2)dfs1(nx,ny);
    }
}

void getrc(int a, int k, int &r, int &c){
    int sgn=1,cn=k;
    r=1;
    while(a-cn>0){
        a-=cn;
        cn+=sgn;
        r++;
        if(cn==2*k-1)sgn=-1;
    }
    c=a + max(r-k,0);
}

int main(){
    int K,d,a,r,c;
    for(auto & i : g)for(int & j : i)j=-2;
    scanf("%d%d", &K,&d);
    while(d--)scanf("%d", &a), getrc(a,K,r,c),g[r][c]=0;
    dfs1(0,0);
    dfs(r,c);
    printf("%d\n", cnt);
}