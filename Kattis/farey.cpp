#include <iostream>
using namespace std;
#define MAX 10001
int ephi[MAX];
void sieve(){
    for(int i=0;i<MAX;i++)ephi[i]=i;
    ephi[1]=0;
    for(int i=2;i<MAX;i++){
        if(ephi[i]==i){
            for(int j=i;j<MAX;j+=i){
                ephi[j]-=ephi[j]/i;
            }
        }
    }
    for(int i=1;i<MAX;i++)ephi[i]+=ephi[i-1];
}

int main(){
    int T;
    sieve();
    scanf("%d",&T);
    while(T--){
        int c,n;
        scanf("%d%d",&c,&n);
        printf("%d %d\n",c, 2+ephi[n]);
    }
}