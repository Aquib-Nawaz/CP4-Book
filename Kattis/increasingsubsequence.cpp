#include <iostream>
#include <algorithm>
using namespace std;

int arr[200], l[200], p[200],li[200];

void print(int i){
    if (i==-1) return;
    print(p[i]);
    printf(" %d", arr[i]);
}

int main(){
    int n, k,pos;
    while(scanf("%d",&n), n){
        for(int i=0;i<n;i++)scanf("%d", arr+i);
        k=0;
        for(int i=0;i<n;i++){
            pos = lower_bound(l,l+k,arr[i])-l;
            if(pos==k) l[k++]=arr[i];
            else l[pos]=arr[i];
            p[i]=pos?li[pos-1]:-1;
            li[pos]=i;
        }

        printf("%d",k);
        print(li[k-1]);
        printf("\n");
    }
}