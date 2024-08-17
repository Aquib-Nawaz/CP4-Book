#include <iostream>
using namespace std;
int arr[2000], dp1[2000], dp2[2000];
int main(){
    int n,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",arr+i);
    for(int i=n-1;i>=0;i--){
        int &v1 = dp1[i];
        int &v2 = dp2[i];
        v1=v2=1;
        for(int j=i+1; j<n;j++){
            if(arr[j]>arr[i])v1=max(v1,dp1[j]+1);
            else v2=max(v2,dp2[j]+1);
        }
        ans = max(ans,v1+v2-1);
    }
    printf("%d",ans);
}