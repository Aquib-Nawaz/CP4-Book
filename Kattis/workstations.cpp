#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct interval{
    int time;
    bool arrival;
    bool operator <(const interval &p)const{
        if(time==p.time) return arrival>p.arrival;
        return time>p.time;
    }
};

int main(){
    int n,m,a,d,ans=0;
    scanf("%d%d",&n,&m);
    priority_queue<struct interval>pq;
    queue<int>q;
    for(int i=0;i<n;i++)scanf("%d%d",&a,&d), pq.push({a,true}), pq.push({a+d,false});
    while(!pq.empty()){
        interval p = pq.top();
        pq.pop();
        if(p.arrival){
            while(!q.empty()){
                int u = q.front();
                q.pop();
                if(u+m>=p.time){
                    ans++;
                    break;
                }
            }
        }else{
            q.push(p.time);
        }
    }
    printf("%d\n",ans);
}