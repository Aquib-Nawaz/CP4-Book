#include <iostream>
using namespace std;
int arr[1000000];
int main(){
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",arr+i);
        }
        int mn=1e9,v=n+1;
        for(int i=n-1;i>=0;i--){
            if(arr[i]>mn)v=min(arr[i],v);
            mn=min(mn,arr[i]);
        }
        printf("%d\n",n-v+1);
    }
}