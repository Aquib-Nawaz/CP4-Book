#include <iostream>
#include <cmath>
using namespace std;

int numDigit[210000], sz;

void init(){
    double lg = 0;
    sz=2;
    while(lg<1e6){
        lg+= log10(sz);
        numDigit[sz++]=(int)lg+1;
    }
}

int inverseFactorial(string &s){
    if(s.size()<=3){
        int i=stoi(s);
        switch(i){
            case 1: return 1;
            case 2: return 2;
            case 6: return 3;
            case 24: return 4;
            case 120: return 5;
            case 720: return 6;
            default: return -1;
        }
    }
    return lower_bound(numDigit+7, numDigit+sz, s.size()) - numDigit;

}

int main(){
    init();
    string s;
    cin>>s;
    cout<<inverseFactorial(s)<<endl;

}