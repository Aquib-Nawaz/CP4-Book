#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct mypair{
    int a,b;
    bool operator<(const mypair &p)const{
        return (a*1.0/b<p.a*1.0/p.b);
    }
};

int main() {
    int p, n, d;
    mypair temp;
    while (scanf("%d %d", &p, &n) != EOF) {
        priority_queue<struct mypair> pq;
        p -= n;
        for (int i = 0; i < n; i++)scanf("%d", &d), pq.push({d,1});
        if(n==0){
            printf("%d\n",0);
            continue;
        }
        while (p>0){
            //p.a/p.b < p1.a<p1.b => p.b = p.a*p1.b/p1.a+1-p.b
            temp = pq.top();
            pq.pop();
            p--;
            temp.b++;
            pq.push(temp);
        }
        printf("%d\n", (int)ceil(pq.top().a*1.0/pq.top().b));
    }
}