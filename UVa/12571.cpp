#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int V[230];
#define REP(i,n)for(int i=0;i<n;i++)
int main(){
    int t,n, q, a;
    scanf("%d", &t);
    while(t--){
        memset(V, 0, sizeof V);
        scanf("%d %d", &n, &q);
        REP(i,n){scanf("%d", &a); REP(j,230)V[j] = max(V[j],a&j);}
        REP(i,q){scanf("%d", &a); printf("%d\n", V[a]);}
    }
}