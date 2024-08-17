#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s,ans, t,t1;
    cin >> s;
    char c='z';
    for(char x:s)c = min(c,x);
    for(int i=1;i<s.size()-1;i++){
        if(s[i-1]!=c)continue;
        for(int j=i+1;j<s.size();j++){
            t = s.substr(0, i);
            std::reverse(t.begin(), t.end());
            t1 = s.substr(i, j-i);
            std::reverse(t1.begin(), t1.end());
            t += t1;
            t1=s.substr(j, s.size()-j);
            std::reverse(t1.begin(), t1.end());
            t += t1;
            if(ans.empty()|| t < ans){
                ans = t;
            }
        }
    }
    cout << ans << endl;
}