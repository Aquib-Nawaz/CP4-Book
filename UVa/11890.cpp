#include <iostream>
#include <cstring>
#include <utility>
#include <stack>
#include <algorithm>
using namespace std;

char expr[100001];
int A[100000],len;

int solve(int &id){
    int p=0,ne=0,_p,_ne;
    bool inv=false;
    char c;
    stack<pair<int,int>>st;
    stack<bool>st1;
    for(int i=id;i<len;i++){
        c=expr[i];
        if(c=='x'){
            if(inv)ne++;
            else p++;
        }
        else if(c=='-' || c=='+'){
            inv=c=='-';
        }
        else if(c==')'){
            _p=p,_ne=ne;
            p=st.top().first,ne=st.top().second;
            inv=st1.top();
            st.pop();st1.pop();
            if(inv)p+=_ne,ne+=_p;
            else p+=_p,ne+=_ne;
        }
        else if(c=='('){
            st.emplace(p,ne);
            st1.push(inv);
            p=ne=0;
            inv=false;
        }
    }
    return ne;
}

int main() {
    int T,ans,id,n;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", expr);
        len = strlen(expr);
        scanf("%d", &n);
        for(int i=0;i<n;i++)scanf("%d", &A[i]);
        sort(A,A+n);
        ans=id=0;
        auto it= solve(id);
        for(int i=0;i<n;i++)ans+=(i<it?-1:1)*A[i];
        printf("%d\n", ans);
    }
}