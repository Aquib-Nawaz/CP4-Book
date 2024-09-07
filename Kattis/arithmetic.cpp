#include <iostream>
#include <string>
using namespace std;

char getChar(int x){
    if(x<10)return x+'0';
    return x-10+'A';
}

string gethex(int v){
    string ret = "";
    ret+=getChar(v/256);
    v%=256;
    ret+=getChar(v/16);
    ret+=getChar(v%16);
    return ret;
}

int main(){
    string s,b;
    cin >> s;
    int n=s.size();
    s = string((4-n%4)%4,'0')+s;
    n=s.size();
    for(int i=0;i<n;i+=4){
        int v = (s[i]-'0')*512 + (s[i+1]-'0')*64 + (s[i+2]-'0')*8 + (s[i+3]-'0');
        b+=gethex(v);
    }
    int i=0;
    while(i<b.size()-1&&b[i]=='0')i++;
    cout << b.substr(i) << endl;
}