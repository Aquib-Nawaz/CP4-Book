#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
int main(){
    int T,N,W;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&N,&W);
        for(int i=0;i<N;i++){
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+N);
        int i,w;
        for(i=w=0;i<N&& w+ arr[i]<=W;w+=arr[i++]);
        printf("%d\n",i);
    }
}
