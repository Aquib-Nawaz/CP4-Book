#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

struct interval{
    int l,r;
    bool operator < (const interval& rhs) const{
        return r<rhs.r;
    }
}arr[200000];

int main(){
    int n,k,l,r;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d %d",&l,&r);
        arr[i]={l,r};
    }
    sort(arr,arr+n);
    multiset<int>q;
    int ans=0;
    multiset<int>::iterator it;

    for(int i=0;i<n;i++){
        int u=arr[i].l;
        if(q.size()<k||*q.begin()<u){q.insert(arr[i].r); ans++;}
        if(!q.empty() && *q.begin()<u){
            it = q.lower_bound(u);
            it--;
            q.erase(it);
        }
    }
    printf("%d",ans);
}