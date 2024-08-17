#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
int N;
char answers[100][100][51];

int main(){
    scanf("%*[^\n]\n");
    scanf("%d\n", &N);
    int sz;
    REP(i, N){
        int j=0;
        while(true) {
            int k=0;
            char c;
            while(scanf("%c", &c), c!='\n'&&c!=','){
                answers[i][j][k++]=c;
            }
            answers[i][j][k]=0;
            if(c=='\n')break;
            scanf("%c", &c);
            j++;
        }
        sz=j+1;
    }
    int mn=sz+1;
    int count[N];
    REP(i, N){
        count[i]=0;
        REP(j, N){
            int cnt=0;
            REP(k, sz){
                if (strcmp(answers[i][k], answers[j][k]) != 0){
                    cnt++;
                }
            }
            count[i]=max(cnt,count[i]);
        }

        mn = min(count[i], mn);
    }

    REP(j,N){
        if(mn==count[j]){
            REP(i, sz){
                if(i!=0)
                    printf(", ");
                printf("%s", answers[j][i]);
            }
            printf("\n");
        }
    }
}