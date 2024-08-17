#include <iostream>
#include <unordered_map>
using namespace std;
int A[2][1000000];

bool can(int k, int n){
    int cur=-1;
    for(int j=0;j<2;j++){
        for(int i=0;i<n;i++){
            if(A[j][i]<=k)continue;
            if(cur==-1)cur=A[j][i];
            else if(A[j][i]!=cur)return false;
            else cur=-1;
        }
    }
    return true;
}

int main(){
    int n,lo=0,hi=0,d;
    scanf("%d",&n);
    unordered_map<int,int>mp;
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&d);
            mp[d]|=1<<i;
            if(mp[d]==3)lo=max(lo,d);
            hi=max(hi,d);
            A[i][j]=d;
        }
    }
    int ans;
    while(lo<=hi){
        int mid=(lo+hi)>>1;
        if(can(mid,n))ans=mid,hi=mid-1;
        else lo=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}
