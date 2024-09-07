#include <iostream>
using namespace std;

long long base10(string s, int b){
    int n=s.size()-1,po=1;
    long long ret=0;
    while(n>=0){
        ret+=(s[n--]-'0')*po;
        po*=b;
    }
    return ret;
}

string to_string(long long v, int base){
    string ret;
    int po=1;
    while(v){
        ret+=(v%base+'0');
        v/=base;
        po*=base;
    }
    reverse(ret.begin(),ret.end());
    if(ret.empty())ret="0";
    return ret;
}

string modulo(string s, long long d,int base){
    long long ret=0,po=1;
    for(int i=s.size()-1;i>=0;i--){
        ret=(ret+(s[i]-'0')*po)%d;
        po = po*base%d;
    }
    return to_string(ret,base);
}

int main(){
    int b;
    string s1,s2;
    while (scanf("%d", &b),b){
        cin >> s1 >> s2;
        cout << modulo(s1,base10(s2,b),b) << endl;
    }

}