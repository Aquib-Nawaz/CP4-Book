#include <iostream>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    int a,b,ans;
    char c;
    while(n--){
        scanf("\n%c %d %d", &c, &a, &b);
        int m=min(a,b), M=max(a,b);
        switch(c){
            case 'k':
                if(m==1) ans = M;
                else if(m==2) ans = 4*(M/4) + 2*(min(2, M%4));
                else ans =(a*b+1)/2;
                break;
            case 'r':
                ans = m;
                break;
            case 'Q':
                if(m>=4||m==1||m<M)ans=m;
                else ans=m-1;
                break;
            case 'K':
                ans=((m+1)/2)*((M+1)/2);
                break;

        }
        printf("%d\n", ans);
    }
}