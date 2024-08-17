#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int>adjL[26];
char line[2][21];
int indeg[26];

void addEdge(int x){
    char c1,c2;
    for(int i=0;line[1-x][i];i++){
        c1=line[x][i],c2=line[1-x][i];
        if(c1==c2)continue;
        adjL[c2-'A'].push_back(c1-'A');
        if(indeg[c1-'A']==-1)indeg[c1-'A']=0;
        if(indeg[c2-'A']==-1)indeg[c2-'A']=0;
        indeg[c1-'A']++;
        break;
    }
}

int main(){
    while(true){
        memset(indeg, -1, sizeof indeg);
        for(auto & i : adjL)i.clear();
        if(scanf("%s",line[0])!=1)break;
        int x=1;
        while(scanf("%s", line[x]),line[x][0]!='#'){
            addEdge(x);
            x^=1;
        }
        bool chng = true;
        while(chng){
            chng=false;
            for(int i=0;i<26;i++){
                if(indeg[i]==0){
                    for(int j:adjL[i]){
                        indeg[j]--;
                    }
                    indeg[i]=-1;
                    printf("%c", 'A'+i);
                    chng=true;
                    break;
                }
            }
        }
        printf("\n");
    }
}