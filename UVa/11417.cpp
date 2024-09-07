#include <iostream>
using namespace std;

#define MAX 501
int A[MAX];

int gcd(int a, int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

void init(){
    for(int & i : A)i=0;
    for(int i=2;i<MAX;i++)for(int j=1;j<i;j++)A[i]+=gcd(i,j);
    for(int i=1;i<MAX;i++)A[i]+=A[i-1];
}

int main(){
    init();
    int n;
    while(cin>>n,n)cout<<A[n]<<endl;
}
