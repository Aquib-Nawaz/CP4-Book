#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); i++)

char A[2][11][11], tmp;
int C=0, N;

void rotate(){
    REP(i,N/2)for(int j=i;j<N-i-1; j++){
        tmp = A[0][i][j];
        A[0][i][j] = A[0][N-1-j][i];
        A[0][N-1-j][i] = A[0][N-1-i][N-1-j];
        A[0][N-1-i][N-1-j] = A[0][j][N-1-i];
        A[0][j][N-1-i] = tmp;
    }
}

bool compare(){
    REP(i,N)REP(j,N)if(A[0][i][j]!=A[1][i][j])return false;
    return true;
}

void reflect(){
    REP(i,N/2)REP(j,N)swap(A[0][i][j], A[0][N-1-i][j]);
}

int main(){
    while(++C){
        if(scanf("%d", &N)==-1) break;
        printf("Pattern %d was ", C);
        REP(i, N)REP(j,2)scanf("%s", A[j][i]);
        int deg = 0;
        if(compare()){
            printf("preserved.\n");
            continue;
        }
        bool f= false;
        REP(_,3){
            rotate();
            deg+=90;
            if(compare()){
                printf("rotated %d degrees.\n", deg);
                f=true;
                break;
            }
        }
        if(f)continue;
        rotate();
        reflect();
        if(compare()){
            printf("reflected vertically.\n");
            continue;
        }
        deg=0;
        REP(_,3){
            rotate();
            deg+=90;
            if(compare()){
                printf("reflected vertically and rotated %d degrees.\n", deg);
                f=true;
                break;
            }
        }
        if(f)continue;
        printf("improperly transformed.\n");
    }
    return 0;
}
