#include <iostream>
using namespace std;

int A[700][700];
int N, M, K,P[26], ans;


int Find(int x){
    if(P[x]==x) return x;
    return P[x]=Find(P[x]);
}

void Union(int x, int y){
    x=Find(x);
    y=Find(y);
    if(x==y) return;
    P[y]=x;
    ans--;
}

int main(){
    scanf("%d %d %d", &N,&M,&K);
    char c;
    ans=K;
    for(int i=0;i<26;i++)P[i]=i;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf(" %c",&c);
            A[i][j]=c-'A';
        }
    }
    for(int j=0;j<M;j++){
        int p=A[0][j];
        for(int i=1;i<N;i++){
            Union(p,A[i][j]);
        }
    }
    printf("%d", ans);
}