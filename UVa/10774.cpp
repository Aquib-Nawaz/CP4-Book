#include <iostream>
#include <utility>
using namespace std;
#define M 30001
pair<int,int> P[M];

int main(){
    int n,C=0,T;
    for(int i=1;i<M;i++){
        int j = i+1;
        if((j&-j)==j)P[i]={0,i};
        else {
            j = 1<<(31-__builtin_clz(i))^i;
            j = (j<<1)|1;
            P[i]= P[j];
            P[i].first++;
        }
    }
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("Case %d: %d %d\n",++C,P[n].first,P[n].second);
    }
}