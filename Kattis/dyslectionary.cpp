#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
pair<string,string> A[101];
int main(){
    int ret=0;
    char c;
    while(ret!=-1){
        int i=0,sz=0;
        while(true){
            A[i].first="";
            while(ret = scanf("%c", &c),ret!=-1&& c!='\n'){A[i].first.push_back(c);}
            if(ret==-1||A[i].first.empty())break;
            A[i].second=A[i].first;
            reverse(A[i].first.begin(),A[i].first.end());
            sz = max((int)A[i].first.size(), sz);
            i++;
        }
        sort(A,A+i );
        for(int j=0;j<i;j++)printf("%*s\n", sz, A[j].second.c_str());
        if(ret!=-1)printf("\n");
    }
}