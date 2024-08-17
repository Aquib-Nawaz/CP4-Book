#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct doll{
    int w,h;
    bool const operator < ( const doll & rhs) const {
        return w < rhs.w;
    }
}arr[100000];

int temp[100000];

int main(){
    int T,n,tempsz;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d%d",&arr[i].w,&arr[i].h);
        sort(arr,arr+n);
        tempsz=0;
        multiset<int>pq;
        for(int i=0;i<n;i++){
            if(!pq.empty() && *pq.begin()<arr[i].h){
                auto it = pq.lower_bound(arr[i].h);
                pq.erase(--it);
            }
            temp[tempsz++] = arr[i].h;
            if(i<n-1 && arr[i+1].w==arr[i].w)continue;
            for(int j=0;j<tempsz;j++)pq.insert(temp[j]);
            tempsz=0;
        }
        printf("%lu\n",pq.size());
    }
}