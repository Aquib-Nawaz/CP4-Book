#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string s;
    while (getline(cin , s)) {
        unordered_set<int>st;
        int d;
        stringstream ss(s);
        while (ss >> d) st.insert(d);
        getline(cin,s);
        ss = stringstream(s);
        int f=0, nf=0;
        while (ss>> d){
            if(st.count(d))f++;
            else nf++;
        }
        if(nf==0){
            if(f==st.size())printf("A equals B\n");
            else printf("B is a proper subset of A\n");
            continue;
        }
        if(f==st.size())printf("A is a proper subset of B\n");
        else if(f==0) printf("A and B are disjoint\n");
        else printf("I'm confused!\n");
    }
}