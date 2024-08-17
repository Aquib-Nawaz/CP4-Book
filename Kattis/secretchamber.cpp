#include <iostream>
#include <cstring>
using namespace std;

bool dp[26][26];
char u[51], v[51];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    memset(dp,0,sizeof dp);
    for(int i=0;i<26;i++)dp[i][i]=true;
    for(int i=0;i<n;i++){
        char a,b;
        scanf(" %c %c",&a,&b);
        dp[a-'a'][b-'a']=true;
    }
    for(int k=0;k<26;k++)
        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
                if(dp[i][k]&&dp[k][j])dp[i][j]=true;
    for(int i=0;i<m;i++){
        scanf("%s%s", u, v);
        bool same=strlen(u)==strlen(v);
        n= strlen(u);
        for(int j=0;j<n && same;j++){
            if(!dp[u[j]-'a'][v[j]-'a'])same=false;
        }
        if(same)printf("yes\n");
        else printf("no\n");
    }

}