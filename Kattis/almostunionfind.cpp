#include <iostream>
using namespace std;

int Z[100001],P[100001];
long long S[100001];
int M[100001];

int Find(int x){
    if(P[x]==x) return x;
    return P[x]=Find(P[x]);
}

int _Find(int x){
    if(M[x])return M[x]= Find(M[x]);
    return Find(x);
}

void Union(int x, int y){
    x=_Find(x);
    y=_Find(y);
    if(x==y) return;
    if(Z[x]<Z[y]) swap(x,y);
    P[y]=x;
    Z[x]+=Z[y];
    S[x]+=S[y];
}

void Remove(int x,int y){
    int _x= _Find(x);
    y= _Find(y);
    if(_x==y) return;
    M[x]=y;
    Z[_x]--;Z[y]++;
    S[_x]-=x;S[y]+=x;

}

int main(){
    int n,m,op,x,y;
    while(scanf("%d %d", &n,&m)!=-1){
        for(int i=1;i<=n;i++)P[i]=i,Z[i]=1,S[i]=i,M[i]=0;
        for(int i=0;i<m;i++){
            scanf("%d %d", &op,&x);
            if(op==1||op==2) scanf("%d",&y);
            if(op==1) Union(x,y);
            else if(op==2) Remove(x,y);
            else printf("%d %lld\n",Z[_Find(x)], S[_Find(x)]);
        }
    }
}