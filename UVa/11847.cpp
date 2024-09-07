#include <iostream>
using namespace std;

int main(){
    int n;
    while (scanf("%d",&n),n){
        printf("%d\n",31-__builtin_clz(n));
    }
}