#include <iostream>
#include <cstring>
#define MAX_BOLTS 500
#define MAX_NUTS  500
/* global copy of the input data */
int nuts,bolts;
int fits[MAX_BOLTS][MAX_NUTS];
int nut_used[MAX_NUTS], mt[MAX_NUTS];
bool used1[MAX_BOLTS], used[MAX_BOLTS];
using namespace std;

void read_input_data(void){
    int n,b;
    scanf("%d%d",&bolts,&nuts);
    for(int i=0;i<nuts;i++)mt[i]=-1;
    for(b=0;b<bolts;b++){
        bool matched=false;
        for(n=0;n<nuts;n++){
            scanf("%d",&fits[b][n]);
            if(!matched && fits[b][n] && mt[n]==-1) matched=true, mt[n]=b;
        }
        used1[b]=matched;
    }
}

bool try_kuhn(int v){
    if(used[v])return false;
    used[v]=true;
    for(int u=0;u<nuts;u++){
        if(fits[v][u] && (mt[u]==-1||try_kuhn(mt[u]))){
            mt[u]=v;
            return true;
        }
    }
    return false;
}

int main(){
    int cases,caseno;
    scanf("%d",&cases);
    for(caseno=1;caseno<=cases;caseno++){
        read_input_data();
        for(int i=0;i<bolts;i++){
            if(used1[i])continue;
            memset(used, 0, sizeof used);
            try_kuhn(i);
        }
        int ans=0;
        for(int i=0;i<nuts;i++)if(mt[i]!=-1)ans++;
        printf("Case %d: ",caseno);
        printf("a maximum of %d nuts and bolts ",ans);
        printf("can be fitted together\n");
    }
    return 0;
}