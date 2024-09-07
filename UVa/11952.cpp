#include <iostream>
using namespace std;

int base10(int x, int b){
    int pow=1,ret=0;
    while (x){
        ret+=(x%10)*pow;
        pow*=b;
        x/=10;
    }
    return ret;
}

int minb(int x){
    int ret=0;
    bool one=x;
    while(x){
        one&=x%10==1;
        ret = max(x%10+1, ret);
        x/=10;
    }
    if(one)return 1;
    return ret;
}

int nones(int x){
    int ans=0;
    while (x){
        ans++;
        x/=10;
    }
    return ans;
}

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        int a,b,c,u,v,w,m;
        scanf("%d + %d = %d", &a,&b,&c);
        m = max(max( minb(a), minb(b)),minb(c));
        if(m==1){
            if(nones(a)+ nones(b)== nones(c)){
                printf("1\n");
                continue;
            }
        }
        bool f=0;
        for(int i=max(m,2);i<=18;i++){
            u = base10(a,i);
            v = base10(b,i);
            w = base10(c,i);
            if (u+v==w){
                printf("%d\n", i);
                f=1;
                break;
            }
        }
        if(!f)printf("0\n");
    }
}