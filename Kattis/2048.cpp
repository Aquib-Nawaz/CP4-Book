#include <iostream>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
int A[4][4],a;
int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};

bool in_range(int i, int j){
    return i+dir[a][0]>=0 && i+dir[a][0]<4 && j+dir[a][1]>=0 && j+dir[a][1]<4;
}

bool marked[4][4]={false};
int changed[4][4]={-1};

int main(){
    REP(i,4)REP(j,4)scanf("%d",&A[i][j]);
    scanf("%d", &a);
    int _i,_j;
    REP(_,4)REP(i,4)REP(j,4) if(in_range(i,j)&&changed[i][j]!=_){

        _i=i+dir[a][0], _j=j+dir[a][1];
        if(A[i][j]>0&&A[_i][_j]==A[i][j] && !marked[i][j] && !marked[_i][_j]){
            A[_i][_j]<<=1;
            A[i][j]=0;
            marked[_i][_j]=true;
            changed[_i][_j]=_;
        }
        if(A[_i][_j]==0){
            A[_i][_j]=A[i][j];
            marked[_i][_j] = marked[i][j];
            marked[i][j]=false;
            A[i][j]=0;
            changed[_i][_j]=_;
        }
    }
    REP(i,4){REP(j,4){if(j!=0)printf(" "); printf("%d",A[i][j]);}
    printf("\n");}
}