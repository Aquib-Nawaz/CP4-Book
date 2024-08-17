#include <iostream>
using namespace std;
int arr[100][100];
bool check(int i, int lj, int rj){
    int val = arr[i][rj];
    if(lj>0)val-=arr[i][lj-1];
    return val==0;
}

#define REP(i,n) for(int i=0;i<n;i++)

int main(){
    int n,m, st, ans;
    while(scanf("%d%d",&n,&m),n){
        REP(i,n)REP(j,m)scanf("%d",&arr[i][j]), arr[i][j]+=j==0?0:arr[i][j-1];
        ans = 0;
        REP(lj,m)for(int rj=lj;rj<m;rj++)
        {
            st=0;
            REP(i,n){
                if(!check(i,lj,rj))st=i+1;
                else ans=max(ans,(rj-lj+1)*(i-st+1));
            }
        }
        printf("%d\n",ans);
    }
}