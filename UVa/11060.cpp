#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

vector<int>adjL[100];
char line[101], line1[101];
string names[100];
unordered_map<string, int>mp;
int indeg[100], N,M ;
bool f;

int main(){
    int C=0;
    while(scanf("%d", &N)!=-1){
        mp.clear();
        for(int i=0;i<N;i++){
            scanf("%s", line);
            names[i]=line;
            mp[names[i]]=i;
            adjL[i].clear();
            indeg[i]=0;
        }
        scanf("%d", &M);
        for(int i=0;i<M;i++){
            scanf("%s %s", line, line1);
            adjL[mp[line]].push_back(mp[line1]);
            indeg[mp[line1]]++;
        }

        printf("Case #%d: Dilbert should drink beverages in this order:",++C);
        for(int _=0;_<N;_++){
            for(int i=0;i<N;i++){
                if(indeg[i]!=0)continue;
                printf(" %s", names[i].c_str());
                indeg[i]--;
                for(auto v:adjL[i])
                    indeg[v]--;
                break;
            }
        }
        printf(".\n\n");
    }
}