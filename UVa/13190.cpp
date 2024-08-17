#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

typedef struct {
    string name;
    int freq;
} Med;

Med A[3000];
char name[16];
int main(){
    int T,n,k;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &n, &k);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            scanf("%s %d", name, &A[i].freq);
            A[i].name = name;
            pq.emplace(A[i].freq, i);
        }
        for(int i=0;i<k;i++){
            auto p = pq.top();
            pq.pop();
            printf("%d %s\n", p.first, A[p.second].name.c_str());
            p.first += A[p.second].freq;
            pq.push(p);
        }
    }
}