#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
#include <unordered_set>
using namespace std;

bitset<100>A[100];
char line[10];
int main(){
    int T,p,t;
    scanf("%d",&T);
    string s;
    while(T--){
        scanf("%d%d ",&p,&t);
        for(int i=1;i<=p;i++)A[i].reset();
        while(getline(cin,s)){
            if(s=="")break;
            stringstream ss(s);
            int a,b;
            ss>>a>>b;
            A[a].set(b);
        }
        unordered_set<bitset<100>>st;
        for(int i=1;i<=p;i++)st.insert(A[i]);
        printf("%d\n",(int)st.size());
        if(T!=0)printf("\n");
    }
}