#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;
int main(){
    int n;
    char x[4];
    scanf("%d %s", &n, x);
    if(n==1){
        printf("1\n");
        return 0;
    }
    int ans=0;
    if(strcmp("out", x)==0){
        int idx=2;
        do{
            if(idx<=(n+1)/2)
                idx = 2*idx-1;
            else
                idx = 2*(idx-(n+1)/2);
            ans++;
        }
        while(idx!=2);
    }
    else{
        int idx=1;
        do{
            if(idx<=n/2)
                idx = 2*idx;
            else
                idx = 2*(idx-n/2)-1;
            ans++;
        }
        while(idx!=1);
    }
    printf("%d\n" , ans);
    return 0;
}