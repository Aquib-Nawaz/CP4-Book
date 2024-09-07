#include <iostream>
using namespace std;
#define MAX 4000001
long long ephi[MAX], ans[MAX];

void sieve(){
    for(int i=1;i<MAX;i++)ephi[i]=i;
    for(int i=2;i<MAX;i++){
        if(ephi[i]==i){
            for(int j=i;j<MAX;j+=i){
                ephi[j]-=ephi[j]/i;
            }
        }
    }
    for(int i=1;i<MAX;i++){
        for(int j=2;j*i<MAX;j++){
            ans[i*j]+=i*ephi[j];
        }
    }

    for(int i=1;i<MAX;i++)ans[i]+=ans[i-1];
}

int main(){
    int n;
    sieve();
    while(scanf("%d",&n),n){
        printf("%lld\n",ans[n]);
    }
    return 0;

}