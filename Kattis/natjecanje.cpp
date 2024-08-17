#include <iostream>
using namespace std;

pair<int,int>P[10];
int ans,s=0,r=0;
void solve(int id, int n, int cur){
    if(id==n){
        ans = min(ans, __builtin_popcount((cur&s)^s));
        return;
    }
    solve(id+1,n,cur|1<<P[id].first);
    solve(id+1,n,cur|1<<P[id].second);
}

int main(){
    int N,S,R,d;
    scanf("%d %d %d",&N,&S,&R);
    for(int i=0;i<S;i++)scanf("%d",&d),d--,s|=(1<<d);
    for(int i=0;i<R;i++)scanf("%d",&d),d--,r|=(1<<d);
    int t = s&r;
    s^=t;
    r^=t;
    S-=__builtin_popcount(t);
    R-=__builtin_popcount(t);

    for(int i=0,j=0;i<N;i++){
        if((r&(1<<i))==0)continue;
        if(i==0)P[j++]={1,1};
        else if(i==N-1) P[j++]={i-1,i-1};
        else P[j++]={i-1,i+1};
    }
    ans=S;
    solve(0,R,0);
    printf("%d\n",ans);
    return 0;
}