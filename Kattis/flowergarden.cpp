#include <iostream>
#include <cmath>
using namespace std;

#define MAX 20001
typedef long double ld;
bool isPrime[MAX];

void seive(){
    for(bool &i:isPrime)i= true;
    isPrime[1]= false;
    for(int i=2;i*i<MAX;i++){
        if(isPrime[i]){
            for(int j=i*i;j<MAX;j+=i)isPrime[j]= false;
        }
    }
}

int main(){
    int T;
    seive();
    scanf("%d", &T);
    while (T--){
        int n,d;
        scanf("%d %d", &n, &d);
        int ans=0, px=0,py=0,x,y;
        ld cd=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d", &x,&y);
            cd+=sqrt((x-px)*(x-px)+(y-py)*(y-py));
            if(cd<=d&&isPrime[i])ans=i;
            px=x,py=y;
        }
        printf("%d\n", ans);
    }
}