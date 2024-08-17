#include <iostream>
#include <bitset>
using namespace std;

int temp[8];
bitset<20>ld,rd;
int counter, x,y;
void back_track(int m, int c){
    int _m = m;
    if (c == 8) {               // a candidate solution
        printf("%2d      %d", ++counter, temp[0]+1);
        for (int j = 1; j < 8; ++j) printf(" %d", temp[j]+1);
        printf("\n");
        return;
    }
    while(_m) {
        int t = _m & -_m, r = __builtin_ctz(t);
        if (!ld[r + c] && !rd[r - c + 7] && ((c==y)==(r==x))) {
            temp[c] = r;
            ld[r + c] = rd[r - c + 7] = true;
            back_track(m ^ t, c + 1);
            ld[r + c] = rd[r - c + 7] = false;
        }
        _m ^= t;
    }
}

int main(){
    int T;
    scanf("%d" ,&T);
    while(T--){
        counter=0;
        scanf("%d %d", &x, &y);
        x--;y--;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        back_track((1<<8)-1, 0);
        if(T)printf("\n");
    }
}