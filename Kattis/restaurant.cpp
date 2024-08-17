#include <iostream>
#include <stack>

using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
char command[5];
int main(){
    int N,sum1, sum2, m;
    bool f=true;
    while(scanf("%d", &N),N){
        sum1=sum2=0;
        if(!f)
            printf("\n");
        f=false;
        REP(i,N){
            scanf("%s %d", command, &m);
            if(command[0]=='D'){
                sum1+=m;
                printf("DROP 1 %d\n", m);
            }
            else {
                if(sum2>=m){
                    printf("TAKE 2 %d\n", m);
                    sum2-=m;
                }
                else{
                    if(sum2!=0)
                        printf("TAKE 2 %d\n", sum2);
                    m-=sum2;
                    printf("MOVE 1->2 %d\n", sum1);
                    sum2=sum1-m;
                    sum1=0;
                    printf("TAKE 2 %d\n", m);
                }
            }

        }

    }

}