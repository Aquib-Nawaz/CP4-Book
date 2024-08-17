#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N,d,a,b;
    while(scanf("%d",&N),N){
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<N;i++)scanf("%d",&d),pq.push(d);
        int ans=0;
        while(pq.size()>1){
            a=pq.top();
            pq.pop();
            b=pq.top();
            pq.pop();
            ans+=a+b;
            pq.push(a+b);
        }
        printf("%d\n",ans);
    }

}