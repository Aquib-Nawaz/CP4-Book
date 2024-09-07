#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int getval(char c){
    if(c>='0'&&c<='9')return c-'0';
    return c-'A'+10;
}

void printvec(vector<int>&a){
    for(int i=0;i<a.size()-1;i++)printf("%d ",a[i]);
    if(!a.empty())printf("%d\n",a.back());
}

vector<int>add(vector<int>&a, vector<int>&b, int base){
    vector<int>ret;
    int n1=a.size(),n2=b.size();
    int carry=0;
    while(n1||n2||carry){
        if(n1)carry+=a[--n1];
        if(n2)carry+=b[--n2];
        ret.push_back(carry%base);
        carry/=base;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

vector<int> multiply(vector<int>&a, vector<int>&b, int base){
    vector<int>ret,cur;
    int n1=a.size(),n2=b.size();
    int carry;
    for(int i=n1-1;i>=0;i--){
        carry=0;
        cur = vector<int>(n1-i-1,0);
        int m=a[i];
        for(int j=n2-1;j>=0;j--){
            carry+=m*b[j];
            cur.push_back(carry%base);
            carry/=base;
        }
        if(carry)cur.push_back(carry);
        reverse(cur.begin(),cur.end());
        ret=add(ret,cur,base);
    }
    return ret;
}

vector<int>inttovec(int a,int base=10){
    vector<int>ret;
    while (a)ret.push_back(a%base) ,a/=base;
    reverse(ret.begin(),ret.end());
    return ret;
}

vector<int> base10(string &a, int base){
    for(char c:a){
        if(getval(c)>=base)return {};
    }
    int n = a.size();
    vector<int>vbase= inttovec(base),pow(1,1),ret;
    while(n){
        n--;
        vector<int>t = inttovec(getval(a[n]));
        t = multiply(t,pow,10);
        ret=add(ret,t,10);
        pow=multiply(pow,vbase,10);
    }
    if(ret.empty())ret.push_back(0);
    return ret;
}

int main() {
    string a,b;
    while(cin >> a >> b) {
        map<vector<int>,int>mp;
        for(int i=2;i<=36;i++){
            vector<int>t= base10(a,i);
            if(!t.empty())mp.insert({t,i});
        }
        int i;
        for(i=2;i<=36;i++){
            vector<int>t = base10(b,i);
            if(mp.count(t)){
                printf("%s (base %d) = %s (base %d)\n",a.c_str(),mp[t],b.c_str(),i );
                break;
            }
        }
        if(i==37)printf("%s is not equal to %s in any base 2..36\n",a.c_str(),b.c_str());
    }
}