#include <iostream>
using namespace std;

int op[7] = {0,1,2,5,9,8,6};
int main(){
    int N;
    while (scanf("%d", &N) == 1) {
        while(N){
            printf("%d",op[N%7]);
            N/=7;
        }
        printf("\n");
    }
}