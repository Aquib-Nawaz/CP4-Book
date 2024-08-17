#include <iostream>
#include <cstring>
using namespace std;
int A[1001];
int main(){
    int n,a,p;
    while(scanf("%d",&n), n){
        memset(A,-1,sizeof A);
        bool b=true;
        for(int i=0; i<n; i++){
            scanf("%d %d", &a, &p);
            if(i+p<0 || i+p>=n || A[i+p]!=-1)
                b=false;
            else
                A[i+p]=a;
        }
        if(!b)
            printf("-1");
        else{
            printf("%d", A[0]);
            for(int i=1; i<n; i++)
                printf(" %d", A[i]);
        }
        printf("\n");
    }
}