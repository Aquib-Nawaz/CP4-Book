#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
string attr[20];
vector<string>song[100];
unordered_map<string, int>mp;
char val[31];
int main(){
    int n_attr=0,N, q,o;
    char c=0;
    while(c!='\n'){
        while(scanf("%c", &c),c!=' '&&c!='\n')attr[n_attr].push_back(c);
        mp[attr[n_attr]] = n_attr;
        n_attr++;
    }
    scanf("%d", &N);
    string s;
    REP(i,N)REP(j,n_attr)scanf("%s", val), song[i].emplace_back(val);
    scanf("%d", &q);
    REP(i,q){
        scanf("%s", val), o=mp[val];
        stable_sort(song, song+N, [&o](const vector<string> &a, const vector<string> &b){
        return a[o] < b[o];});
        REP(j,n_attr){if(j!=0)printf(" "); printf("%s", attr[j].c_str());}
        printf("\n");
        REP(j,N){REP(k,n_attr){if(k!=0)printf(" "); printf("%s", song[j][k].c_str());}
        printf("\n");}
        if(i!=q-1)printf("\n");
    }
}