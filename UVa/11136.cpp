#include <iostream>
#include <set>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)

int main(){
    int n,k,d;
    long long ans;
    multiset<int>::iterator it;
    while(scanf("%d",&n),n){
        ans=0;
        multiset<int>s;
        REP(i,n){
            scanf("%d", &k);
            REP(j,k)scanf("%d", &d),s.insert(d);
            ans-=*s.begin();
            s.erase(s.begin());
            it = s.end();
            it--;
            ans+=*it;
            s.erase(it);
        }
        printf("%lld\n", ans);
    }

}