#include <iostream>
#include <utility>
using namespace std;

pair<long long,int> dp[26][26];
int par[26][26];
int pat[26];
int main(){
    int N, M,Q;
    char u,v;
    int d;
    scanf("%d%d",&N,&M);
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++)dp[i][j]={1e15,-1};
        dp[i][i]={0,0};
    }
    for(int i=0;i<M;i++){
        scanf(" %c %c %d", &u,&v,&d);
        dp[u-'A'][v-'A']={d,1};
        dp[v-'A'][u-'A']={d,1};
        par[u-'A'][v-'A']=u-'A';
        par[v-'A'][u-'A']=v-'A';
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                pair<long long,int>temp;
                temp.first = dp[j][i].first+dp[i][k].first;
                temp.second = dp[j][i].second+dp[i][k].second;
                if(dp[j][k]>temp){
                    dp[j][k]=temp;
                    par[j][k]=par[i][k];
                }
            }
        }
    }
    scanf("%d",&Q);
    while(Q--){
        scanf(" %c %c", &u,&v);
        u-='A', v-='A';
        int l=dp[u][v].second;
        pat[0]=u;
        for(int i=0;i<l;i++){
            pat[l-i]=v;
            v=par[u][v];
        }
        printf("%c", u+'A');
        for(int i=1;i<=l;i++){
            printf(" %c",pat[i]+'A');
        }
        printf("\n");
    }
}