#include <iostream>
#include <string>
using namespace std;

bool isFeasible(string &s, int st, int len){
    bool ret=true;
    for(int i=st+len;i<s.size();i++)
        ret&=s[i]==s[(i-st)%len+st];
    return ret;
}

int gcd(int a, int b){
    return b?gcd(b,a%b):a;
}

struct candidate{
    int num, den;
    bool operator<(const candidate &rhs) const{
        return den < rhs.den;
    }
}arr[100];

int main(){
    string s;
    while (cin >> s, s!="0"){
        while(s.back()=='.')s.pop_back();
        s = s.substr(s.find('.')+1);
        int lpo=1,cnt=0;

        for(int j=0;j<s.size();j++,lpo*=10){
            int lhs = strtol(s.substr(0,j).c_str(),NULL,10);
            int rpo=10;
            for(int i=1;i<=s.size()-j;i++,rpo*=10){
                if(!isFeasible(s,j,i))continue;
                int rhs = strtol(s.substr(j,i).c_str(),NULL,10);
                int num = lhs*(rpo-1)+rhs, den = lpo*(rpo-1), g = gcd(num, den);
                arr[cnt++] = {num/g,den/g};
            }
        }
        int ans=0;
        for(int i=0;i<cnt;i++)if(arr[i]<arr[ans])ans=i;
//        for(ans=0;ans<cnt;ans++)
        printf("%d/%d\n", arr[ans].num, arr[ans].den);
    }

}