#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i = 0; i < n; i++)
int main(){
    int T,N,S,Q, n, d, ans;
    scanf("%d", &T);
    while(T--){
        ans=-2;
        scanf("%d %d %d", &N, &S, &Q);
        stack<int> st;
        queue<int> q[N];
        int unloaded=0;
        REP(i,N){
            scanf("%d", &n);
            REP(j,n){
                scanf("%d", &d);
                q[i].push(d);
            }
            unloaded+=n;
        }
        while(unloaded>0){
            REP(i,N){
                ans+=2;
                while(!st.empty()){
                    if(st.top()==i+1)st.pop(),ans++, unloaded--;
                    else if(q[i].size()<Q){
                        q[i].push(st.top());
                        st.pop();
                        ans++;
                    }
                    else break;
                }
                while(!q[i].empty()&&st.size()<S){
                    st.push(q[i].front());
                    q[i].pop();
                    ans++;
                }
                if(unloaded==0)break;
            }
        }
        printf("%d\n", max(ans, 0));
    }
}