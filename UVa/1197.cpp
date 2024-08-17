#include <iostream>
using namespace std;

int p[30000];


int get_parent(int a){
    if(p[a]==a)return a;
    return p[a]=get_parent(p[a]);
}

void do_union(int a, int b){
    p[get_parent(a)] = get_parent(b);
}

int main(){
    int n,m,k,d,_p,cnt;
    while(scanf("%d %d", &n,&m),n){
        for(int i=0;i<n;i++)p[i]=i;
        for(int i=1;i<=m;i++){
            scanf("%d %d",&k, &_p);
            for(int j=0;j<k-1;j++)scanf("%d", &d), do_union(d,_p);
        }
        d = get_parent(0);
        cnt=0;
        for(int i=0;i<n;i++)if(d== get_parent(i)) cnt++;
        printf("%d\n", cnt);
    }
}