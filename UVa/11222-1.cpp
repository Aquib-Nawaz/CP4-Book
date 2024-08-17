#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
int A[3][1001],S[3];

int main() {
    int N, C = 0;
    scanf("%d", &N);
    while (C++ < N) {
        printf("Case #%d:\n", C);
        REP(j, 3) {
            scanf("%d", &S[j]);
            REP(i, S[j])scanf("%d", &A[j][i]);
        }
        REP(i, 3)sort(A[i], A[i] + S[i]);
//        int sz[3] = {0};
//        REP(i, 3) {
//            for (int j = 1; j < S[i]; j++)
//                if (A[i][j - 1] != A[i][j])
//                    A[i][++sz[i]] = A[i][j];
//        }
//        REP(i, 3)S[i] = sz[i] + 1;
        unordered_map<int, int>mp;
        REP(i,3) REP(j,S[i]) mp[A[i][j]]++;

        vector<int>res[3];
        REP(i,3)REP(j,S[i]) if(mp[A[i][j]]==1) res[i].push_back(A[i][j]);

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