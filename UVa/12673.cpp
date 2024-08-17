#include <iostream>
#include <algorithm>
using namespace std;

int A[100001];

int main(){
    while (true){
        int n,g,a,b,w=0;
        if(scanf("%d %d",&n, &g)==-1)break;
        for(int i=0;i<n;i++){scanf("%d%d",&a,&b), A[i]=a-b;}
        sort(A,A+n);
        for(int i=n-1;i>=0&&A[i]+g>=0;i--){
            if(A[i]>0)w+=3;
            else if(A[i]+g==0)g=0,w+=1;
            else g+=A[i]-1,w+=3;
        }

        printf("%d\n",w);
    }
}