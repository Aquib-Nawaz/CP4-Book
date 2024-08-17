#include<iostream>
using namespace std;

int dir[8][2]={{1,2}, {0,2}, {0,1}, {0,0}, {1,0},
               {2,0}, {2,1}, {2,2}};

int G[3][3];
int main(){
    int x,y,d,_x,_y;
    while(scanf("%d%d%d", &x,&y,&d), x!=-1){
        G[1][1]=d;
        for(int i=0;i<8;i++){
            scanf("%d%d%d", &_x,&_y, &d);
            _x-=x-1, _y-=y-1;
            G[_x][_y]=d;
        }
        d= G[1][1]-2;
        if(d<0) d+=8;

        for(int i=0;i<8;i++,d=(d+1)%8){
            if(G[dir[d][0]][dir[d][1]]==1)break;
        }
        printf("%d\n",d);
    }

}