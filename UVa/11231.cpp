#include <iostream>
using namespace std;

int main(){
    int n,m,t;
    while(scanf("%d%d%d", &n,&m,&t),n){
        int nb = (n-8)/2+1,nw = (n<9?0:(n-9)/2+1);
        if(t)swap(nw,nb);
        printf("%d\n", nb*(m<9?0:(m-7)/2)+nw*((m-8)/2+1));
    }

}