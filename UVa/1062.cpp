#include <iostream>
#include <set>
using namespace std;

int main(){
    char c;
    int C=0;
    while(scanf("%c",&c),c!='e'){
        set<char>s;
        s.insert(c);
        while(scanf("%c", &c), c != '\n') {
            auto it = s.lower_bound(c);
            if(it!=s.end()&&*it!=c){
                s.erase(it);
                s.insert(c);
            }
            else if(it==s.end())
                s.insert(c);
        }
        printf("Case %d: %lu\n",++C, s.size());
    }
}