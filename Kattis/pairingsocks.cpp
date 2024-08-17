#include <iostream>
#include <stack>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
int main(){
    int n,d;
    scanf("%d", &n);
    stack<int>m,a;
    REP(i,2*n)scanf("%d", &d),m.push(d);
//    REP(i,2*n)m.push(a.top()),a.pop();
    int ans=0;
    while(!m.empty()){
        while(!m.empty()&&(a.empty()||a.top()!=m.top()))ans++,a.push(m.top()),m.pop();
        while(!m.empty()&&!a.empty()&&a.top()==m.top())ans++,a.pop(),m.pop();
    }
    if(a.empty())
        printf("%d", ans);
    else
        printf("impossible");
}