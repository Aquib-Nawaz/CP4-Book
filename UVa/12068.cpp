#include <iostream>
using namespace std;
int pq[8];
typedef long long ll;

ll gcd(ll a, ll b){
    return b?gcd(b,a%b):a;
}

int main(){
    int T,C=0;
    scanf("%d", &T);
    while (T--){
        int n;
        scanf("%d", &n);
        ll pr=1;
        for(int i=0;i<n;i++)scanf("%d", pq+i), pr*=pq[i];
        ll sum = 0;
        for(int i=0;i<n;i++)sum+=pr/pq[i];
        pr*=n;
        ll g = gcd(sum, pr);
        printf("Case %d: %lld/%lld\n",++C, pr/g, sum/g);
    }
}