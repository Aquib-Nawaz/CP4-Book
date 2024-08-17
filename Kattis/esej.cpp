#include <iostream>
using namespace std;

int main(){
    int A, B;
    scanf("%d %d", &A, &B);
    for(int i=0;i<max(A,B/2);i++){
        int j=i;
        for(int k=0;k<4;k++)printf("%c", j%26+'a'), j/=26;
        if(i!=max(A,B/2)-1)
        printf(" ");
    }
}