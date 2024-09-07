#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int operation( int v, int w, char op){
    switch(op){
        case 'A': return v+w;
        case 'R': return w>>2;
        case 'L': return w<<2;
        case 'N': return w;
    }
    return -1;
}
unordered_map<char,int>mp={{'V',0},{'U',1},{'C',2},{'D',3}};
int getNum(string s){
    int b=4,po=1,ret=0;
    for(int i=s.size()-1;i>=0;i--){
        ret+=po*(mp[s[i]]);
        po*=b;
    }
    return ret;
}

int main(){
    int N,a,b;
    scanf("%d", &N);
    string num1,num2;
    char op;
    printf("COWCULATIONS OUTPUT\n");
    while(N--){
        cin >> num1 >> num2;
        a= getNum(num1),b= getNum(num2);
        for(int i=0;i<3;i++){
            cin >> op;
            b = operation(a,b,op);
        }
        cin >> num1;
        a = getNum(num1);
        printf("%s\n",a==b?"YES":"NO");
    }
    printf("END OF OUTPUT\n");
}