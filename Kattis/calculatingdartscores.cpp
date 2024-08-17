#include <iostream>
#include <cstring>
using namespace std;

void print(int i){
    if(i==0)return;
    if(i<=20)printf("single %d", i);
    else if(i%3==0)printf("triple %d", i/3);
    else printf("double %d", i/2);
    printf("\n");
}

bool is_valid(int i){
    return i<=20 || i%2==0 && i<=40 || i%3==0 && i<=60;
}

int main(){
    int n,sz=0;
    cin >> n;
    int A[61];
    memset(A,0,sizeof A);
    for(int i=0;i<21;i++)A[i]=A[2*i]=A[3*i]=1;
    for(int i=0;i<=60;i++)if(A[i])A[sz++]=i;
    for(int i=0;i<sz;i++)for(int j=0;j<sz;j++)
        if(is_valid(n-A[i]-A[j])){
        print(A[i]);
        print(A[j]);
        print(n-A[i]-A[j]);
        return 0;
    }
    printf("impossible");
    return 0;
}