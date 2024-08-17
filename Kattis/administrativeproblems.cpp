#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int A[24];
#define REP(i,n) for(int i=0;i<(n);++i)

typedef struct {
    long long value;
    string car;
    bool err;
} spy;

typedef struct {
    int cat,pick, perkm;
}car;

char name[41], temp[41];

int main(){
    int T,h,d,n,m,c,p,k;
    char tp;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &n,&m);
        map<string, spy >mp;
        map<string, car>cars;
        REP(i,n) scanf("%s %d %d %d", name,&c,&p,&k), cars[name]={c,p,k};
        REP(i,m){
            scanf("%d %s %c %s%*c", &c, name, &tp, temp);
            if(tp=='p') {
                if(mp[name].car.empty()&&!mp[name].err) mp[name].car=temp;
                else mp[name].err=true;
            }
            else if(tp=='r') {
                if(mp[name].car.empty()||mp[name].err)mp[name].err=true;
                else {
                    mp[name].value+=cars[mp[name].car].pick+cars[mp[name].car].perkm*strtol(temp, nullptr,10);
                    mp[name].car="";
                }
            }
            else {
                if(mp[name].car.empty()||mp[name].err)mp[name].err=true;
                else{
                    mp[name].value+=ceil(cars[mp[name].car].cat*strtol(temp,nullptr, 10)/100.0);
                }
            };
        }

        for(auto & it : mp){
            if(it.second.err || !it.second.car.empty()) printf("%s INCONSISTENT\n", it.first.c_str());
            else printf("%s %lld\n", it.first.c_str(), it.second.value);
        }
    }
}