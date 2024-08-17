#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int>adjL[100001];
int vis[100001];
int arr[100000];

int main(){
    int N, u, v;
    scanf("%d", &N);
    memset(vis, -1, sizeof vis);
    for(int i=1;i<N;i++){
        scanf("%d%d", &u, &v);
        arr[i] = u;
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }
    queue<int>q;
    q.push(1);
    vis[1]=0;
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int x:adjL[u]){
            if(vis[x]==-1)
                vis[x]=1-vis[u],q.push(x);
        }
    }
    for(int i=1;i<N;i++)printf("%d\n", vis[arr[i]]);

}