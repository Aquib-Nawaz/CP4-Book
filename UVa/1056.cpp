#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string,int>mp;
int dp[50][50];
int main(){
    int n,m,C=0;
    while (scanf("%d%d", &n,&m),n){
        for(int i=0;i<n;i++){for(int j=i+1;j<n;j++)dp[j][i]=dp[i][j]=50;dp[i][i]=0;}
        for(int i=0;i<m;i++){
            string a,b;
            cin>>a>>b;
            if(mp.count(a)==0)mp[a]=mp.size();
            if(mp.count(b)==0)mp[b]=mp.size();
            dp[mp[a]][mp[b]]=dp[mp[b]][mp[a]]=1;
        }
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
        int ans=0;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)ans=max(ans,dp[i][j]);
        printf("Network %d: ",++C);
        if(ans==50)printf("DISCONNECTED\n\n");
        else printf("%d\n\n",ans);
        mp.clear();
    }

}