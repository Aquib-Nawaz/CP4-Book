#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    vector<int>values;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    int d,i=0,cnt=0,curt;
    pair<int,int>p;
    while(scanf("%d", &d), d!=0){
        values.push_back(d);
        i++;
        curt=2*d;
        while(scanf("%d", &d), d!=0) {
            values.push_back(d);
            i++;
            curt = curt<2*d ? curt : 2*d;
        }
        for(int k=0; k<values.size(); k++)
            if(curt<values[k]-5){
                cnt++;
                pq.emplace(values[k]-5,k);
            }
            else{
                pq.emplace(2*values[k], k);
            }
        while(curt<=18000){
            while((p=pq.top()).first<=curt){
                pq.pop();
                if(p.first%values[p.second]==0){
                    cnt++;
                    pq.emplace(values[p.second]+p.first-5, p.second);
                }
                else {
                    cnt--;
                    pq.emplace(values[p.second]+p.first+5, p.second);
                }
            }
            if(cnt==i)
                break;
            curt = pq.top().first;
        }
        if(curt>18000)
            printf("Signals fail to synchronise in 5 hours\n");
        else
            printf("%02d:%02d:%02d\n", curt/3600, (curt%3600)/60, curt%60);
        pq = priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>();
        i=0;
        cnt=0;
        values.clear();
    }
}