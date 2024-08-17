#include <iostream>
#include <cstring>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)

int tree[(int)1e7+1], A[1<<24], CZ[30], N ,t=0, num=0 ,miss[30];
void update(int i, int v){for(;i<=1e7;i+=i&-i) tree[i] += v;}
int query(int i){int sum = 0;for(;i>0;i-=i&-i) sum += tree[i]; return sum;}

void process(int v){
    t++;
    if(A[v]){
        int needed_sz = num - query(A[v]-1);
        for(int i=0; i<N&&CZ[i]<needed_sz; ++i)miss[i]++;
        update(A[v], -1);
    }
    else {
        num++;
        REP(i,N)miss[i]++;
    }
    A[v]=t;
    update(t, 1);
}

char cmd[10];

int main(){
    int b,y,n;
    memset(tree, 0, sizeof tree);
    memset(A, 0, sizeof A);
    scanf("%d", &N);
    REP(i,N)scanf("%d", CZ+i);
    while(scanf("%s", cmd), strcmp(cmd, "END")!=0){
        if(cmd[0]=='A'){
            scanf("%d", &b);
            process(b);
        }
        else if(cmd[0]=='R'){
            scanf("%d %d %d", &b, &y, &n);
            REP(k,n)process(b+k*y);
        }
        else{
            REP(i,N-1)printf("%d ", miss[i]);
            printf("%d\n", miss[N-1]);
            memset(miss, 0, sizeof miss);
        }
    }
}