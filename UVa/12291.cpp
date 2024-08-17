#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char A[2][12][12]={'.'};
int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
#define REP(i, n) for(int i=0;i<n;i++)
#define REP1(i, n) for(int i=1;i<=n;i++)

void move_u(char arr[12][12], int n){
    REP(i,n-1)REP(j,n)arr[i][j] = arr[i+1][j];
    REP(j,n)arr[n-1][j]='.';
}

void move_d(char arr[12][12], int n){
    for(int i=n-1;i>0;i--)REP(j,n)arr[i][j] = arr[i-1][j];
    REP(j,n)arr[0][j]='.';

}

void move_l(char arr[12][12], int n){
    REP(i,n)REP(j,n-1)arr[i][j] = arr[i][j+1];
    REP(i,n)arr[i][n-1]='.';

}

void move_r(char arr[12][12], int n){
    REP(i,n)for(int j=n-1;j>0;j--)arr[i][j] = arr[i][j-1];
    REP(i,n)arr[i][0]='.';
}

void canon(char arr[12][12], int n){
    while(find(arr[0], arr[0]+n, '*')==arr[0]+n)
        {move_u(arr, n);}

    bool ec=true;
    while(ec){
        REP(i,n)if(arr[i][0]=='*')ec=false;
        if(ec)move_l(arr, n);
    }
}

int mycount(char arr[12][12], int n){
    int ret=0;
    REP(i,n)REP(j,n)if(arr[i][j]=='*')ret++;
    return ret;
}

char diff[12][12];
int get_diff(char arr1[12][12], char arr2[12][12], int n){
    int ret=0;
    REP(i,n)REP(j,n)
    if(arr1[i][j]=='*'&&arr2[i][j]=='*')diff[i][j]='.', ret++;
    else if(arr1[i][j]=='.'&&arr2[i][j]=='*')return -1;
    else diff[i][j]=arr1[i][j];
    return ret;
}

int main(){
    int S[2], cnt[2];
    while(cin >> S[0] >>S[1],S[0]){
        memset(A, '.', sizeof A);
    REP(j,2)REP(i,S[j])scanf("%s", A[j][i]);
    REP(i,2)REP(j,S[i])A[i][j][S[i]]='.';
    REP(j,2){
        canon(A[j], S[j]);
        cnt[j] = mycount(A[j], S[j]);
    }
    if(cnt[0]!=2*cnt[1]){
        printf("0\n");
        continue;
    }
    int r=S[0]-1,c=S[0]-1;
    bool valid=false;
    char cur[12][12];
    memcpy(cur, A[1], sizeof A[1]);
    while(true){
        memset(diff, '.', sizeof diff);
        if(get_diff(A[0], cur, S[0])==cnt[1]){
            canon(diff, S[0]);
            if(get_diff(A[1], diff, S[1])==cnt[1]){
                valid=true;
                break;
            }
        }
        bool er=true,ec=true;

        REP(i,S[0])if(cur[r][i]=='*')er=false;
        REP(i,S[0])if(cur[i][c]=='*')ec=false;

        if(er)move_d(cur, S[0]);
//        else if(ec)move_r(cur, S[0]);
        else break;
    }
    if(valid)printf("1\n");
    else printf("0\n");

    }
}