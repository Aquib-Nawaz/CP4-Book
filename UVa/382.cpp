#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;

unordered_set<int>mp;

void find_factor(int d){
    for(int i=2;i<=sqrt(d);i++){
        if(d%i==0){
            mp.insert(i);
            mp.insert(d/i);
        }
    }
    if(d!=1)
        mp.insert(1);
    int sum=0;
    for(auto it:mp)sum+=it;
    if(sum==d)printf("%5d  PERFECT\n",d);
    else if(sum<d)printf("%5d  DEFICIENT\n",d);
    else printf("%5d  ABUNDANT\n",d);
    mp.clear();
}

int main(){
    printf("PERFECTION OUTPUT\n");
    int d;
    while(scanf("%d", &d),d){
        find_factor(d);
    }
    printf("END OF OUTPUT\n");
}