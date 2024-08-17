#include <iostream>
#include <set>
#include <cstring>
using namespace std;

int A[200002], B[200000];

int main(){
    int n,d;
    scanf("%d", &n);
    memset(A,0,(n+2)*sizeof A[0]);
    for(int i=0;i<n;i++){
        A[i+1]++;
        scanf("%d", &B[i]);
        A[B[i]]++;
    }
    if(A[n+1]==0){printf("Error\n"); return 0;}
    set<int>st;
    for(int i=1;i<=n;i++)if(A[i]==1)st.insert(i);
    for(int i=0;i<n;i++){
        if(st.empty()){printf("Error\n"); return 0;}
        int x=*st.begin();
        st.erase(x);
        A[B[i]]--;
        if(A[B[i]]==1)st.insert(B[i]);
        B[i]=x;
        A[x]=0;
    }
    for(int i=0;i<n;i++)printf("%d\n",B[i]);

}