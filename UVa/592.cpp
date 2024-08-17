#include <iostream>
#include <cstring>
#include <string>
using namespace std;

typedef struct {
    int s,n,v,t;
} statement;
statement stts[50];
int V[6], cur[6], n;

bool truth(int i){
    bool spt = false,stt;
    if(cur[stts[i].s]==0||cur[stts[i].s]==1&&cur[5]==0)spt=true;
    if(stts[i].v!=3)stt = (cur[stts[i].n]==stts[i].v)^stts[i].t;
    else stt = (!(cur[stts[i].n]==0||cur[stts[i].n]==1&&cur[5]==0))^stts[i].t;
    return spt==stt;
}

void solve(int i){
    if(i<=5){
        for(int j=0;j<3-(i==5);j++){
            cur[i]=j;
            solve(i+1);
        }
        return;
    }
    for(i=0;i<n;i++){
        if(!truth(i))return;
    }
    for(i=0;i<6;i++)if(V[i]==-1)V[i]=cur[i];else if(V[i]!=cur[i])V[i]=-2;
}

string P[3] = {"divine", "human", "evil"}, D[2]= {"day","night"};

int main(){
    int i,C=0;
    char c,s,o;
    while (scanf("%d", &n), n){
        i=-1;
        memset(V, -1, sizeof V);
        while(i++<n-1){
            scanf(" %c: %c %*s %c%*s", &s, &o, &c);
            stts[i].s=s-'A';
            if(o=='I'&&c=='i'){
                scanf(" %c%*s", &c);
                stts[i].v=c!='d';
                stts[i].t=0;
                stts[i].n=5;
                continue;
            }
            stts[i].n=o!='I'?o-'A':s-'A';
            stts[i].t=c=='n';
            if(c=='n'){
                scanf(" %c%*s",&c);
            }
            int t;
            if(c=='d')t=0;
            else if(c=='h')t=1;
            else if(c=='e')t=2;
            else t=3;
            stts[i].v=t;
        }
        solve(0);
        printf("Conversation #%d\n", ++C);
        if(V[0]==-1)printf("This is impossible.\n");
        else{
           bool f=0;
           for(i=0;i<5;i++){
               if(V[i]!=-2){
                   f=1;
                   printf("%c is %s.\n",i+'A', P[V[i]].c_str());
               }
           }
           if(V[5]!=-2){
               f=1;
               printf("It is %s.\n", D[V[5]].c_str());
           }
           if(!f)printf("No facts are deducible.\n");
        }
        printf("\n");
    }
}