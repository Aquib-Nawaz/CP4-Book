#include <iostream>
using namespace std;
int A[10];

bool checkequal(int n) {
    int x = A[0];
    for(int i=1;i<n;i++) if(A[i]!=x) return false;
    return true;
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d", &A[i]);
    int d;
    for(d=0;d<n && !checkequal(n-d);d++){
        for(int i=0;i<n-d-1;i++)
            A[i]=A[i+1]-A[i];
    }
    int ans=0;
    printf("%d ", d);
    while(d>=0)ans+=A[n-1-d], d--;
    printf("%d\n", ans);
}