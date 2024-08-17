#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct P{
    int x,y;
    bool operator < (const P& rhs) const{
        return x<rhs.x;
    }
}arr[ 100000];

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)scanf("%d %d",&arr[i].x,&arr[i].y);
    sort(arr,arr+n);
    multiset<int>pq;
    int ans=0;
    for(int i=0;i<n;i++){
        while(!pq.empty()&&*pq.begin()<=arr[i].x)pq.erase(pq.begin());
        if(pq.size()<k)pq.insert(arr[i].y),ans++;
        else if(*pq.rbegin()>arr[i].y)pq.erase(prev(pq.end())),pq.insert(arr[i].y);
    }
    printf("%d\n",ans);
}