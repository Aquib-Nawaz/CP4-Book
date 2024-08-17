#include <iostream>
#include <cstring>
using namespace std;

int _H[100];

int main(){
    int T,C=0,N,H,Ta,Td,d;
    scanf("%d",&T);
    while(T--){
        int ans=0;
        scanf("%d%d%d%d", &N, &H, &Ta, &Td);
        memset(_H,0,sizeof _H);
        for(int i=0;i<N;i++)scanf("%d", &d), _H[d]++;
        if(Td<2*Ta){
        for(int i=99,j;i>=0;i--){
            j = min(i, H-i-1);
            if(j==i){
                ans+=_H[i]/2;
                _H[i]&=1;
                j--;
            }
            while(_H[i]>0&&j>=0){
                int x=min(_H[i],_H[j]);
                _H[i]-=x;
                _H[j]-=x;
                ans+=x;
                j--;
            }
        }}
        printf("Case %d: %d\n", ++C, ans*Td + (N-2*ans)*Ta);

    }
}