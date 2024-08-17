#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[200][31], arr[200],N,K, pref[201], temp[31];
int takes[200][31];

int getval(int l, int r){
    if(l+1>=r)return arr[r]-arr[l];
    int mid = (l+r)/2;
    return arr[mid]*(mid-l) - (pref[mid-1]-(l==0?0:pref[l-1])) + (pref[r]-pref[mid])-arr[mid]*(r-mid);
}

int solve(int l,  int k){
    if(k==1) return getval(l,N-1);
    int &ans = dp[l][k],t;
    if(ans!=-1) return ans;
    ans=1e9;
    for(int i=l;i<N-1;i++){
        t = getval(l,i)+solve(i+1, k-1);
        if(ans>t) ans = t, takes[l][k]=i+1;
    }
    return ans;
}

int main(){
    int C=0,d;
    while(scanf("%d%d",&N,&K),N){
        pref[0] = 0;
        for(int i=0;i<N;i++)scanf("%d",&d),arr[i]=d,pref[i]=i==0?arr[i]:pref[i-1]+arr[i];
        memset(dp,-1,sizeof dp);
        int ans = solve(0,K);
        printf("Chain %d\n",++C);
        for(int i=0,lb=0,ub;i<K;i++){
            ub = K-i==1?N:takes[lb][K-i];
            printf("Depot %d at restaurant %d serves restaurant",i+1,(lb+ub+1)/2 );
            if(lb+1!=ub)printf("s %d to %d\n",lb+1,ub);
            else printf(" %d\n",lb+1);
            lb=ub;
        }
        printf("Total distance sum = %d\n",ans);
        printf("\n");
    }
}