#include <iostream>
#include <cstring>
#include<algorithm>
using namespace std;

char pat[1001];
bool vis[1001];
#define REP(i,n) for(int i=0;i<n;i++)

int main(){
    int n,M,sum; bool f=true;
    while(scanf("%s", pat)!=EOF){
        if(!f)printf("\n");
        f=false;
        printf("%s: ", pat);
        n=strlen(pat), sum=0;
        bool err=false;
        memset(vis,0,sizeof(vis));
        REP(i,n+9){
            if(i<n)
            sum+=pat[i]-'0';
            int nxt = i+pat[i%n]-'0';
            if(nxt==i)continue;
            if(pat[nxt%n]=='0'||vis[nxt]){err=true;}
            vis[nxt]= true;
        }
        if(sum%n!=0){printf("invalid # of balls");
            continue;}
        sum/=n;

        if(err)printf("invalid pattern");
        else printf("valid with %d balls", sum);
    }
}