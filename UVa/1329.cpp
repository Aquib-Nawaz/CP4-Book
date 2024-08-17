#include <iostream>
using namespace std;

int p[20001],d[20001];

int get_parent(int a){
    if(p[a]==a)return a;
    int t=p[a];
    p[a]=get_parent(p[a]);
    d[a] += d[t];
    return p[a];
}

void do_union(int a, int b){
    p[a] = b;
    d[a]  = abs(a-b)%1000;
}

int main(){
    int n,_d,_p,T;
    char c;
    scanf("%d", &T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)d[i]=0, p[i]=i;
        while(scanf(" %c",&c),c!=79){
            if(c=='E'){
                scanf("%d",&_d);
                get_parent(_d);
                printf("%d\n", d[_d]);
            }
            else{
                scanf("%d %d",&_d, &_p);
                do_union(_d,_p);
            }
        }
    }
}