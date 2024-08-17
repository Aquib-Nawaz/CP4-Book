#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct MP{
    int c,t;
    bool operator<(const MP& rhs) const {
        return t<rhs.t;
    }
}arr[10000];

int main() {
    int n,t;
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++){
        scanf("%d%d",&arr[i].c,&arr[i].t);
    }
    sort(arr,arr+n);
    int ans=0;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0,c=0;i<n;i++){
        if(c<=arr[i].t)c++,ans+=arr[i].c,pq.push(arr[i].c);
        else if(pq.top()<arr[i].c){
            ans+=arr[i].c-pq.top();
            pq.pop();
            pq.push(arr[i].c);
        }
    }
    printf("%d",ans);
    return 0;
}