#include <iostream>
using namespace std;
int P[26],S[26];

int Find(int x){
    if(P[x]==x) return x;
    return P[x]=Find(P[x]);
}

void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    if(a==b) return;
    P[b]=a;
    S[a]+=S[b];
}

int main(){
    int T,t,a;
    char u,v;
    scanf("%d", &T);
    while(T--){
        for(int i=0;i<26;i++)P[i]=i,S[i]=1;
        while(scanf(" (%c,%c)",&u,&v)==2){
            Union(u-'A', v-'A');
        }
        t=a=0;
        scanf("%*s");
        int ret;
        do{
            ret=scanf(" %c%c",&u,&v);
            if(P[u-'A']!=u-'A')continue;
            if(S[u-'A']==1)a++;
            else t++;
        }while(ret==2&&v!='\n');
        printf("There are %d tree(s) and %d acorn(s).\n", t,a);
    }
}