#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int mt[100];
bool used[100], used1[100];
pair<int,int>Points[100], Points1[100];
vector<int>adj[100];
#define EPS 1e-10
typedef long double ld;

ld dist(int x, int y, int x1, int y1){
    return sqrt(pow((x-x1),2) + pow((y-y1),2));
}

bool try_kuhn(int v){
    if(used[v])return false;
    used[v]= true;
    for(int i:adj[v]){
        if(mt[i]==-1 || try_kuhn(mt[i])){
            mt[i]=v;
            return true;
        }
    }
    return false;
}

int main(){
    int N,M,T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &N,&M);
        for(int i=0;i<N;i++){
            adj[i].clear(), used1[i]= false;
            scanf("%d %d", &Points[i].first, &Points[i].second);
        }
        for(int i=0;i<M;i++){
            int x,y;
            mt[i]=-1;
            scanf("%d%d", &x,&y);
            Points1[i] = {x,y};
            for(int j=0;j<N-1;j++){
                if(dist(x,y,Points[j].first,Points[j].second)+dist(x,y,Points[j+1].first,Points[j+1].second)
                <2*dist(Points[j].first,Points[j].second,Points[j+1].first,Points[j+1].second)+EPS){
                    adj[j].push_back(i);
                    if(mt[i]==-1 && !used1[j]){
                        mt[i]=j;
                        used1[j]=true;
                    }
                }
            }
        }
        for(int i=0;i<N-1;i++){
            if(!used1[i]){
                memset(used, 0, sizeof used);
                try_kuhn(i);
            }
        }
        int k=N;
        for(int i=0;i<M;i++){
            if(mt[i]!=-1)k++;
        }
        printf("%d\n", k);
        for(int i=0;i<N-1;i++){
            printf("%d %d ", Points[i].first, Points[i].second);
            for(int j=0;j<M;j++){
                if(mt[j]==i)printf("%d %d ", Points1[j].first, Points1[j].second);
            }
        }
        printf("%d %d\n", Points[N-1].first, Points[N-1].second);
        if(T)printf("\n");

    }
    return 0;
}