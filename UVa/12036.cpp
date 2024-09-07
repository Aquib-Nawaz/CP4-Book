#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int T,C=0;
    scanf("%d", &T);
    while(T--){
        int N,x;
        scanf("%d", &N);
        unordered_map<int, int> m;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                scanf("%d", &x), m[x]++;
        }
        bool f= true;
        for(auto it: m){
            f&=it.second<=N;
        }
        printf("Case %d: %s\n", ++C, f?"yes":"no");
    }
}