#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct interval{
    int q, d;
    bool operator<(const struct interval& rhs) const{
        return d < rhs.d;
    }
} arr[800000];

int main(){
    int T,n;
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d %d",&arr[i].q, &arr[i].d);
        sort(arr, arr+n);
        int cur=0;
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            if(arr[i].q>arr[i].d)continue;
            if(cur+arr[i].q<=arr[i].d)cur+=arr[i].q, pq.push(arr[i].q);
            else if(pq.top()>arr[i].q){
                cur+=arr[i].q-pq.top();
                pq.pop();
                pq.push(arr[i].q);
            }
        }
        printf("%lu\n",pq.size());
        if(T>0)printf("\n");
    }
}