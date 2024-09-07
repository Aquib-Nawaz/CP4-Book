#include <iostream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int x;
    string s;
    while(scanf("%d ", &x)==1){
        getline(cin,s);
        stringstream ss(s);
        stack<int>st;
        int d,n;
        while(ss >> d)st.push(d);
        long long ans=0,p=1;
        st.pop();
        n=1;
        while(!st.empty())d=st.top(),st.pop(),ans+=d*p*n,p*=x,n++;
        printf("%lld\n", ans);
    }
}