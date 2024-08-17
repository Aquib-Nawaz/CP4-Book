#include <iostream>
#include <cstring>
#include <list>
using namespace std;

char C[1000001];
int main(){
    int n,T;
    scanf("%d", &T);
    while(T--){
        scanf(" %[^\n]", C);
        n= strlen(C);
        list<char> L;
        auto it=L.end();
        for(int i=0;i<n;i++){
            if(C[i]=='[')
                it=L.begin();
            else if(C[i]==']')
                it=L.end();
            else if(C[i]=='<'){
                if(L.empty()||it==L.begin()) continue;
                it--;
                it=L.erase(it);
            }
            else
                L.insert(it, C[i]);
        }
        for(auto c:L)
            printf("%c", c);
        if(T!=0)
            printf("\n");
    }
}