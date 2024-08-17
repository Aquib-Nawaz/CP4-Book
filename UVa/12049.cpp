#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    int T,ans,d;
    scanf("%d", &T);
    unordered_multiset<int>L,R;
    while(T--){
        ans=0;
        L.clear();
        R.clear();
        int n,m;
        scanf("%d %d", &n, &m);
        for(int i=0; i<n;i++){
            scanf("%d", &d);
            L.insert(d);
        }
        for(int i=0; i<m;i++){
            scanf("%d", &d);
            R.insert(d);
        }
        for(int it: L){
            if(R.find(it)!=R.end()){
                ans++;
                R.erase(R.find(it));
            }
        }
        printf("%d\n", n+m-2*ans);
    }
}