#include <iostream>
#include <bitset>
using namespace std;

int A[92][8],C[8],counter=0, temp[8];
bitset<20>ld,rd;
int ans;
void back_track(int m, int c){
    if (c == 8) {
        for(int i=0;i<8;i++)A[counter][i]=temp[i]+1;
        counter++;
        return;
    }
    int _m = m;
    while(_m) {
        int t = _m & -_m, r = __builtin_ctz(t);
        if (!ld[r + c] && !rd[r - c + 7] ) {
            temp[c] = r;
            ld[r + c] = rd[r - c + 7] = true;
            back_track(m ^ t, c + 1);
            ld[r + c] = rd[r - c + 7] = false;
        }
        _m ^= t;
    }
}

int main(){
    int T=0;
    back_track((1<<8)-1, 0);
    while(scanf("%d", &C[0])!=-1){
        ans=8;
        for(int i=1;i<8;i++)scanf("%d",&C[i]);

        for(int j=0;j<92;j++){
            int ts=0;
            for(int i=0;i<8;i++)if(A[j][i]!=C[i])ts++;
            ans=min(ans,ts);
        }
        printf("Case %d: %d\n", ++T, ans);
    }
}