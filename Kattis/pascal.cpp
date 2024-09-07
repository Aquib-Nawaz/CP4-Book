#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int i;
    for(i=2;i*i<=n;i++)if(n%i==0)break;
    if(i*i>n)i=n;
    printf("%d\n",n-n/i);
}