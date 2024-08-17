#include <iostream>
#include <cstring>
using namespace std;

char W[27];

int main(){
    int T,n,ans,cur,t;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        cur=(1<<26)-1,ans=0;

        for(int i=0;i<n;i++){
            scanf("%s",W);
            t=0;
            for(int j=0;j< strlen(W);j++)t|=1<<W[j]-'a';
            cur&=t;
            if(cur==0)ans++,cur=t;
        }
        printf("%d\n",ans);
    }
}