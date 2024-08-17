#include <iostream>
#include <bitset>
using namespace std;
bitset<13>A;
int C[13];
int main(){
    int T,d;
    scanf("%d", &T);
    while(T--){
        A.set();
        scanf("%d", &d);
        int cur=0;
        for(int i=1;i<=d;i++){
            for(int j=0;j<i+(i!=1);j+=A.test(cur))cur=(cur+1)%d;
            C[cur]=i;
            A.reset(cur);
        }
        for(int i=0;i<d-1;i++)printf("%d ", C[i]);
        printf("%d\n", C[d-1]);
    }
}