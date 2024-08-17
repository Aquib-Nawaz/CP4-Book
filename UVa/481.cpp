#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;
#define pb push_back

vi A,L,L_id,P;

void print(int u){
    if(u==-1)return;
    print(P[u]);
    printf("%d\n",A[u]);
}


int main(){
    int d,n,pos;
    while (scanf("%d",&d)!=-1)A.pb(d);
    n=A.size();
    int k = 0, lis_end = 0;
    L = vi(n,0);
    L_id = vi(n,0);
    P = vi(n,0);
    for(int i=0;i<n;i++){
        pos = lower_bound(L.begin(),L.begin()+k,A[i])-L.begin();
        L[pos] = A[i];
        L_id[pos] = i;
        P[i] = pos?L_id[pos-1]:-1;
        if(pos==k)k++;
        if(pos==k-1)lis_end=i;
    }
    printf("%d\n-\n",k);
    print(lis_end);

}