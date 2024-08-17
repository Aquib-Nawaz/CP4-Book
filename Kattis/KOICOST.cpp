#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define PRIME 1000000000
#define MAX 1000001

int parent[MAX];
int sizearr[MAX];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    parent[b] = a;
    sizearr[a] += sizearr[b];
}

struct Edge {
    int u, v, weight;

};

struct edgeComparator{
    bool operator()(Edge e1, Edge e2){
        return e1.weight > e2.weight;
    }
};

struct Edge edges[MAX];
int suffix[MAX];

int main(){
    int n,m;
    scanf("%d %d", &n,&m);
    for(int i=1;i<=n; i++){
        parent[i] = i;
        sizearr[i]=1;
    }
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d %d %d", &u,&v,&w);
        edges[i] = Edge({u,v,w});
    }
    sort(edges, edges+m, edgeComparator());
    suffix[m-1] = edges[m-1].weight;
    for(int i=m-2;i>=0;i--)
        suffix[i] = (suffix[i+1]+edges[i].weight)%PRIME;
    int p1, p2;
    int ans=0;
    for (int i=0;i<m;i++) {
        Edge e = edges[i];
        p1=find_set(e.u);p2=find_set(e.v);
        if ( p1!=p2) {
            ans = (int)(ans + ((ll)sizearr[p1] * sizearr[p2] % PRIME) * suffix[i] % PRIME) % PRIME;
            union_sets(p1, p2);
        }
    }
    printf("%d\n", ans);
    return 0;
}