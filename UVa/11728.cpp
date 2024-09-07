#include <iostream>
using namespace std;
int mp[1001];
int sumDiv(int N) {
    int ans = 1;                                    // start from ans = 1
    for (int i = 2; i*i<=N; ++i) {
        int multiplier = i, total = 1;
        while (N%i == 0) {
            N /= i;
            total += multiplier;
            multiplier *= i;
        }
        ans *= total;
    }
    if (N != 1) ans *= (N+1);
    return ans;
}


int main(){
    for(int i=0;i<1001;++i)mp[i]=-1;
    for(int i=1;i<1001;++i){
        int t= sumDiv(i);
        if(t<1001)mp[t]=i;
    }
    int n,C=0;
    while (scanf("%d",&n),n){
        printf("Case %d: %d\n",++C,mp[n]);
    }

}