#include <iostream>
using namespace std;
int arr[100000];
bool arr1[100000];

int main(){
    int T,n,m,l,r,ans,val;
    scanf("%d",&T);
    while(T--){
        ans=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)scanf("%d",arr+i), arr1[i]=arr[i]==m;
        for(int i=0;i<n;i++){
            if(!arr1[i])continue;
            val=m;
            l=i-1,r=i+1;

            while(l>=0 && arr[l]>m)val+=arr[l--];
            while(r<n && arr[r]>m)val+=arr[r++];

            ans = max(ans,val);
        }
        printf("%d\n",ans);
    }
}