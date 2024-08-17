#include <iostream>
using namespace std;

int main(){
    int a,b,n,u,v;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&a,&b);
        u = (a+b)/2; v=(a-b)/2;
        if(v<0 || (a+b)%2!=0)
            printf("impossible\n");
        else
            printf("%d %d\n",u,v);
    }
}