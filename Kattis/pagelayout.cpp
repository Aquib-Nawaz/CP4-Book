#include <iostream>
using namespace std;

struct rect
{
    int x;
    int y;
    int width;
    int height;
};

bool valueInRange(int value, int min, int max)
{ return (value >= min) && (value < max); }

bool rectOverlap(rect &A, rect &B)
{
    bool xOverlap = valueInRange(A.x, B.x, B.x + B.width) ||
                    valueInRange(B.x, A.x, A.x + A.width);

    bool yOverlap = valueInRange(A.y, B.y, B.y + B.height) ||
                    valueInRange(B.y, A.y, A.y + A.height);

    return xOverlap && yOverlap ;
}
rect rects[20];
int edge[20],n,ans, cur;

void solve(int id, int used){
    ans = max(cur,ans);
    for(int i=id;i<n;i++){
        if(!(used&1<<i)){
            cur+=rects[i].width*rects[i].height;
            solve(i+1,used|edge[i]);
            cur-=rects[i].width*rects[i].height;
        }
    }
}

int main(){
    while (scanf("%d",&n),n){
        ans=cur=0;
        for (int i=0;i<n;i++)
            scanf("%d %d %d %d",&rects[i].width,&rects[i].height,&rects[i].x,&rects[i].y),edge[i]=0;
        for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(rectOverlap(rects[i],rects[j]))edge[i]|=1<<j,edge[j]|=1<<i;
        solve(0,0);
        printf("%d\n",ans);
    }
}