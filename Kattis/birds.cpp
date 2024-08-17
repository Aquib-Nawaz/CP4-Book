#include <iostream>
#include <algorithm>
using namespace std;

int A[20000];
int main(){
    int l,d,n;
    scanf("%d%d%d",&l,&d,&n);
    for(int i=0;i<n;i++)scanf("%d",A+i);
    sort(A,A+n);

    if(n==0){
        printf("%d\n",(l-12)/d+1);
        return 0;
    }
    int ans=(A[0]-6)/d+(l-6-A[n-1])/d;
    for(int i=0;i<n-1;i++){
        ans+=(A[i+1]-A[i])/d-1;
    }
    printf("%d\n",ans);
}