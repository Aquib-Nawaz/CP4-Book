#include <iostream>
#include <algorithm>
using namespace std;

struct interval{
    int a,b;
    bool operator <(const interval &p)const{
        return b>p.b;
//        return a<p.a;
    }
}arr[10000];

int main(){
    int N,C=0;
    while (scanf("%d",&N),N){
        for(int i=0;i<N;i++)scanf("%d %d",&arr[i].a,&arr[i].b);
        sort(arr,arr+N);
        int ans=0;
        for(int i=0,br=0;i<N;i++){
            br+=arr[i].a;
            ans=max(ans,br+arr[i].b);
        }
        printf("Case %d: %d\n",++C,ans);
    }
}