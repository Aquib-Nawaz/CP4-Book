#include <iostream>
#include <cmath>
using namespace std;

#define MAX 100001
int numDiv[MAX];
long long sumDiv[MAX];

void init(){
    for(int i = 1; i < MAX; i++){
        numDiv[i] = 1;
        sumDiv[i] = 1;
    }
    for(int i = 2; i < MAX; i++) {
        if (numDiv[i] == 1) {
            sumDiv[i] = i+1, numDiv[i] = 2;
            for (int j = 2 * i; j < MAX; j += i) {
                int count=1,_j=j,multiplier=i, s=1;
                while(_j%i==0){
                    count++;
                    _j/=i;
                    s+=multiplier;
                    multiplier*=i;
                }
                numDiv[j] *= count;
                sumDiv[j] *= s;
            }
        }
    }
}
int main(){
    int T;
    scanf("%d", &T);
    init();
    while(T--){
        int a,b,k;
        scanf("%d %d %d", &a, &b, &k);
        long long ans1=0, ans2=0;
        for(int i = k*ceil(a*1.0/k); i <= b; i+=k){
//            printf("%d %d %d\n", i, numDiv[i], sumDiv[i]);
            ans1 += numDiv[i];
            ans2 += sumDiv[i];
        }
        printf("%lld %lld\n", ans1, ans2);
    }
}