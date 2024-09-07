#include <iostream>
using namespace std;

bool special(char c){
    return c<='*'&&c>='!' || c<=']'&&c>='[';
}

int main(){
    int n;
    string s;
    while (scanf("%d ", &n)==1){
        getline(cin,s);
        string escape((1<<n)-1, '\\');
        for(char c:s){
            if(special(c))
                cout << escape;
            cout << c;
        }
        cout << endl;
    }
}