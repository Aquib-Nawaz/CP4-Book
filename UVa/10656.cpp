#include <iostream>
using namespace std;

int main() {
    int n,d;
    while (scanf("%d", &n), n) {
        bool f=true;
        for(int i=0;i<n;i++) {
            scanf("%d", &d);
            if(d==0)continue;
            if(!f)printf(" ");
            printf("%d", d);
            f=false;
        }
        if(f)printf("0");
        printf("\n");
    }
    return 0;
}