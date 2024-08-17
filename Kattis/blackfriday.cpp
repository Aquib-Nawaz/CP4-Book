#include <iostream>
#include <cstring>
using namespace std;
int A[7];
int main(){
    int n,d;
    scanf("%d", &n);
    memset(A,-1,sizeof A);
    for(int i=1;i<=n;i++){scanf("%d", &d); if(A[d]==-1)A[d]=i; else A[d]=-2;}
    for(int i=6;i>0;i--){if(A[i]>0){printf("%d\n", A[i]); return 0;}}
    printf("none\n");
}