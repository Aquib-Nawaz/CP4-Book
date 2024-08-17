#include <iostream>
#include <set>
#include <climits>
using namespace std;

int main(){
    int n, m,C=0, d;
    while(scanf("%d", &n)!=-1){
        set<int>st,st1;
        for(int i=0;i<n;i++)scanf("%d", &d), st.insert(d);
        st1=st;
        scanf("%d", &m);
        printf("Case %d:\n",++C);
        for(int i=0;i<m;i++){
            scanf("%d", &d);
            int ans = INT_MAX/2;
            for(auto it=st.begin();it!=st.end();it++){
                st1.erase(*it);
                auto it1 = st1.lower_bound(d-*it);
                if(it1!=st1.end()){
                    if(abs(*it+*it1-d)<abs(ans-d))ans=*it+*it1;
                }
                if(it1!=st1.begin()){
                    it1--;
                    if(abs(*it+*it1-d)<abs(ans-d))ans=*it+*it1;
                }
                st1.insert(*it);
                if(*it>=d)break;
            }
            printf("Closest sum to %d is %d.\n", d, ans);
        }
    }
}