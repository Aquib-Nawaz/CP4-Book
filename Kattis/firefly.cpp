#include <iostream>
#include <algorithm>
using namespace std;

int N,H;
int A[100000],B[100000];
int main(){
    int d;
    scanf("%d %d",&N,&H);
    for(int i=0;i<N/2;i++){
        scanf("%d %d",A+i,&d);
        B[i]=H-d;
    }
    sort(A,A+N/2);
    sort(B,B+N/2);
    int ans=N+1,cnt,cur;
    for(int i=1,l=0,m=0;i<=H;i++){
        while(l<N/2&&A[l]==i-1)l++;
        while(m<N/2&&B[m]==i-1)m++;
        cur = m+(N/2-l);
        if(cur<ans)ans=cur,cnt=1;
        else if(cur==ans)cnt++;
    }
    printf("%d %d",ans,cnt);
}