#include <iostream>
#include <bitset>
using namespace std;

int ans, Chess[8][8], maxans;
bitset<20>ld,rd;
int counter;

void back_track(int m, int c){
    int _m = m;
    if (c == 8) {               // a candidate solution
        maxans = max(maxans,ans);
        return;
    }
    while(_m) {
        int t = _m & -_m, r = __builtin_ctz(t);
        if (!ld[r + c] && !rd[r - c + 7]) {
            ans+=Chess[r][c];
            ld[r + c] = rd[r - c + 7] = true;
            back_track(m ^ t, c + 1);
            ld[r + c] = rd[r - c + 7] = false;
            ans-=Chess[r][c];
        }
        _m ^= t;
    }
}

int main(){
    int T;
    scanf("%d" ,&T);
    while(T--){
        counter=ans=maxans=0;
        for(int i=0;i<8;i++)for(int j=0;j<8;j++)scanf("%d",&Chess[i][j]);

        back_track((1<<8)-1, 0);
        printf("%5d",maxans);
        if(T)printf("\n");
    }
}