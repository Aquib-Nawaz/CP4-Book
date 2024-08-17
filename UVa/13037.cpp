#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
int A[3][2],S[3];
int main(){
    int T,C=0,d;
    scanf("%d", &T);
    while(C++<T){
        unordered_map<int ,int>mp;
        memset(A,0,sizeof A);
        REP(i,3)scanf("%d", S+i);
        REP(j,3)REP(i,S[j]){scanf("%d", &d); mp[d]|=(1<<j);}

        printf("Case #%d:\n", C);

        for(auto it:mp){
            if(it.second==7){
                continue;
            }
            int x = it.second,id=0;
            if(x!=(x&-x))
                x=7-x,id=1;
            A[__builtin_ctz(x)][id]++;
        }

        for(int *B:A)printf("%d %d\n", B[0],B[1]);
    }
}