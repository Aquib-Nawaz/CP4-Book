#include <iostream>
using namespace std;
int A[256];

void populate(){
    for(int i=0;i<=255;i++){
        A[(i^(i<<1))&255]=i;
    }
}

int main(){
    populate();
    int n,d;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &d);
        if(i!=0)printf(" ");
        printf("%d", A[d]);
    }
}