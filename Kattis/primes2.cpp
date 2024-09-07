#include <iostream>
#include <string>
using namespace std;
#define MAX 1<<20
bool arr[MAX];
int primes[1000000],cnt;

void sieve(){
    cnt=0;
    for(bool & i : arr)i=true;
    for(int i=2;i*i<MAX;i++){
        if(arr[i]){
            for(int j=i*i;j<MAX;j+=i)arr[j]=false;
        }
    }
    arr[0]=arr[1]=false;
    primes[cnt++]=2;
    for(int i=3;i<1<<20;i+=2)
        if(arr[i])primes[cnt++]=i;
}

bool isPrime(long long n){
    if(n<2)return false;
    for(int i=0;i<cnt&&(long long)primes[i]*primes[i]<=n;i++){
        if(n%primes[i]==0)return false;
    }
    return true;
}

int val(char c){
    return c<='9'?c-'0':c-'A'+10;
}

int getMax(string &s){
    int ret=0;
    for(char i : s){
        ret = max(ret, val(i));
    }
    return ret;
}

long long convertToBase(string &s, int b) {
    long long ret = 0;
    for (char i : s) {
        ret = ret*b + val(i);
    }
    return ret;
}

int base[] = {2,8,10,16};

int main(){
    int T;
    scanf("%d", &T);
    string s;
    sieve();
    while (T--){
        cin >> s;
        int v = getMax(s);
        int t=0,p=0;
        for(int i : base){
            if(i>v){
                t++;
                p += isPrime(convertToBase(s, i));
            }
        }
        if(p==0)t=1;
        else if(t%p==0)t/=p,p=1;
        printf("%d/%d\n",p,t);
    }
}