#include <iostream>
using namespace std;

int getType(char c){
    if(c<='9'&&c>='0') return 0;
    else if(c<='z'&&c>='a') return 1;
    return 2;
}
int getnum(char c){
    if(c<='9'&&c>='0') return c-'0';
    else if(c<='z'&&c>='a') return c-'a';
    return c-'A';
}
int base[]={10,26,26};
char getVal(int t, int n,bool carry=0){
    if(t==0)return '0'+n;
    else if(t==1)return 'a'+n-carry;
    else return 'A'+n-carry;
}

int main(){
    string a;
    int b;
    while(cin >> a){
        cin >> b;
        int n = a.length()-1;
        string s;
        while(b){
            int val=0,t;
            if(n>=0)val = getnum(a[n]), t=getType(a[n]);
            else t= getType(a[0]);
            b+=val;

            int d = b%base[t];
            b/=base[t];
            if(n<0 && d==0 && t!=0)d+=26,b--;
            s.push_back(getVal(t,d,n<0));
            if(n>=0)
            n--;
        }
        cout << a.substr(0,n+1);
        reverse(s.begin(),s.end());
        cout << s << endl;
    }
}