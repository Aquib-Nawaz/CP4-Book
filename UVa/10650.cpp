#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;

bool isPrime[32001];
int primes[10000];
int main(){
    int a,b,cnt=0;
    map<int, pair<int,int>>mp;
    for(int i=2;i<=32000;i++)isPrime[i]=true;
    for(int i=2;i<=32000;i++){
        if(isPrime[i]){
            primes[cnt++]=i;
            for(int j=2*i;j<=32000;j+=i){
                isPrime[j]=false;
            }
        }
    }
    int cur=0, diff=0;
    for(int i=1;i<cnt;i++){
        if(primes[i]-primes[i-1]==diff)cur++;
        else {
            if(cur>1) {
                mp[primes[i-cur-1]]={i-cur-1,cur+1};
            }
            diff = primes[i]-primes[i-1];
            cur=1;
        }
    }
    while (scanf("%d %d", &a,&b), a || b) {
        if(a>b)swap(a,b);
        auto it = mp.lower_bound(a);
        for(auto it1=it;it1!=mp.end() && primes[it1->second.first+it1->second.second-1]<=b;it1++){
            for(int i=0;i<it1->second.second-1;i++){
                printf("%d ", primes[i+it1->second.first]);
            }
            printf("%d\n", primes[it1->second.first+it1->second.second-1]);
        }
    }
}