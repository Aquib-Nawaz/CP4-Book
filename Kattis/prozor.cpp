#include <iostream>
using namespace std;
int arr[100][100];
char arr1[100][100];
int main() {
    int R,S,K;
    char c;
    scanf("%d%d%d",&R,&S,&K);
    int ret=-1,_i,_j,val;

    for(int i=0;i<R;i++)for(int j=0;j<S;j++){
        scanf(" %c",&c);
        arr[i][j]= c=='*';
        arr1[i][j]=c;
        if(i>0)arr[i][j]+=arr[i-1][j];
        if(j>0)arr[i][j]+=arr[i][j-1];
        if(i>0&&j>0)arr[i][j]-=arr[i-1][j-1];
        if(i>=K-1&&j>=K-1){
            val = arr[i-1][j-1]-arr[i-K+1][j-1]-arr[i-1][j-K+1]+arr[i-K+1][j-K+1];
            if(val>ret){
                ret = val;
                _i=i,_j=j;
            }
        }
    }
    arr1[_i][_j]  = arr1[_i][_j-K+1] = arr1[_i-K+1][_j] = arr1[_i-K+1][_j-K+1] = '+';
    for(int j=_j-K+2;j<_j;j++)arr1[_i][j] = arr1[_i-K+1][j] = '-';
    for(int i=_i-K+2;i<_i;i++)arr1[i][_j] = arr1[i][_j-K+1] = '|';
    printf("%d\n",ret);
    for(int i=0;i<R;i++){
        for(int j=0;j<S;j++)printf("%c",arr1[i][j]);
        printf("\n");
    }
    return 0;
}