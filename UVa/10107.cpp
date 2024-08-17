#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int main(){
    priority_queue<int>pq1;
    priority_queue<int, vector<int>, greater<int>>pq2;
    int d;
    while(scanf("%d", &d)!=EOF){
        if(pq1.size()==pq2.size()){
            if(!pq1.empty()&&d>pq2.top()){
                pq2.push(d);
                d=pq2.top();
                pq2.pop();
            }
            pq1.push(d);
            printf("%d\n", pq1.top());
        }
        else{
            if(d<pq1.top()){
                pq1.push(d);
                d=pq1.top();
                pq1.pop();
            }
            pq2.push(d);
            printf("%d\n", pq1.top()/2+pq2.top()/2+(pq1.top()%2==1 &&1==pq2.top()%2));
        }
    }
}