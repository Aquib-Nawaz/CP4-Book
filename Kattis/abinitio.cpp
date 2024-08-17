#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define PRIME 1000000007
bool A[4000][4000];

int main(){
    int V,E,Q,x,y,t,cnt,ret;
    long long pow;
    bool T=false,C=false;
    scanf("%d %d %d", &V,&E,&Q);
    memset(A,0,sizeof A);
    for(int i=0;i<E;i++){
        scanf("%d %d", &x,&y);
        A[x][y]=true;
    }
    for(int i=0;i<Q;i++){
        scanf("%d", &t);
        if(t==1){
            V++;
            if(C){
                for(int j=0;j<V;j++)A[V-1][j]=A[j][V-1]=true;
            }
        }
        else if(t==5)T=!T;
        else if(t==6)C=!C;
        else if(t==2||t==4){
            scanf("%d %d", &x, &y);
            if(T)swap(x,y);
            A[x][y]= !A[x][y];
        }
        else{
            scanf("%d", &x);
            for(int j=0;j<V;j++){
                A[x][j]=A[j][x]=C;
            }
        }
    }
    printf("%d\n", V);
    if(T)
        for(int i=0;i<V;i++)for(int j=0;j<i;j++)swap(A[i][j],A[j][i]);
    for(int i=0;i<V;i++){
        pow=1;cnt=0,ret=0;
        for(int j=0;j<V;j++){
            if(i==j)continue;
            x=A[i][j];
            if(C)x=!x;
            if(x){
                ret = (ret+pow*j)%PRIME;
                cnt++;pow=(pow*7)%PRIME;
            }
        }
        printf("%d %d\n", cnt,ret);
    }
}