#include <iostream>
#include <queue>
using namespace std;

struct node{
    int x,y;
    bool reachable(const node& other) const {
        return abs(x-other.x)+abs(y-other.y)<=1000;
    }
}nodes[102];
bool vis[102];
int main(){
    int T,n;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        n+=2;
        for(int i=0;i<n;i++)scanf("%d%d", &nodes[i].x, &nodes[i].y), vis[i]=false;
        queue<int>q;
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            if(u==n-1)break;
            for(int i=0;i<n;i++)if(nodes[u].reachable(nodes[i])&&!vis[i])vis[i]=true, q.push(i);
        }
        if(vis[n-1])printf("happy\n");
        else printf("sad\n");
    }
}