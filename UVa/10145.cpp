#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
using namespace std;
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        char c;
        int tr,dt;
        unordered_map<int, pair<unordered_set<int>,int>>lk;
        unordered_set<int>ign;
        while(scanf(" %c", &c),c!='#'){
            scanf("%d %d", &tr, &dt);
            if(ign.count(tr)){
                printf("IGNORED\n");
                continue;
            }

            if(c=='S'){
                if(!lk.count(dt)){
                    lk[dt].first.insert(tr);
                    lk[dt].second=-1;
                }
                else if(lk[dt].second==-1||lk[dt].second==tr){
                    lk[dt].first.insert(tr);
                }
                else {printf("DENIED\n"); ign.insert(tr);
                    continue;}
            }
            else{
                if(!lk.count(dt)){
                    lk[dt].second=tr;
                }
                else if(lk[dt].second==tr){
                }
                else if(lk[dt].second==-1 && (lk[dt].first.count(tr)&&lk[dt].first.size()==1)){
                    lk[dt].second=tr;
                }
                else {printf("DENIED\n"); ign.insert(tr);
                    continue;}
            }
            printf("GRANTED\n");
        }
        if(T!=0)
        printf("\n");
    }
}