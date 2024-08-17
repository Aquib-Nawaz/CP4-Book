#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N,d,T;
    long long a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(int i=0;i<N;i++)scanf("%d",&d),pq.push(d);
        long long ans=0;
        for(int i=0;i<N-1;i++){
            a=pq.top();
            pq.pop();
            b=pq.top();
            pq.pop();
            ans+=a+b;
            pq.push(a+b);
        }
        printf("%lld\n",ans);
    }

}