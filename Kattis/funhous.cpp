#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

#define REPI(i, b, n) for (int i = b; i < n; i++)
#define REP(i, n) REPI(i, 0, n)
char A[21][21];

int dir[4][2] = {{-1,0}, {0,-1}, {1, 0}, {0, 1}};
unordered_map<char, int>chngdir[4] = {{{'/', 3}, {'\\', 1}}, {{'/', 2}, {'\\', 0}},
                                      {{'/', 1}, {'\\', 3}}, {{'/', 0}, {'\\', 2} }};
int main(){
    int L,W,C=0;
    while(scanf("%d %d", &W, &L), L){

    REP(i,L)scanf("%s", A[i]);
    int d, curx, cury;
    REP(i,W-2)if(A[0][i+1]=='*'){curx=0, cury=i+1, d=2;break;}
    REP(i,W-2)if(A[L-1][i+1]=='*'){curx=L-1, cury=i+1, d=0;break;}
    REP(i,L-2)if(A[i+1][0]=='*'){curx=i+1, cury=0, d=3;break;}
    REP(i,L-2)if(A[i+1][W-1]=='*'){curx=i+1, cury=W-1, d=1;break;}

    while(true){
        curx += dir[d][0], cury += dir[d][1];
        if(A[curx][cury]=='x')break;
        if(A[curx][cury]!='.')
            d = chngdir[d][A[curx][cury]];
    }
    A[curx][cury] = '&';
    printf("HOUSE %d\n", ++C);
    REP(i,L)printf("%s\n", A[i]);

    }
}