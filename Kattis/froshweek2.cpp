#include <iostream>
#include <algorithm>
using namespace std;

int A[200000],B[200000];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",A+i);
    for(int i=0;i<m;i++)scanf("%d",B+i);
    int i=0,j=0;
    sort(A,A+n);
    sort(B,B+m);
    int ans=0;
    while(i<n&&j<m){
        while(j<m&&A[i]>B[j])j++;
        if(j==m)break;
        i++;
        j++;
        ans++;
    }
    printf("%d",ans);

}