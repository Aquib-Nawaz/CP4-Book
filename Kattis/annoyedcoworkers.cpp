#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;


struct inter{
    ll a,d,cnt;

    ll f() const {
        return a+cnt*d; // return a.
    }

    bool operator<(const inter& b)const{
        ll l=f(),r=b.f();
        if(l!=r)return l>r;
        return b.d<d;
    }
};

//ll f(ll mx, int c){
//    ll cnt=0;
//    for (int i = 0; i < c; i++)cnt+=(mx-A[i])/B[i];
//    return cnt;
//}

int main() {
    int h, c,a,d;
    scanf("%d%d", &h, &c);
    ll mx=0;
    priority_queue<inter>pq;
    for (int i = 0; i < c; i++)scanf("%d%d", &a,&d), mx=max(mx,(ll)a),pq.push({a,d,0});
    while(h>0){
        auto it=pq.top();
        pq.pop();
        h--;
        it.cnt++;
        mx = max(mx,it.a+it.cnt*it.d);
        pq.push(it);
    }

    printf("%lld\n", mx);
}