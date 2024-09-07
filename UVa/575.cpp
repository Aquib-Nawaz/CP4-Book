#include <iostream>
using namespace std;

int main(){
    string s;
    while(cin>>s,s!="0"){
        int po = 2,ret=0;
        for(int i=s.size()-1;i>=0;i--){
            ret+=(s[i]-'0')*(po-1);
            po<<=1;
        }
        printf("%d\n",ret);
    }
}