#include <iostream>
#include <set>
using namespace std;
int A[102];
int main() {
    int d,n;
    scanf("%d %d", &d,&n);
    A[0]=0;
    A[n+1]=d;
    for(int i=1;i<=n;i++)scanf("%d", A+i);
    set<int> S;
    for(int i=0;i<=n+1;i++)for(int j=i+1;j<=n+1;j++)S.insert(A[j]-A[i]);
    for(auto it:S)printf("%d ", it);
}