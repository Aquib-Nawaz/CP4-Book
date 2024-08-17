#include <iostream>
using namespace std;

int compute_phi(int n){
    int phi = n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n = n/i;
            }
            phi = phi - phi/i;
        }
    }
    if(n>1){
        phi = phi - phi/n;
    }
    return phi;
}

int main(){
    int T;
    scanf("%d",&T);
    int n,e,p,q,phi,_phi;
    while(T--){
        scanf("%d %d",&n,&e);
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                p=i;
                q=n/i;
                break;
            }
        }
        phi = (p-1)*(q-1);
        _phi = compute_phi(phi)-1;
        long long pow=1,inv=1;
        pow=e;
        for(int i=0;1<<i<=_phi;i++){
            if(_phi&(1<<i)){
                inv=inv*pow%phi;
            }
            pow=pow*pow%phi;
        }
        printf("%lld\n",inv);
    }
}