#include <iostream>
using namespace std;

int main(){
    int n,C;
    int A[12];
    scanf("%d", &n);
    while(n--){
        scanf("%d",&C);
        for(int i=0;i<12;i++)scanf("%d", A+i);
        int ans=0;
        for(int i=1;i<11;i++){
            int m=A[i];
            for(int j=i;j<11;j++){
                m=min(A[j],m);
                if(A[i-1]<m&&A[j+1]<m)ans++;
            }
        }
        printf("%d %d\n", C,ans);
    }
}