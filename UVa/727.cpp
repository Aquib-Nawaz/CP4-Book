#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

unordered_map<char, char>mp = {{'*', 1},{'/', 1},{'+', 0},{'-', 0}};
int main(){
    int n, ret;
    scanf("%d\n", &n);
    char c;
    while(n--){
        bool f=true;
        stack<char>st;
        while(true){
            if(!f)ret=scanf("%*c");
            f=false;
            if(ret==-1 || scanf("%c", &c)==-1 || c=='\n' )break;
            if(c<='9'&&c>='0'){printf("%c",c); continue;}
            else if(c=='(')st.push(c);
            else if(c==')'){
                while(st.top()!='('){printf("%c",st.top()); st.pop();}
                st.pop();
            }
            else {
                while(!st.empty()&&st.top()!='('&&mp[c]<=mp[st.top()]){
                    printf("%c",st.top()); st.pop();
                }
                st.push(c);
            }
        }
        while(!st.empty()){printf("%c",st.top()); st.pop();}
        printf("\n");
        if(n!=0)printf("\n");
    }
}