#include <iostream>
#include <cstring>
#include <list>
using namespace std;

char C[100001];
int main(){
    int n;
    while(scanf("%s", C) != EOF){
        n= strlen(C);
        list<char> L;
        auto it=L.end();
        for(int i=0;i<n;i++){
            if(C[i]=='[')
                it=L.begin();
            else if(C[i]==']')
                it=L.end();
            else
                L.insert(it, C[i]);
        }
        for(auto c:L)
            printf("%c", c);
        printf("\n");
    }
}