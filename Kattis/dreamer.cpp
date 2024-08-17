#include <iostream>
#include <cstring>
using namespace std;
int cur[8], ans;
int d,m,y;
int A[10];
char C[27];

bool m31[13] = {false,true,false,true,false,true,false,true,true,false,true,false,true};

bool isLeap(int _y){
    if(_y%400==0)return true;
    if(_y%100==0)return false;
    if(_y%4==0)return true;
    return false;
}

bool vaild(int _d, int _m, int _y){
    if(_y<2000||_m>12||_d>31||_m==0||_d==0)return false;
    if(_m==2 )return _d <= 28+isLeap(_y);
    if(m31[_m]||_d!=31)return true;
    return false;
}

bool date_compare(int _d, int _m, int _y){
    if(_y<y)return true;
    if(_y==y&&_m<m)return true;
    if(_y==y&&_m==m&&_d<d)return true;
    return false;
}

void solve(int l){
    if(l==8){
        int _d = cur[0]*10+cur[1];
        int _m = cur[2]*10+cur[3];
        int _y = cur[4]*1000+cur[5]*100+cur[6]*10+cur[7];
        if(vaild(_d,_m,_y)){
            if(ans==0||date_compare(_d,_m,_y))d=_d,y=_y,m=_m;
            ans++;
        }
        return;
    }
    for(int i=0;i<10;i++){
        if(A[i]==0)continue;
        cur[l]=i;
        A[i]--;
        solve(l+1);
        A[i]++;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf(" %[^\n]", C);
        memset(A,0,sizeof A);
        for(int j=0; j< strlen(C);j++)if(C[j]!=' ')A[C[j]-'0']++;
        ans=0;
        solve( 0);
        printf("%d", ans);
        if(ans)printf(" %02d %02d %d", d, m, y);
        printf("\n");
    }
    return 0;
}