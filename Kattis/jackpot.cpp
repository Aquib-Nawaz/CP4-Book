#include <iostream>
#include <string>
#include <sstream>
using namespace std;

long long gcd(long long a, long long b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    string s;
    while (getline(cin,s)){
        long long a=1;
        int b;
        stringstream ss(s);
        while(ss >> b){
            a/=gcd(a,b);
            a*=b;
        }

        printf("%lld\n", a);
    }
}