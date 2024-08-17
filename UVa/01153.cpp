#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct P{
    int q,d;
    bool operator < (const P& rhs) const{
        return d<rhs.d;
    }
}arr[ 800000];

int main(){
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d %d",&arr[i].q,&arr[i].d);
        sort(arr,arr+n);
        priority_queue<int>pq;
        for(int i=0,cur=0;i<n;i++){
            if(arr[i].q>arr[i].d)continue;
            if(cur+arr[i].q<=arr[i].d)pq.push(arr[i].q),cur+=arr[i].q;
            else if(arr[i].q<pq.top()){
                cur+=arr[i].q-pq.top();
                pq.pop();
                pq.push(arr[i].q);
            }
        }
        printf("%lu\n",pq.size());
        if(T!=0)printf("\n");
    }
}