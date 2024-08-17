#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 1000001
int tree[MAXN];
void update(int i, int v, int n){for(;i<=n;i+=i&-i)tree[i]+=v;}
int query(int i){int sum=0;for(;i;i-=i&-i)sum+=tree[i]; return sum;}

int main(){
    memset(tree, 0, sizeof tree);
    int n, q, l, r;
    char c;
    scanf("%d %d", &n, &q);
    while(q--) {
        scanf(" %c %d", &c, &l);
        if(c=='F'){
            int updt = query(l)==query(l-1)?1:-1;
            update(l, updt, n);
        }
        else{
            scanf("%d", &r);
            printf("%d\n", query(r)-query(l-1));
        }
    }
}