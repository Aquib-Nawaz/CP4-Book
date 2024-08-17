#include <cstdio>
#include <cmath>
#include <deque>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int next(int a, const vector<bool>& C){
    for (int i=a+1; i<=52; i++){
        if(!C[i])
            return i;
    }
    return 53;
}
int func(int m, int v, int idx, int A[], int B[], const vector<bool>& C){

    if(idx==2){
        if(v==0)return 53;
        if(v==2)return next(0,C);
        return next(A[__builtin_ctz(m)], C);
    }
    int t = m, ans=1;
    while(t){
        int two_pow = t&-t;
        ans = max(ans,func(m^two_pow,A[__builtin_ctz(two_pow)]<B[idx]?v+1:v,idx+1 ,A,B,C));
        t-=two_pow;
    }
    return ans;
}
int main(){
    vector<bool> C;
    int A[3], B[2];
    while(scanf("%d %d %d %d %d",&A[0],&A[1],&A[2],&B[0], &B[1])) {
        if (A[0] == 0 && A[1] == 0 && A[2] == 0 && B[0] == 0 && B[1] == 0)
            break;
        C.clear();
        C.resize(53, false);
        for (int i = 0; i < 3; i++) {
            C[A[i]] = true;
        }
        for (int i = 0; i < 2; i++) {
            C[B[i]] = true;
        }
        int m = (1<<3)-1;
        int ret = func(m,0,0,A,B,C);
        int min = ret==53?-1:ret;
//        sort(A, A+3);
//        sort(B, B+2);
//        int min=-1;
//        if(B[0]>A[2]){min=next(0,C);}
//        else if(B[1]>A[2]&&B[0]>A[1]){min=next(A[1], C);}
//        else if(B[1]>A[2]&&B[0]<A[1]){min=next(A[2], C);}
//        else if(B[1]>A[1]&&B[0]>A[1]){min=next(A[1], C);}


        printf("%d\n", min);
    }
}