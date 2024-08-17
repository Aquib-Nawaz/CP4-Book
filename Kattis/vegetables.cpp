#include <iostream>
#include <cmath>
#include <set>
using namespace std;

typedef long double ld;
struct P{
    int v,cut=0,idx;
    bool operator<(const P& rhs) const {
        ld lv=ld(v)/(cut+1),rv=ld(rhs.v)/(rhs.cut+1);
        if(abs(rv-lv)<1e-10){
            if(cut!=rhs.cut)return cut>rhs.cut;
            return idx<rhs.idx;
        }
        return lv < rv;
    }
};

ld veg_ratio(P lhs,P rhs){
    return lhs.v/(lhs.cut+1.0)/rhs.v*(rhs.cut+1.0);
}

int main(){
    ld t,tmp;
    int n,d;
    scanf("%Lf %d",&t,&n);
    set<P>pq;
    for(int i=0;i<n;i++)scanf("%d",&d), pq.insert({d,0,i});
    int ans=0;
    // mn  mn/t
    while(true){
        tmp=veg_ratio(*pq.begin(),*pq.rbegin());
        if(tmp>=t-1e-4)break;
        ans++;
        P p = *pq.rbegin();
        pq.erase(p);
        p.cut++;
        pq.insert(p);
    }
    printf("%d",ans);
}