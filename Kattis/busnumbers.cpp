#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){

    int N,d;
    scanf("%d", &N);
    priority_queue<int, vector<int>, greater<int>>st;
    for(int i=0; i<N;i++){
        scanf("%d",&d);
        st.push(d);
    }
    bool f=true;
    while(!st.empty()){
        d = st.top();
        st.pop();
        if(!f)printf(" ");
        f=false;
        int cnt=0;
        while(!st.empty()&&st.top()==d+cnt+1)
            cnt++,st.pop();
        printf("%d", d);
        if(cnt==0)continue;
        if(cnt==1)
            printf(" %d", d+1);
        else
            printf("-%d", d+cnt);
    }
}