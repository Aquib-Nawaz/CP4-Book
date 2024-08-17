#include <iostream>
using namespace std;
char A[100][101];
int main(){
    int T,M,N,Q,r,c;
    scanf("%d", &T);
    while (T--){
        scanf("%d %d %d\n", &M, &N, &Q);
        for (int i = 0; i < M; i++){
            scanf("%s", A[i]);
        }
        printf("%d %d %d\n", M,N,Q);
        for (int _ = 0; _ < Q; _++){

            scanf("%d %d", &r, &c);
            int l;
            char s=A[r][c];
            for(l=1;;l++){
                if (r-l<0 || c-l<0 || r+l>=M || c+l>=N) break;
                bool err=false;
                for (int i = r-l; i <= r+l&&!err; i++){
                    for (int j = c-l; j <= c+l; j++){
                        if(A[i][j]!=s){
                            err=true;
                            break;
                        }
                    }
                }
                if(err)break;
            }
            printf("%d\n", 2*l-1);
        }
    }
}