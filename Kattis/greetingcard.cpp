#include <iostream>
#include <utility>
#include <set>
#include <math.h>
using namespace std;

int main(){
    set<pair<int,int>> d;
    for(int i=0;i<=2018;i++){
        int jsq = 2018*2018-i*i;
        int rt = sqrt(jsq);
        if(rt*rt == jsq){
            d.insert({i,rt});
            if(i!=0)
            d.insert({i,-rt});
        }
    }
    int n;
    scanf("%d",&n);
    set<pair<int,int>>s;
    while(n--){
        int a,b;
        scanf("%d %d",&a,&b);
        s.insert({a,b});
    }
    int ans=0;
    for(auto p:s){
        for(auto diff:d)if(s.count({p.first+diff.first,p.second+diff.second})){
            ans++;
        }
    }
    printf("%d",ans);
}