#include <iostream>
using namespace std;

#define MAX 2000001
int numFactor[MAX];
int nums[MAX];
int counts[40];
void sieve() {
    int i, j, t;
    for (i = 1; i < MAX; i++) numFactor[i] = 1;
    for (i = 2; i < MAX/2; i++) {
        if (numFactor[i] == 1) {
            for (j = 2*i; j < MAX; j+=i) {
                t=j;
                while(t%i==0) t/=i, numFactor[j]++;
            }
        }
    }
    numFactor[0]=numFactor[1]=0;
    for (i = 0; i < 40; i++) counts[i]=0;
    for (i = 0; i < MAX; i++) counts[numFactor[i]]++;
    for (i = 1; i < 40; i++) counts[i]+=counts[i-1];
    for (i = MAX-1;i>0;i--) nums[counts[numFactor[i]]-1]=i,counts[numFactor[i]]--;
    //Write count sort based on numFactor for nums

}

int main() {
    int n,C=0;
    sieve();
    while (scanf("%d", &n),n) {
        printf("Case %d: %d\n", ++C, nums[n]);
    }
    return 0;
}