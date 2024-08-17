#include <iostream>
#include <stack>
#include <string>
using namespace std;
int p[5];
bool solve(string &s){
    stack<bool>st;
    char c;
    bool l,r;
    for(int i=s.size()-1;i>=0;i--){
        c=s[i];
        if(c>'o')st.push(p[c-'p']);
        else if(c=='N'){
            l = st.top();
            st.pop();
            st.push(!l);
        }
        else{
            l = st.top();
            st.pop();
            r = st.top();
            st.pop();
            switch (c) {
                case 'K':
                    st.push(l&r);
                    break;
                case 'A':
                    st.push(l|r);
                    break;
                case 'C':
                    st.push(!l|r);
                    break;
                case 'E':
                    st.push(l==r);
                    break;
                default:
                    break;
            }
        }
    }
    return st.top();
}

#define REP(i)for(i=0;i<2;i++)

int main(){
    string s;
    bool err;
    while(cin>>s,s!="0") {
        err=false;
        REP(p[0])REP(p[1])REP(p[2])REP(p[3])REP(p[4])if(!solve(s))err= true;
        if(err)cout<<"not"<<endl;
        else cout<<"tautology"<<endl;
    }
}