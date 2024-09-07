#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    vector<int>v;
    while (T--){
        int n;
        scanf("%d", &n);
        v.resize(n);
        bool isArithemtic = true;
        for(int i=0;i<n;i++)scanf("%d", &v[i]), isArithemtic &= (i==0 || v[i]-v[i-1]==v[1]-v[0]);
        if(isArithemtic){
            printf("arithmetic\n");
            continue;
        }
        sort(v.begin(), v.end());
        isArithemtic = true;
        for(int i=2;i<n;i++) isArithemtic &=  v[i]-v[i-1]==v[1]-v[0];
        if(isArithemtic){
            printf("permuted arithmetic\n");
            continue;
        }
        printf("non-arithmetic\n");
    }
}