#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define pb push_back
#define pp pop_back

bool card_eq(char const a[], char const b[]){
    return a[0] == b[0] || a[1] == b[1];
}
int main(){
    char card[3];
    while(scanf("%s", card), card[0] != '#') {
        vector<vector<string>>st;
        st.pb(vector<string>({card}));
        REP(i,51){
            scanf("%s", card);
            st.pb(vector<string>({card}));
            int cur = (int)st.size()-1;
            while(cur<st.size()){
                if(cur-3>=0 && card_eq(st[cur-3].back().c_str(), st[cur].back().c_str()) ) {
                    st[cur-3].emplace_back(st[cur].back());
                    st[cur].pp();
                    if(st[cur].empty())st.erase(st.begin()+cur);
                    cur-=3;
                }
                else if(cur-1>=0 && card_eq(st[cur-1].back().c_str(), st[cur].back().c_str())) {
                    st[cur-1].emplace_back(st[cur].back());
                    st[cur].pp();
                    if(st[cur].empty())st.erase(st.begin()+cur);
                    cur-=1;
                }
                else cur++;
            }
        }
        if(st.size()==1) printf("1 pile remaining: ");
        else printf("%d piles remaining: ", (int)st.size());
        REP(i, st.size()-1)printf("%d ", (int)st[i].size());
        printf("%d\n", (int)st[st.size()-1].size());
    }
}