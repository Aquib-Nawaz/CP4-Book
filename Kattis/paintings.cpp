#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

string A[13];
int T,N,M;
int B[12],ans[12],cnt;
char W[21],W1[21];
bool f=false;
map<string,int>mp;
map<int,int>edge;

void solve(int mask, int l){
    if(mask==0){
        if(!f)
            for(int i=0;i<N;i++)ans[i]=B[i];
        f=true;
        cnt++;
        return;
    }

    for(int i=0;i<N;i++){
        if(mask&1<<i && (l==0||(edge[B[l-1]]&1<<i)==0)){
            B[l]=i;
            solve(mask^1<<i,l+1);
        }
    }
}

int main(){

    scanf("%d",&T);
    while(T--){
        scanf("%d ",&N);
        mp.clear();
        edge.clear();
        for(int i=0;i<N;i++)scanf("%s",W),A[i]=W,B[i]=i,mp[W]=i;
        scanf("%d",&M);
        for(int i=0;i<M;i++)scanf("%s %s",W,W1),edge[mp[W]]|=1<<mp[W1],edge[mp[W1]]|=1<<mp[W];
        f=false;
        cnt=0;
        solve((1<<N)-1,0);
        printf("%d\n",cnt);
        for(int i=0;i<N;i++){
            if(i!=0)printf(" ");
            printf("%s",A[ans[i]].c_str());
        }
        if(T!=0)
            printf("\n");
    }

}