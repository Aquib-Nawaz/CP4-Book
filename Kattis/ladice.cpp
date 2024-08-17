#include <iostream>
using namespace std;

int p[300001],d[300001];

int get_parent(int a){
    if(p[a]==a)return a;
    return p[a] = get_parent(p[a]);
}

int do_union(int a, int b){
    a= get_parent(a);b = get_parent(b);
    if(a!=b){
        p[a]=b;
        d[b]+=d[a];
    }
    return b;
}

int main(){
    int n,m,a,b;
    scanf("%d %d", &n,&m);
    for(int i=1;i<=m;i++)p[i]=i,d[i]=1;
    for(int i=0;i<n;i++){
        scanf("%d %d", &a,&b);
        b=do_union(a,b);
        if(d[b]>0)printf("LADICA"),d[b]--;
        else printf("SMECE");
        if(i!=n-1)printf("\n");
    }

}