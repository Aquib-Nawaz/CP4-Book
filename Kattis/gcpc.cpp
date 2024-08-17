#include <iostream>
#include <utility>
#include <map>
#include <cstring>
using namespace std;

pair<int,int> A[100001], B[100001];
int fen[100002];

void update(int i, int v, int n){
    while(i<=n){
        fen[i]+=v;
        i+=i&-i;
    }
}

int query(int i){
    int ans=0;
    while(i>0){
        ans+=fen[i];
        i-=i&-i;
    }
    return ans;
}

int main(){
    map<pair<int,int>, int>mp;
    int n,m,a,b;
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++)A[i]={0,0};
    mp.insert({{0,0},0});

    for(int i=0;i<m;i++){
        scanf("%d %d", &a,&b);
        A[a].first--;
        A[a].second+=b;
        B[i] = {a,b};
        mp.insert({A[a],0});
    }
    int v=1;
    for(auto it = mp.begin();it!=mp.end();it++){
        it->second = v++;
    }
    memset(fen, 0,sizeof fen);
    for(int i=1;i<=n;i++){A[i]={0,0};
        update(mp[A[i]],1,mp.size()+2);}

    for(int i=0; i<m; i++){
        update(mp[A[B[i].first]],-1,mp.size()+2);
        A[B[i].first].first--;
        A[B[i].first].second+=B[i].second;
        update(mp[A[B[i].first]],1,mp.size()+2);
        printf("%d\n", query(mp[A[1]]-1)+1);
    }

}