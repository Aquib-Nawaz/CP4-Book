#include <iostream>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n)==1){
        printf("%d\n",32-__builtin_clz(n));
    }
}