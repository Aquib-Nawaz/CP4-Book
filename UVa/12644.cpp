#include <iostream>
#include <vector>
using namespace std;

int mt[500], Jack[500][26];
bool used[500], used1[500];

vector<int>adj[500];
char word[31];

bool try_kuhn(int u){
    if(used[u])return false;
    used[u]=true;
    for(int v: adj[u]){
        if(mt[v]==-1||try_kuhn(mt[v])){
            mt[v]=u;
            return true;
        }
    }
    return false;
}


int main(){
    int V,C;
    while (scanf("%d%d", &V,&C)==2){
        for(int i=0;i<V;i++){
            scanf("%s", word);
            for(int j=0;j<26;j++)Jack[i][j]=0;
            for(char *c=word;*c;c++){
                Jack[i][*c-'a']++;
            }
            used1[i]= false;
            adj[i].clear();
        }
        for(int i=0;i<C;i++){
            mt[i]=-1;
            scanf("%s", word);
            int freq[26]={0};
            for(char *c=word;*c;c++){
                freq[*c-'a']++;
            }
            for(int j=0;j<V;j++){
                int k;
                for(k=0;k<26&&Jack[j][k]>=freq[k];k++);
                if(k==26) {
                    adj[j].push_back(i);
                    if(mt[i]==-1&&!used1[j]){
                        mt[i]=j;
                        used1[j]=true;
                    }
                }
            }
        }
        for(int i=0;i<V;i++){
            if(!used1[i]){
                for(int j=0;j<V;j++)used[j]=false;
                try_kuhn(i);
            }
        }
        int ans=0;
        for(int i=0;i<C;i++){
            if(mt[i]!=-1)ans++;
        }
        printf("%d\n", ans);
    }
}