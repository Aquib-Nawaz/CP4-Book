#include <iostream>
using namespace std;

int main(){
    char c;
    int p1=0,p2=0,p3=0;
    scanf("%c",&c);
    char curc1 = c, curc2=c, curc3=c;
    while(scanf("%c", &c),c!='\n'){

        if(c=='U'){
            if(curc1!='U') p1++;
            if(curc2!='U')p2+=2;
            else p2++;
        }
        else{
            if(curc2!='D') p2++;
            if(curc1!='D')p1+=2;
            else p1++;
        }
        p3+=curc3!=c;
        curc1 = 'U';
        curc2 = 'D';
        curc3 = c;

    }
    printf("%d\n%d\n%d\n",p1,p2,p3);
}