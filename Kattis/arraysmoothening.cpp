#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;

unordered_map<int,int>A;

ll f(int mn, int c){
    ll cnt=0;
    for (auto i:A){
        if(i.second<=mn)continue;
        cnt+=i.second-mn;
    }
    return cnt;
}

int main() {
    int h, c,d;
    scanf("%d%d", &c, &h);
    int lo=0,hi=0,mid;
    for (int i = 0; i < c; i++)scanf("%d", &d),A[d]++,hi=max(A[d],hi);
    while(hi-lo>1){
        mid=(lo+hi)>>1;
        if (f(mid,c)<=h)hi=mid;
        else lo=mid+1;
    }
    if(hi!=lo && f(lo,c)>h){
        lo++;
    }
    printf("%d\n", lo);
}