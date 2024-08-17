#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
    int n;
    scanf("%d\n", &n);
    int xv=0, v=0, t;
    int dir=1;
    char c[2],cur='+';
    char op[7];
    char *en;
    while(n--){
        c[0]='\0';
        while(scanf("%[0-9x]%"
                    "[\n]", op,c)!=EOF){

            t = (int)strtol(op,&en, 10);
            if(*en=='x'){
                if(op[0]=='x')
                    t=1;
                xv+=dir*t*(cur=='+'?1:-1);
            }
            else {
                v += dir * t * (cur == '+' ? -1 : 1);
            }

            if(c[0]=='\n')
                break;
            scanf("%c", &cur);
            if(cur=='='){
                dir=-1;
                cur='+';
            }
        }
        if(v==0 && xv==0)
            printf("IDENTITY\n");
        else if(v!=0 && xv==0)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", (int)floor(v*1.0/xv));

        v=xv=0;
        dir=1;
        cur='+';
    }
    return 0;
}