#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

char cmd[100001];

int main(){
    int N,n,d;
    scanf("%d", &N);
    while(N--){
        deque<int>dq;
        scanf("%s %d [", cmd, &n);
        for(int i = 0; i < n; i++){
            scanf("%d%*c", &d);
            dq.push_back(d);
        }
        if(n==0)scanf("%*c");
        bool r=false, err=false;
        for(int i=0;i< strlen(cmd); i++){
            if(cmd[i]=='R') r=!r;
            else{
                if(dq.empty()){ err=true;break;}
                if(r) dq.pop_back();
                else dq.pop_front();
            }
        }
        if(err)printf("error");
        else{
            printf("[");
            for(int i=0;i<dq.size();i++){
                printf("%d", r?dq[dq.size()-1-i]:dq[i]);
                if(i!=dq.size()-1)printf(",");
            }
            printf("]");
        }
        if(N!=0)printf("\n");
    }
}