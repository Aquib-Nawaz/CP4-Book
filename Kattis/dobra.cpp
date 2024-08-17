#include <iostream>
#include <cstring>
using namespace std;

char W[101];
int n;
bool hasL=false;
int v=0,c=0;
long long tot=0;

long long _pow(int x, int y){
    long long ans=1;
    for(int i=0;i<y;i++)ans*=x;
    return ans;
}

void solve(int l){
    if(l==n){
        long long ans = _pow(21,c)-(hasL?0:_pow(20,c));
        ans*=_pow(5,v);
        tot+=ans;
        return;
    }
    if(W[l]!=2){
        if(l<2||W[l-1]!=W[l]||W[l-2]!=W[l])
            solve(l+1);
        return;
    }
    if(l<2||W[l-1]!=1||W[l-2]!=1){
        W[l]=1;
        v++;
        solve(l+1);
        v--;
        W[l]=2;
    }
    if(l<2||W[l-1]!=0||W[l-2]!=0){
        W[l]=0;
        c++;
        solve(l+1);
        c--;
        W[l]=2;
    }
}

int main(){
    scanf("%s",W);
    n= strlen(W);
    for(int i=0;i<n;i++){
        if(W[i]=='L')hasL=true;
        if(W[i]=='_')W[i]=2;
        else if(W[i]=='A'||W[i]=='E'||W[i]=='I'||W[i]=='O'||W[i]=='U')W[i]=1;
        else W[i]=0;
    }
    solve(0);
    printf("%lld",tot);
}