#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
char C[500001];
int main(){
    while (scanf("%s", C)!=-1){
        char * pre = strchr(C, 'X'), *cur;
        long ans=pre-C-1;
        while(cur=strchr(pre+1, 'X'), cur){
            ans=max(ans,(cur-pre-2)/2);
            pre=cur;
        }
        ans=max(ans,C+strlen(C)-pre-2);
        printf("%ld\n", ans);
    }


}