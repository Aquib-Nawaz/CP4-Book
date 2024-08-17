#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <utility>
#include <unordered_set>
using namespace std;

string groups[]  ={"A","B","AB","O"};
char signs[] = {'+','-'};
map<string,int>MP;
map<char, int>MP1;
unordered_set<int>s1[4],s2[2];

pair<int,int> getPalletes(char s[]){
    char * en;
    if((en=strchr(s, '+'))!= nullptr){
        *en='\0';
        return make_pair(MP[s], MP1['+']);
    }
    else if((en=strchr(s, '-'))!= nullptr){
        *en='\0';
        return make_pair(MP[s], MP1['-']);
    }
    return make_pair(-1,-1);
}

unordered_set<int> combine_s1(int a, int b){
    unordered_set<int>help;
    for(auto it:s1[a]){
        for(int it1 : s1[b]){
            if(it1==it || it1==3){
                help.insert(it);
            }
            else if(it==3)
                help.insert(it1);
            else
                help.insert(2);
        }
    }
    return help;
}

unordered_set<int> combine_s2(int a,int b){
    unordered_set<int>help;
    for(auto it=s2[a].begin(); it!=s2[a].end(); it++){
        for(int it1 : s2[b]){
            if(it1==*it ){
                help.insert(*it);
            }
            else
                help.insert(0);
        }
    }
    return help;
}
unordered_set<int>mp[4][4];
unordered_set<int>mp1[2][2];

unordered_set<int> diff_s1(int a, int b){
    unordered_set<int>ret;
    for(int i=0;i<4;i++)
        if(mp[a][i].find(b)!=mp[a][i].end())
            ret.insert(i);
    return ret;
}

unordered_set<int> diff_s2(int a, int b){
    unordered_set<int>ret;
    for(int i=0;i<2;i++)
        if(mp1[a][i].find(b)!=mp1[a][i].end())
            ret.insert(i);
    return ret;
}

void print(unordered_set<int>&p,unordered_set<int>&q){
    bool f=true;
    if(p.size()!=1||q.size()!=1)
        printf("{");
    for(int a:p){
        for(int b:q){
            if(!f)
                printf(", ");
            f=false;
            printf("%s%c", groups[a].c_str(), signs[b]);
        }
    }
    if(p.size()!=1||q.size()!=1)
        printf("}");
}

int main(){
    int C=1;
    for(int i=0; i<4; i++){
        MP[groups[i]]=i;
        if(i<2)
            MP1[signs[i]]=i;
    }
    s1[0].insert(0); s1[0].insert(3);
    s1[1].insert(1); s1[1].insert(3);
    s1[2].insert(0); s1[2].insert(1);
    s1[3].insert(3);
    s2[0].insert(0); s2[0].insert(1);
    s2[1].insert(1);

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            mp[i][j]=combine_s1(i,j);
        }
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            mp1[i][j]=combine_s2(i,j);
        }
    }

    char p1[4],p2[4],ch[4];

    while(scanf("%s %s %s",p1,p2,ch),p1[0]!='E') {
        printf("Case %d: ",C);
        C++;
        pair<int, int> p1_ = getPalletes(p1);
        pair<int, int> p2_ = getPalletes(p2);
        pair<int, int> ch_ = getPalletes(ch);

        if(p1_.first==-1){
            auto df1 = diff_s1(p2_.first, ch_.first);
            auto df2 = diff_s2(p2_.second, ch_.second);
            if(df1.empty()||df2.empty())
                printf("IMPOSSIBLE ");
            else{
                print(df1,df2);
                printf(" ");
            }
        }
        else {
            printf("%s%c ", groups[p1_.first].c_str(), signs[p1_.second]);
        }
        if(p2_.first==-1){
            auto df1 = diff_s1(p1_.first, ch_.first);
            auto df2 = diff_s2(p1_.second, ch_.second);
            if(df1.empty()||df2.empty())
                printf("IMPOSSIBLE ");
            else{
                print(df1,df2);
                printf(" ");
            }
        }
        else {
            printf("%s%c ", groups[p2_.first].c_str(), signs[p2_.second]);
        }
        if(ch_.first==-1){
            print(mp[p1_.first][p2_.first],
            mp1[p1_.second][p2_.second]);
            printf("\n");
        }
        else {
            printf("%s%c\n", groups[ch_.first].c_str(), signs[ch_.second]);
        }
    }

}