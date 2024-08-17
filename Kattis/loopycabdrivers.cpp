#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

vector<int>adjL[2][20000];
int x, order[20000],c,curCC;
bool vis[20000];
string name[20000];
unordered_map<string , int >mp;
vector<int>scc[20000];
void dfs(int u){
    vis[u]=true;
    if(x==1)
        scc[curCC].push_back(u);
    for(auto v:adjL[x][u]){
        if(!vis[v])dfs(v);
    }
    if(x==0)order[--c]=u;
}

bool cmp(vector<int>& a, vector<int>& b){
    return name[a[0]]<name[b[0]];
}
char line[21];
int main(){
    int N=0,M,u,v;
    scanf("%d", &M);
    for(int i=0;i<M;i++){
        scanf("%s",line);
        if(mp.find(line)==mp.end()){
            name[N++]=line;
            mp[line]=N-1;
        }
        u=mp[line];
        scanf("%s",line);
        if(mp.find(line)==mp.end()){
            name[N++]=line;
            mp[line]=N-1;
        }
        v=mp[line];
        adjL[0][u].push_back(v);
        adjL[1][v].push_back(u);
    }
    for(int i=0;i<N;i++)vis[i]= false;
    x=0, c=N;
    for(int i=0;i<N;i++)if(!vis[i]) dfs(i);
    for(int i=0;i<N;i++)vis[i] = false;
    x=1,curCC=0;
    for(int i=0;i<N;i++)if(!vis[order[i]]) dfs(order[i]), sort(scc[curCC].begin(), scc[curCC].end(),
                                                               [](int a, int b){return name[a]<name[b];}
    ), curCC++;
    sort(scc, scc+curCC, [](vector<int>&a, vector<int>&b){return name[a[0]]<name[b[0]];});


    for(int i=0;i<curCC;i++){
        if(scc[i].size()==1)continue;
        cout << "okay ";
        for(int j : scc[i])cout<<" "<<name[j];
        cout<<endl;
    }
    bool f=true;
    for(int i=0;i<curCC;i++){
        if(scc[i].size()!=1)continue;
        if(f)printf("avoid");
        f=false;
        printf(" %s", name[scc[i][0]].c_str());
    }
    if(!f)printf("\n");
}
