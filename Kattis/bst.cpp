#include <iostream>
#include <map>
using namespace std;

struct Node{
    int l=-1,r=-1,h=0;
};

int main(){
    int n,d;
    long long cnt=0;
    scanf("%d %d", &n, &d);
    map<int,struct Node> tree;
    tree[d]={.h=1};
    printf("0\n");
    for(int i=0;i<n-1;i++){
        scanf("%d", &d);
        auto it = tree.lower_bound(d);
        if(it!=tree.end()&&it->second.l==-1){
            it->second.l=d;
        }
        else{
            it--;
            it->second.r = d;
        }
        tree[d] = {.h=it->second.h+1};
        cnt+=it->second.h;
        printf("%lld\n", cnt);
    }

}