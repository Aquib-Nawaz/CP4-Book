#include <iostream>
#include <queue>
using namespace std;

int dist[10000], sm[10];

int main(){
    int l,u,r,C=0;

    while (scanf("%d%d%d", &l,&u,&r), l||u||r){
        for (int & i : dist) i = -1;
        for(int i=0;i<r;i++)scanf("%d", sm+i);
        queue<int>q;
        q.push(l);
        dist[l]=0;
        while(!q.empty()){
            l=q.front();
            q.pop();
            if(u==l)break;
            for(int i=0;i<r;i++){
                int v=(l+sm[i])%10000;
                if(dist[v]==-1){
                    dist[v]=dist[l]+1;
                    q.push(v);
                }
            }
        }
        printf("Case %d: ",++C);
        if(dist[u]==-1)printf("Permanently Locked\n");
        else printf("%d\n",dist[u]);
    }
}