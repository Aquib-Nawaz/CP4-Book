#include <iostream>
#include <algorithm>
using namespace std;

int V[15];

int main(){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d", V+i);
    }
    sort(V,V+N);
    int ans=0,i;
    for(i=N-1;i>2;i-=2){
        int cur1 = V[i]+V[i-1]+2*V[0], cur2 = V[1]+V[0]+V[i]+V[1];
        ans+= min(cur1, cur2);
    }
    if(i==2) ans+=V[0]+V[1]+V[2];
    else ans+=V[i];
    printf("%d\n", ans);
}