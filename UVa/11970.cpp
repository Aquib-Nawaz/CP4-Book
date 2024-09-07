#include <iostream>
#include <algorithm>
using namespace std;
int squares[40000];

int main(){
    int T,n,nsq=0,C=0;
    for(int i=0;i*i<=1e9;i++)squares[nsq++]=i*i;
    scanf("%d", &T);

    while (T--){
        scanf("%d", &n);
        printf("Case %d:",++C);
        int m = lower_bound(squares, squares+nsq, n) - squares;
        for(int i=m-1,x;i>0;i--){
            x = n-squares[i];
            if(x % i == 0)printf(" %d", x);
        }
        printf("\n");
    }
}