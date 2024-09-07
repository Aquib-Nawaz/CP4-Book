#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

int g[41][41], dir[6][2]={{1,0}, {0,1}, {-1,0}, {0,-1},
                                  {1,1}, {-1,-1}};
int dist[41][41];
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
bool inRange(int r, int c, int k){
    int mxc=r+k-1,mnc=1;
    if(r>k)mxc = 2*k-1, mnc=r-k+1;
    return c>=mnc && c<=mxc && r>0&&r<=2*k-1 && g[r][c]==0;
}
int main(){
    int R,N,A,B,X,r,c,a;
    scanf("%d%d%d%d%d", &R,&N,&A,&B,&X);
    for(auto & i : g)for(int & j : i)j=0;
    while(X--)scanf("%d", &a), getrc(a,R,r,c),g[r][c]=-1;
    int dr,dc;
    getrc(A,R,r,c), getrc(B,R,dr,dc);
    for(auto &i:dist)for(auto &j:i)j=-1;
    queue<pair<int,int>>q;
    q.emplace(r,c);
    dist[r][c]=0;
    while(!q.empty()){
        r =q.front().first, c=q.front().second;
        q.pop();
        if(r==dr && c==dc || dist[r][c]==N)break;
        for(auto & i : dir){
            int nr = r+i[0], nc = c+i[1];
            if(inRange(nr,nc,R)&&dist[nr][nc]==-1)dist[nr][nc]=dist[r][c]+1,q.emplace(nr,nc);
        }
    }
    if(dist[dr][dc]!=-1)printf("%d\n", dist[dr][dc]);
    else printf("No\n");
}