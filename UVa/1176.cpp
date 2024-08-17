#include <iostream>
using namespace std;
#define M 32768
int P[M];

int main(){
    int n;
    P[0]=0;
    for(int i=1;i<M;i++){
        int j = i+1;
        if((j&-j)==j)P[i]=i;
        else {
            j = 1<<(31-__builtin_clz(i))^i;
            j = (j<<1)|1;
            P[i]= P[j];
        }
    }
    while(scanf("%d",&n)!=-1){
        printf("%d\n",P[n]+n);
    }
}