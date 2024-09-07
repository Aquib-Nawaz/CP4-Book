#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    int j,C=0;
    while (scanf("%d",&j),j!=-1) {
        string s;
        cin >> s;
        s = s.substr(2);
        int lhs = strtol(s.substr(0,s.size()-j).c_str(), NULL, 10);
        int rhs = strtol(s.substr(s.size()-j).c_str(), NULL, 10);
        int lpo=pow(10,s.size()-j), rpo = pow(10,j)-1;
        int num = lhs*rpo+rhs, den = lpo*rpo;
        if(rpo==0)num=lhs,den=lpo;
        int g = gcd(num,den);
        printf("Case %d: %d/%d\n",++C, num/g,den/g);
    }
}