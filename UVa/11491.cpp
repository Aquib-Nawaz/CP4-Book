#include <iostream>
#include <queue>
using namespace std;

struct MP{
    int x,y;
    bool operator<(const MP &a)const{
        return x==a.x?y>a.y:x<a.x;
    }
};

char S[100001];
int main() {
    int n,d,cur,x;
    while(scanf("%d%d",&n,&d),n){
        scanf("%s",S);
        priority_queue<MP>pq;
        for(cur=0,x=-1,n=n-d;n>0;n--){
            for(int i=x+1;i<=cur+d;i++)pq.push({S[i],i});
            while(pq.top().y<cur)pq.pop();
            x=max(cur+d,x);
            printf("%c",pq.top().x);
            d-=pq.top().y-cur;
            cur=pq.top().y+1;
            pq.pop();
        }
        printf("\n");
    }
    return 0;
}