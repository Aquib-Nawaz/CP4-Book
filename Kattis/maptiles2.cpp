#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int l=s.size(),x=0,y=0, p=(1<<(l-1));
    for(char c:s){
        if(c=='1'||c=='3')x+=p;
        if(c=='2'||c=='3')y+=p;
        p>>=1;
    }
    printf("%d %d %d\n", l,x,y);
}