#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int>A[50];
int dp[51];
int cursz=0;
void solve(int c){
    bool f=false;
    for(int i=0;i<cursz;i++){
        int rt = (int)(sqrt(c+A[i].back())+1e-9);
        if(rt*rt== c+A[i].back()){
            f=true;
            A[i].push_back(c);
            dp[cursz]=max(c,dp[cursz]);
            solve(c+1);
            A[i].pop_back();
        }
    }
    if(cursz==50||f) return;
    A[cursz++].push_back(c);
    dp[cursz]=max(c,dp[cursz]);
    solve(c+1);
    A[cursz-1].pop_back();
    cursz--;
}

int main(){
    int T,n;
    scanf("%d", &T);
    memset(dp,0,sizeof dp);
    solve(1);
    while(T--){
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
}