#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
#define REP(i,s,n) for(int i=s;(i)<(n);(i)++)

int A[5][5];
int i0,i1,i2,i3,i4,T,x,y,d,n;
int get_min_distance(int i,int j, int j0, int j1, int j2, int j3, int j4){
    int ans=100;
    ans = min(ans,abs(i-j0/5)+abs(j-j0%5));
    ans = min(ans, abs(i-j1/5)+abs(j-j1%5));
    ans = min(ans, abs(i-j2/5)+abs(j-j2%5));
    ans = min(ans, abs(i-j3/5)+abs(j-j3%5));
    ans = min(ans, abs(i-j4/5)+abs(j-j4%5));
    return ans;
}
int get_distance(int j0, int j1, int j2, int j3, int j4){
    int ret=0;
    REP(i,0,5)REP(j,0,5)ret+=A[i][j]* get_min_distance(i,j,j0,j1,j2,j3,j4);
    return ret;
}
int main(){
    scanf("%d", &T);
    while(T--){
        memset(A,0,sizeof A);
        scanf("%d", &n);
        REP(i,0,n)scanf("%d %d %d", &x, &y, &d),A[x][y]=d;
        int ans = INT_MAX;
        REP(j0,0,25)REP(j1,j0+1,25)REP(j2,j1+1,25)REP(j3,j2+1,25)REP(j4,j3+1,25){
            int t = get_distance(j0,j1,j2,j3,j4);
            if(t<ans)ans=t,i0=j0,i1=j1,i2=j2,i3=j3,i4=j4;
        }
        printf("%d %d %d %d %d\n", i0, i1, i2, i3, i4);
    }


}