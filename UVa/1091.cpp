#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

map<string, int>mp;
int b[150];
int decode[35];
int main() {
    mp["00001"]=0;
    mp["10001"]=1;
    mp["01001"]=2;
    mp["11000"]=3;
    mp["00101"]=4;
    mp["10100"]=5;
    mp["01100"]=6;
    mp["00011"]=7;
    mp["10010"]=8;
    mp["10000"]=9;
    mp["00100"]=10;
    mp["00110"]=-1;

    int n,Case=0;
    while(scanf("%d",&n),n){
        printf("Case %d: ",++Case);
        int maxw=0,minw=201;
        for(int i=0;i<n;i++){
            scanf("%d", &b[i]);
            maxw=max(maxw,b[i]);
            minw=min(minw,b[i]);
        }
        if(n%6!=5 || (n+1)/6<5){
            printf("bad code\n");
            continue;
        }
        double t = (maxw+minw)/2.0;
        int v;
        minw=401;maxw=0;
        for(int i=0;i<n;i++){
            if(b[i]<t){
                v=2*b[i];
            }
            else{
                v=b[i];
            }
            minw = min(minw,v),maxw = max(maxw,v);
        }
        if((maxw-minw)*1.0/(maxw+minw)>.05){
            printf("bad code\n");
            continue;
        }
        char var[6];
        var[5]='\0';
        for(int j=0;j<5;j++){
            if(b[j]<t)
                var[j]='0';
            else
                var[j]='1';
        }

        if(strcmp(var, "01100")==0)
            reverse(b, b+n);
        int i;
        bool valid=true;
        for( i=0;i<n;i+=6){
            for(int j=0;j<5;j++){
                if(b[j+i]<t)
                    var[j]='0';
                else
                    var[j]='1';
            }
            if(mp.count(var)==0||(i+5<n&&b[i+5]>=t) ){
                printf("bad code\n");
                valid=false;
                break;
            }
            else{
                decode[i/6]=mp[var];
            }
        }
        if(!valid)
            continue;
        i/=6;
        if(decode[0]!=decode[i-1] || decode[0]!=-1 || find(decode+1,decode+i-1,decode[0])!=decode+i-1){
            printf("bad code\n");
            continue;
        }
        int C=0,K=0;
        for(int j=1;j<i-3; j++)
            C = (C+((i-4-j)%10+1)*decode[j])%11, K=(K+((i-3-j)%9+1)*decode[j])%11;
        K = (K+C)%11;

        if(C!=decode[i-3] ){
            printf("bad C\n");
            continue;
        }
        if(K!=decode[i-2] ){
            printf("bad K\n");
            continue;
        }
        for(int j=1;j<i-3;j++){
            printf("%c",decode[j]<10?decode[j]+'0':'-');
        }
        printf("\n");
    }

}