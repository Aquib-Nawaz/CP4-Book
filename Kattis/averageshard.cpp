#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
int A[200000];
int main(){
    int T,d;
    scanf("%d", &T);
    while(T--){
        int n,m;
        scanf("%d%d", &n,&m);
        ll sumcs=0, sumec=0;
        for(int i=0;i<n;i++)scanf("%d", &A[i]), sumcs+=A[i];
        for(int i=0;i<m;i++)scanf("%d", &d),sumec+=d;
        double avgcs = sumcs*1.0/n, avgec = sumec*1.0/m;
        int ans=0;
        for(int i=0;i<n;i++)if(A[i]<avgcs-1e-10 && A[i]>avgec+1e-10)ans++;
        printf("%d\n", ans);
    }
}