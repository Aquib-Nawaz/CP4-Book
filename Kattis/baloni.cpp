#include <iostream>
using namespace std;
int B[1000001]={0};
int main(){
    int N, a,cnt=0;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d", &a);
        if(B[a]==0)
            cnt++;
        else
            B[a]--;
        B[a-1]++;
    }
    printf("%d\n", cnt);

}