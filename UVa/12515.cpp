#include <iostream>
#include <cstring>
#include <bitset>
#include <climits>
using namespace std;
char A[1000][101], Q[101];
bitset<100>S, P;
int hamming(int i){
    int s = strlen(A[i]), s1= strlen(Q);
    int ans=INT_MAX;
    if(s1>s)return ans;
    S.reset();P.reset();
    for(int j=0;j<s1;j++)
        S[j] = A[i][j]-'0';
    for(int j=0;j<s1;j++)P[j]=Q[j]-'0';
    for(int j=s1;j<=s;j++){
        ans = min(ans, (int)(S^P).count());
        if(j!=s){S = S>>1; S[s1-1] = A[i][j]-'0';}
    }
    return ans;
}

int main(){
    int n,q, t;
    scanf("%d %d", &n ,&q);
    for(int i=0;i<n;i++)
        scanf("%s", A[i]);
    for(int i=0;i<q;i++){
        scanf("%s", Q);
        int ans=INT_MAX, idx=-1;
        for(int j=0;j<n;j++){
            t = hamming(j);
            if(t<ans){
                ans = t;
                idx = j+1;
            }
        }
        printf("%d\n", idx);
    }
}