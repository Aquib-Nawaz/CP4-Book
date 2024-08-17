#include <iostream>
using namespace std;

int P[1000001],N,K;
int Find(int x){
    if(P[x]==x) return x;
    return P[x]=Find(P[x]);
}

void Union(int x, int y){
    x=Find(x);
    y=Find(y);
    if(x==y) return;
    P[y]=x;
}

int main(){
    scanf("%d %d", &N,&K);
    for(int i=1;i<=N;i++) P[i]=i;
    for(int i=0;i<K;i++){
        int x,y;
        scanf("%d %d", &x,&y);
        Union(x,y);
    }
    bool f=true;
    for(int i=1;i<=N/2;i++){
        if(Find(i)!=Find(N-i+1)) f=false;
    }
    printf("%s", f?"Yes":"No");
}