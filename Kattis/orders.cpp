#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int par[30001], arr[101], ids[100];
int main(){
    int n,d, m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",arr+i);
    }
    memset(par, -1, sizeof par);
    par[0]=0;
    for(int i=1;i<=n;i++){
        int v1 = arr[i];
        for(int v = v1; v<=30000;v++){
            if(par[v-v1]==-1)continue;
            if(par[v-v1]==-2 || par[v]!=-1)par[v] = -2;
            else par[v] = i;
        }
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&d);
        if(par[d]==-2)printf("%s","Ambiguous");
        else if(par[d]==-1)printf("%s","Impossible");
        else {
            int sz=0;
            for(sz=0;d>0;d-=arr[par[d]],sz++){
                ids[sz] = par[d];
            }
            sort(ids, ids+sz);
            bool f= true;
            for(int j=0;j<sz;j++){
                if(!f)printf(" ");
                else f=false;
                printf("%d",ids[j]);;
            }
        }
        if(i!=m-1)printf("\n");
    }

}