#include <iostream>
#include <cmath>;
using namespace std;

int solve(int n,int k){
    int ret=0;
    for(int i=n-1;i>=0;i--){
        int j=1<<i;
        if(k&j){
            k=2*j-k-1;
            ret|=j;
        }
    }
    return ret;
}

int solve_rev(int n){
    int ret=0;
    for(int i=0;i<n;i++){
        int j=1<<i;
        ret|=j;
    }
    return ret;
}

int main(){
    int T,n,k;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &n, &k);
        printf("%d\n",solve(n,k));
    }
}