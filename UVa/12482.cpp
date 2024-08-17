#include <iostream>
#include <cstring>
using namespace std;
char W[71];
int main() {
    int N,L,C,p,l,w;
    while(scanf("%d%d%d",&N,&L,&C)!=-1){
        p=l=1,w=0;
        for(int i=0;i<N;i++){
            scanf("%s",W);
            if(w!=0)w++;
            if(w+ strlen(W)>C){
                l++,w=0;
                if(l==L+1)p++,l=1;
            }
            w+=strlen(W);
        }
        printf("%d\n",p);
    }
}