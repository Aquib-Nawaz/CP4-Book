#include <iostream>
#include <unordered_set>
using namespace std;
int arr[100];

unordered_set<int>dp[51];

int main(){
    int n,m, s;
    dp[0]={0};
    while (scanf("%d%d",&n,&m)!=-1){
        s=0;
        for(int i=0;i<n+m;i++)scanf("%d",&arr[i]), s+=arr[i];
        if (n>m)swap(n,m);
        for(int i=1;i<=n;i++)dp[i].clear();
        for(int i=0;i<n+m;i++){
            for(int j=n;j>=1;j--)
                for(auto it:dp[j-1])
                    dp[j].insert(it+arr[i]);
        }
        int mn=1e9, mx=-1e9;
        for(auto it:dp[n]){
            mn = min(mn, it*(s-it));
            mx = max(mx, it*(s-it));
        }
        printf("%d %d\n",mx,mn);
    }
}