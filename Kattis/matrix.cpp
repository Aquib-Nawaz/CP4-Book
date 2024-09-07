#include <iostream>
using namespace std;

int main(){
    int a,b,c,d,C=0;
    while (scanf("%d", &a)==1){
        scanf("%d %d %d", &b,&c,&d);
        int det = a*d-b*c;
        printf("Case %d:\n", ++C);
        printf("%d %d\n%d %d\n", d/det, -b/det, -c/det, a/det);
    }
}