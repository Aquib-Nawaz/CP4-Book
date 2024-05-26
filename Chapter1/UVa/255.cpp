#include <iostream>
#include <cmath>
using namespace std;

bool inbetween(int a, int b, int c){
    return (a<=b && b<=c) || (a>=b && b>=c);
}

int main(){
    int a,b,c;
    while(scanf("%d %d %d", &a, &b, &c)!=EOF){
        if(a==b||a>63||a<0||b<0||b>63)
            printf("Illegal state\n");
        else if(a==c||b==c||c<0||c>63||(b/8!=c/8 && b%8!=c%8)||(b/8==c/8 && b/8==a/8&& inbetween(b%8, a%8, c%8))||
                (b%8==c%8 && b%8==a%8 && inbetween(b/8, a/8, c/8)))
            printf("Illegal move\n");
        else if(abs(c-a)==8||(a%8!=7&&a+1==c)||(a%8!=0&&a-1==c))
            printf("Move not allowed\n");
        else if((a==0&&c==9)||(a==7&&c==14)||(a==56&&c==49)||(a==63&&c==54)){
            printf("Stop\n");
        }
        else{
            printf("Continue\n");
        }
    }
}