#include <iostream>
#include <algorithm>
using namespace std;

struct interval{
    int l,r;
    bool operator <(const interval& _r) const{
        return l==_r.l?r>_r.r:l<_r.l;
    }
}arr[100000];

int coo[100000];

int main(){
    int T, M,l,r,N,sz,cur;
    scanf("%d",&T);
    while (T--){
        scanf("%d",&M);
        N=sz=cur=0;
        while(scanf("%d%d",&l,&r),l||r){
            if(r<0)continue;
            arr[N].l=l;
            arr[N++].r=r;
        }
        sort(arr,arr+N);

//        bool can=true;
        for(int i=0,m;i<N && arr[i].l<=cur && cur<M;){
            m=0;
            while(i<N&&arr[i].l<=cur){
                if(m<arr[i].r){
                    m = arr[i].r;
                    coo[sz]=i;
                }
                i++;
            }
            cur=m;
            sz++;
        }
        if(cur<M)printf("0\n");
        else {
            printf("%d\n",sz);
            for(int i=0;i<sz;i++)printf("%d %d\n",arr[coo[i]].l,arr[coo[i]].r);
        }
        if(T)
        printf("\n");
    }
}