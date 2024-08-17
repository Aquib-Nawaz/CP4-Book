#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char tree[2][26];
int mp[26],prein;
queue<char>st;

void construct(int inst, int inen){
    if(inst>inen)return;
    int root=mp[tree[0][prein++]-'A'];
    construct(inst,root-1);
    construct(root+1,inen);
    st.push(tree[1][root]);
}

int main(){
    int l;
    while (scanf("%s%s", tree[0], tree[1])!=EOF){
        l= strlen(tree[1]);
        for (int i=0; i<l; i++) mp[tree[1][i]-'A']=i;
        prein=0;

        construct(0,l-1);
        while(!st.empty()){
            printf("%c",st.front());
            st.pop();
        }
        printf("\n");
    }
}