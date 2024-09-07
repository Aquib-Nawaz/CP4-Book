#include <iostream>
#include <cstdlib>
using namespace std;
typedef long long ll;
int V[101][2];
ll gcd(ll a, ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int main(){
    int N,Q;
    scanf("%d%d", &N,&Q);
    for(int i=0;i<N;i++)scanf("%d %d", &V[i][0], &V[i][1]);
    for(int i=0;i<Q;i++){
        int a,b,v;
        scanf("%d%d%d", &a,&b,&v);
        a--,b--;
        ll den = V[a][1]-V[a][0];
        ll num = V[b][0]*den + (ll)(V[b][1]-V[b][0])*(v-V[a][0]);
        ll g = gcd(abs(num),abs(den));
        num/=g, den/=g;
        if(den<0)num=-num, den=-den;
        printf("%lld/%lld\n", num, den);
    }
}