#include <iostream>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)

int tree[200001], mp[100001], t;

void build(int m, int r){
    for(int i=1;i<=m+r;i++){
        if(i<=m){
            tree[i]++;
            mp[i]=m-i+1;
        }
        if(i+(i&-i)<=m+r)
            tree[i+(i&-i)]+=tree[i];
    }
    t=m;
}

void update(int i, int v, int arr[], int n){for(;i<=n;i+=i&-i)arr[i]+=v;}
int query(int i, int arr[]){int sum=0;for(;i;i-=i&-i)sum+=arr[i]; return sum;}

void process(int a, int m, int r){
    printf("%d", m-query(mp[a],tree));
    update(mp[a], -1, tree, m+r);
    t++;
    update(t, 1, tree, m+r);
    mp[a]=t;
}

int main(){
    int T,m,r, d;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&m,&r);
        memset(tree, 0, sizeof tree);
        build(m,r);
        REP(i,r){
            scanf("%d", &d);
            process(d,m, r);
            if(i!=r-1)
                printf(" ");
            else
                printf("\n");
        }

    }
}