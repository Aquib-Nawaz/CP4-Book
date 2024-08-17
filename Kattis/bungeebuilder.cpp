#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,c,m, ans=0, curr;
    scanf("%d", &n);
    scanf("%d", &curr);
    m=curr;
    for(int i=0;i<n-1;i++){
        scanf("%d", &c);
        m=min(m,c);
        ans=max(ans,min(c,curr)-m);
        if(c>curr)
            curr=c;
    }
    printf("%d", ans);
    return 0;
}