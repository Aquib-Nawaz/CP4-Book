#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int T,C=0;
    scanf("%d", &T);
    while (T--){
        int N;
        scanf("%d", &N);
        printf("Case #%d: ", ++C);
        if(N==0){
            printf("0\n");
            continue;
        }
        string ret;
        int sgn=1;
        if(N<0)sgn=-1,N=-N;
        while(N){
            int cur = N&1;
            ret.push_back(cur+'0');
            N-=cur*sgn;
            sgn*=-1;
            N>>=1;
        }
        reverse(ret.begin(), ret.end());
        printf("%s\n", ret.c_str());
    }
}