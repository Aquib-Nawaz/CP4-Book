#include <iostream>
#include <cmath>
using namespace std;
int A[101];
int V[101];

bool next_combination(int n, int k){
    for(int i=k-1;i>=0;i--){
        if(V[i]<n-1){
            V[i]++;
            for(int j=i+1;j<k;j++)V[j]=V[i];
            return true;
        }
    }
    return false;
}

int main(){
    int T,N,S,C=0,len;
    scanf("%d",&T);
    while (T--){
        scanf("%d %d",&N, &S);
        for(int i=1;i<=N;i++)scanf("%d",A+i);
        int u= S/A[1],l=ceil(S*1.0/A[N]);

        printf("Case %d: ",++C);
        bool f=false;
        for(len=l;len<=u;len++){
            for(int i=0;i<len;i++)V[i]=0;
            do{
                int sum=0;
                for(int i=0;i<len;i++)sum+=A[N-V[i]];
                if(sum==S) {
                    f=true;
                    break;
                }
            }
            while(next_combination(N,len));
            if(f)break;
        }
        if(!f)printf("impossible\n");
        else {
            printf("[%d]",len);
            for(int i=0;i<len;i++)printf(" %d",A[N-V[i]]);
            printf("\n");
        }
    }
}