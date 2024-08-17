#include <iostream>
#include <unordered_set>
using namespace std;

int arr[41];
unordered_set<int>st[41],st1, st2;
int main(){
    int n,k,S,d,x;
    bool ne,p;

    while(scanf("%d%d",&n,&k),n||k){
        //s - 2*x = k
        S=0;
        for(int i=0;i<n;i++)scanf("%d",&d),S+=d,arr[i]=d;
        if(S<k || (S-k)&1){
            printf("*\n");
            continue;
        }
        st[n]={0};
        for(int i=n-1;i>=0;i--) {
            st[i] = st[i+1];
            for (auto it: st[i+1])
                st[i].insert(it + arr[i]);
        }
        x = (S-k)>>1;
        if(st[0].count(x)==0){
            printf("*\n");
            continue;
        }
        st1={0};
        for(int i=0;i<n;i++){
            ne=p = false;
            for(auto it:st1){
                ne|=st[i+1].count(x-arr[i]-it)>0;
                p|=st[i+1].count(S-x-arr[i]-it)>0;
                if(ne&&p)break;
            }
            if(ne&&p)printf("?");
            else if(ne)printf("-");
            else printf("+");
            st2=st1;
            for(auto it:st2){
                st1.insert(it+arr[i]);
            }
        }
        printf("\n");
    }
}