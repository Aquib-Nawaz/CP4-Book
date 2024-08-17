#include <iostream>
#include <string>
using namespace std;

bool check(string &x,string y){
    int i,j;
    for(i=j=0;i<x.size()&&j<y.size();j++){
        if(x[i]==y[j])i++;
    }
    return i==x.size();
}

int main(){
    string x,y;
    while(cin>>x>>y){
        printf("%s\n",check(x,y)?"Yes":"No");
    }
}