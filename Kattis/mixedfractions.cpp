#include <iostream>
using namespace std;

int main(){
    int num,den;

    while (scanf("%d %d", &num,&den),num || den){
        printf("%d %d / %d\n", num/den, num%den, den);
    }
}