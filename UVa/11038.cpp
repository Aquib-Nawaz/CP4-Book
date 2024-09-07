#include <iostream>
#include <cstring>
using namespace std;

int cnt(unsigned int x, bool f=0){
   char s[15];
    snprintf(s,15,"%u",x);
    int l=strlen(s);
    int po = 1,cnt=0;
    unsigned int y=x;
    for(int i=l-1;i>0;i--){
        x/=10;
        if(s[i]=='0'){
            cnt+=(x-1)*po+(y%po+1);
        }
        else {
            cnt+=x*po;
        }
        po*=10;
    }
    return cnt;
}

int main(){
    unsigned int n,m;
    while (scanf("%u%u", &n,&m),n!=-1){
        printf("%u\n",cnt(m)-(n==0?-1:cnt(n-1)));
    }
}