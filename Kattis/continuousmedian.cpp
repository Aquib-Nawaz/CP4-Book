#include <iostream>
#include <queue>
using namespace std;

#define REP(i,n) for (int i=0;i<n;i++)

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        long long ans=0;
        priority_queue<int> s1;
        priority_queue<int,vector<int>, greater<int>>s2;
        REP(i,n){
            int d;
            scanf("%d", &d);
            if(s1.size()==s2.size()){
                if(!s2.empty()&&s2.top()<d){
                    int t = s2.top();
                    s2.pop();
                    s2.push(d);
                    d=t;
                }
                s1.push(d);
                ans += s1.top();
            }
            else {
                if(!s1.empty()&&s1.top()>d){
                    int t = s1.top();
                    s1.pop();
                    s1.push(d);
                    d=t;
                }
                s2.push(d);
                ans+=(s2.top()+s1.top())/2;
            }
        }
        printf("%lld\n", ans);
    }
}