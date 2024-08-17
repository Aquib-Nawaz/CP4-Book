#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
int A[3][1001],S[3];
int main(){
    int N,C=0;
    scanf("%d", &N);
    while(C++<N){
        printf("Case #%d:\n", C);
        REP(j,3){
            scanf("%d",&S[j]);
            REP(i,S[j])
                scanf("%d",&A[j][i]);
        }
        REP(i,3)
            sort(A[i],A[i]+S[i]);
        //Why lol lol lol
//        int sz[3]={0};
//        REP(i,3){
//            for(int j=1;j<S[i];j++)
//                if(A[i][j-1]!=A[i][j])
//                    A[i][++sz[i]]=A[i][j];
//        }
//        REP(i,3)S[i]=sz[i]+1;
        int i,j,k;
        i=j=k=0;
        vector<int>res[3];
        while(i<S[0]){
            while(j<S[1] && A[1][j]<A[0][i]){
                while(k<S[2] && A[2][k]<A[1][j]){
                    res[2].push_back(A[2][k++]);
                }
                if(k<S[2]&&A[2][k]==A[1][j])
                    k++;
                else
                    res[1].push_back(A[1][j]);
                j++;
            }
            while(k<S[2] && A[2][k]<A[0][i]){
                res[2].push_back(A[2][k++]);
            }
            bool f=false;
            if(k<S[2]&&A[2][k]==A[0][i])
                k++,f=true;
            if(j<S[1]&&A[1][j]==A[0][i])
                j++,f=true;
            if(!f)
                res[0].push_back(A[0][i]);
            i++;
        }

        while(j<S[1]){
            while(k<S[2]&&A[2][k]<A[1][j]){
                res[2].push_back(A[2][k++]);
            }
            if(k<S[2]&&A[2][k]==A[1][j])
                k++;
            else
                res[1].push_back(A[1][j]);
            j++;
        }
        while(k<S[2]){
            res[2].push_back(A[2][k++]);
        }

        int ans = 0;
        REP(l,3)
            ans=max(ans,int(res[l].size()));
        REP(l,3){
            if(res[l].size()==ans){
                printf("%d %d", l+1, ans);
                REP(m,res[l].size())
                    printf(" %d", res[l][m]);
                printf("\n");
            }
        }
    }
}