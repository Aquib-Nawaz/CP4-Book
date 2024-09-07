#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    long long a,b;
    while(scanf("%lld%lld", &a,&b),a){
        unordered_map<long long,int>mp;
        int s=0,_a=a,_b=b;
        while(a!=1){
            mp.insert({a,s});
            if(a%2==0)
                a/=2;
            else
                a=3*a+1;
            s++;
        }
        mp.insert({1,s});
        s=0;
        while(true){
            if(mp.count(b))break;
            if(b%2==0)
                b/=2;
            else
                b=3*b+1;
            s++;
        }
        printf("%d needs %d steps, %d needs %d steps, they meet at %lld\n", _a,mp[b],_b,s,b);
        fflush(stdout);
    }
}
