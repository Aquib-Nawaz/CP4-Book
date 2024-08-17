#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int A[24];
#define REP(i,n) for(int i=0;i<(n);++i)

typedef struct {
    int d;
    bool entry;
} vehicle;

char number[21], type[10],tim[20];

int main(){
    int T,h,d;
    char c;
    scanf("%d", &T);
    while(T--){
        map<string, map<string,vehicle> >mp;
        REP(i,24) scanf(" %d%*c", &A[i]);
        while(scanf("%c",&c)!=-1&&c!='\n'){
            ungetc(c,stdin);
            scanf("%s %s %s %d%*c", number, tim, type, &d);
            mp[number].insert({tim, {d, type[1]=='n'}});
        }
        for(auto & it : mp){
            double value=0; int entry=-1 ,t;
            for(auto &it1: it.second){
                if(it1.second.entry){
                    entry=it1.second.d;
                    t = 10*(it1.first[6]-'0')+it1.first[7]-'0';
                }
                else if(entry!=-1){
                    value+=100+A[t]*abs(it1.second.d-entry);
                    entry=-1;
                }
            }
            if(value==0) continue;
            value+=200;
            printf("%s $%.2lf\n", it.first.c_str(),value/100);
        }
        if(T) printf("\n");
    }
}