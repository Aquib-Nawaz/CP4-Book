#include <iostream>
#include <cstring>
using namespace std;

typedef unsigned long long ull;
char w[21], ans[21];
ull fac[21];

void set(int n, char c){
    int  i=-1;

    while(n>=0){
        i++;
        n-=ans[i]==0;
    }
    ans[i]=c;
}

int main(){
    fac[0]=1;
    for(int i=1;i<21;i++) fac[i]=fac[i-1]*i;
    int T,C=0;
    scanf("%d",&T);
    while(T--) {
        ull k;
        scanf("%s%llu",w,&k);
        k--;
        int len= strlen(w);
        for(int i=0;i<=len;i++) ans[i]=0;
        for(int i=0;i<len;i++)
            set(k/fac[len-i-1],w[i]), k%=fac[len-i-1];
        ans[len]=0;
        printf("Case %d: %s\n",++C,ans);
    }

}