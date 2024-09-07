#include <iostream>
using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        int cnt=0,mxcnt=0;
        for(char c:s){
            if(c==' ')cnt++;
            else mxcnt=max(mxcnt,cnt), cnt=0;
        }
        cout << 31-__builtin_clz(mxcnt) + ((mxcnt&-mxcnt)!=mxcnt) << endl;
    }
}

