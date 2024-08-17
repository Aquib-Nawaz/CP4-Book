#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

unordered_map<string,int>mp;
int dp[500][500], par[500][500];
char line[10], c;
string file[500];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%s", line), mp[line]=i, file[i]=line;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)dp[i][j]=1000;
    for(int i=0,k;i<n;i++){
        scanf("%*s %d", &k);
        for(int j=0;j<k;j++){
            scanf("%*s ");
            while(true){
                scanf(" %[^,\n]%c", line, &c);
                dp[mp[line]][i]=1;
                par[mp[line]][i]=mp[line];
                if(c=='\n')break;
            }
        }
    }
    for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        if(dp[i][j]>dp[i][k]+dp[k][j]){
            dp[i][j]=dp[i][k]+dp[k][j];
            par[i][j]=par[k][j];
        }
    }
    int mn=-1;
    for(int i=0;i<n;i++){
        if(dp[i][i]<1000 && (mn==-1 || dp[i][i]<dp[mn][mn]))mn=i;
    }
    if(mn==-1)printf("SHIP IT\n");
    else {
        int cur=mn;
        while(true){
            printf("%s ", file[cur].c_str());
            cur=par[mn][cur];
            if(cur==mn)break;
        }
    }
}