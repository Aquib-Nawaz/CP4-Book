#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
string binary(int n){
    string ret;
    while (n){
        ret .push_back(n&1?'1':'0');
        n >>= 1;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
int main(){
    int n;
    while (scanf("%d", &n),n){
        int p = __builtin_popcount(n);
        printf("The parity of %s is %d (mod 2).\n", binary(n).c_str(),p);
    }
}