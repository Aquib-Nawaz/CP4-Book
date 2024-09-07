#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int getVal(char a){
    if(a<='9'&&a>='0')
        return a-'0';
    else
        return a-'A'+10;
}

char getChar(int v){
    if(v<10)return v+'0';
    return v-10+'A';
}

string baseb(string &a, int from, int to){
    if(a.size()>7||from<2||from>16||to<2||to>16)return "ERROR";
    int carry=0,pow=1,n=a.size();
    for(int i=n-1;i>=0;i--)carry+=getVal(a[i])*pow,pow*=from;
    string ret;
    pow=1;
    int x=0;
    while(pow*to<=carry&&x<=6)pow*=to,x++;
    if(x>6)return "ERROR";
    for(int i=x;i>=0;i--){
        ret.push_back(getChar(carry/pow)),carry%=pow;
        pow/=to;
    }
    return ret;
}

int main(){
    string num;
    int a,b;
    char l[10];
    while(scanf("%8s",l)==1){
        scanf("%d%d", &a,&b);
        num=l;
        string ans = baseb(num,a,b);
        ans = string(7-ans.size(),' ')+ans;
        cout<<ans<<endl;
    }
}