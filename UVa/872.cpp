#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int>adjL[26];
char line[200], var[20];
int indeg[20], mp[26],N, cur[20];
bool f;
void addEdge(char u, char v){
    adjL[mp[u-'A']].push_back(mp[v-'A']);
    indeg[mp[v-'A']]++;
}

void solve(int l){
    if(l==N){
        f=false;
        for(int i=0;i<N-1;i++)printf("%c ", var[cur[i]]);
        printf("%c\n", var[cur[N-1]]);
        return;
    }
    for(int i=0;i<N;i++){
        if(indeg[i]==0){
            indeg[i]--;
            for(auto k:adjL[i])indeg[k]--;
            cur[l]=i;
            solve(l+1);
            for(auto k:adjL[i])indeg[k]++;
            indeg[i]++;
        }
    }
}

int main(){
    int T,ret;
    scanf("%d%*c",&T);
    char c;
    while(T--){
        scanf("%*c");
        N=0;
        do{
            ret=scanf("%c%c",var+N, &c);
            adjL[N].clear(), indeg[N]=0;
            mp[var[N]-'A']=N;
            N++;
        }
        while(ret==2 && c!='\n');
        scanf("%[^\n]%*c", line);
        for(int i=0;i<strlen(line);i+=4)addEdge(line[i],line[i+2]);
        f=true;
        solve(0);
        if(f)printf("NO\n");
        if(T)printf("\n");
    }
}