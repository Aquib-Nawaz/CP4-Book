#include <iostream>
#include <string>
#include <utility>
using namespace std;

pair<long long, long long> H(long long previousHash, string &transaction) {
    long long v = previousHash, token=0;
    for (int i = 0; i < transaction.length(); i++) {
        v = (v * 31 + transaction[i]) % 1000000007;
    }
    v = (v * 7 ) % 1000000007;
    int rem = v%((int)1e7);
    if(rem!=0){
        token+=1e7-rem;
        v+=token;
    }
    if(v%((int)1e8)==0)v+=1e8,token+=1e8;
    v%=1000000007;
    rem = v%((int)1e7);
    if(rem!=0){
        token+=1e7-rem;
        v+=token;
    }
    if(v%((int)1e8)==0)v+=1e8,token+=1e8;
    return make_pair(v, token);
}
string s1 = "i-paid-to-her-500-sgcoins", s2 = "she-paid-back-to-me-5000-sgcoins";

int main(){
    int pH;
    scanf("%d", &pH);
    auto ans = H(pH, s1);
    printf("%s %lld\n", s1.c_str(), ans.second);
    ans = H(ans.first, s2);
    printf("%s %lld\n", s2.c_str(), ans.second);
    return 0;

}