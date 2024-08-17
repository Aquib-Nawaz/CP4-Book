#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,_n, m;
    scanf("%d", &n);
    _n = n;
    for(;_n!=0;_n/=10){
        for( m=_n/10;m!=0;m/=10){
            if(m%10<_n%10)break;
        }
        if(m!=0)break;
    }
    if(_n==0){printf("0"); return 0;}
    if(m>=10)printf("%d",m/10);
    printf("%d", _n%10);
    int A[10],i=0;
    while(n>=m){if(n!=_n)A[i++] = n%10; n/=10;}
    sort(A,A+i);
    for(int j=0;j<i;j++)printf("%d",A[j]);
    return 0;

}