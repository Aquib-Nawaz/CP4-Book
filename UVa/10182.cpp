#include <iostream>
using namespace std;

int dir[][2]={{0,-1},{-1,0},{-1,1},{0,1},{1,0},{1,-1}};

int main(){
    int n;
    while(scanf("%d", &n)==1){
        if(n==1){
            printf("0 0\n");
            continue;
        }
        int k=1,i=0;
        while(k<n){
            i++;
            k+=6*i;
        }
        int x=i,y=0;
        for(int j=0;j<6&&k>n;j++){
            int d = min(k-n,i);
            x+=dir[j][0]*d;
            y+=dir[j][1]*d;
            k-=d;
        }
        printf("%d %d\n",x,y);
    }
    //1 + 6 + 12 + 18

}