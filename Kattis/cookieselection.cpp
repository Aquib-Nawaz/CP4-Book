#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define REP(i,n) for (int i=0;i<n;i++)

int main(){
    int T;
    int d,ret;
    priority_queue<int> s1;
    priority_queue<int,vector<int>, greater<int>>s2;
    while((ret=scanf("%d", &d))!=-1){
        if(ret==0){
            scanf(" %*c");
            if(s1.size()==s2.size()){
                d=s2.top();
                s2.pop();
            }
            else {
                d=s1.top();
                s1.pop();
            }
            printf("%d\n", d);
            continue;
        }
        if(s1.size()==s2.size()){
            if(!s2.empty()&&s2.top()<d){
                int t = s2.top();
                s2.pop();
                s2.push(d);
                d=t;
            }
            s1.push(d);
        }
        else {
            if(!s1.empty()&&s1.top()>d){
                int t = s1.top();
                s1.pop();
                s1.push(d);
                d=t;
            }
            s2.push(d);
        }
    }
}