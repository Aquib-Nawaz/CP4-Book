#include <iostream>
using namespace std;

char A[10][10];
int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
void solve(int n){
    int x,y,k;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        if(A[i][j]!='.')continue;
        char mn='A';
        for(;;mn++){
            for( k=0;k<4;k++){
                x=i+dir[k][0];
                y=j+dir[k][1];
                if(x<0||x>=n||y<0||y>=n)continue;
                if(mn==A[x][y])break;
            }
            if(k==4){A[i][j]=mn; break;}
        }
    }
}


int main(){
    int T,n,C=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) for(int j=0;j<n;j++)scanf(" %c",A[i]+j);
        solve(n);
        printf("Case %d:\n",++C);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)printf("%c",A[i][j]);
            printf("\n");
        }
    }
}