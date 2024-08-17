#include <iostream>
using namespace std;

int main() {
    int a, b;
    bool f=true;
    while(scanf("%d %d", &a, &b) != EOF && a||b) {
        int c=0,ans=0;
        if(!f)printf("\n");
        f=false;
        while(a&&b){
            if(c+a%10+b%10>=10)
                c=1,ans++;
            else
                c=0;
            a/=10;
            b/=10;
        }
        ans+=(a%10+b%10+c)/10;
        if(ans==0)
            printf("No carry operation.");
        else if(ans==1)
            printf("1 carry operation.");
        else
            printf("%d carry operations.",ans);
    }
}