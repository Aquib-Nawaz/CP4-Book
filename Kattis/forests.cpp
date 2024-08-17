#include <iostream>
#include <bitset>
#include <unordered_set>
using namespace std;

bitset<101>A[101];
int main(){
    int T,P,x,y;
    scanf("%d %d", &T, &P);
    unordered_set<bitset<101>>st;
    while(scanf("%d %d", &x,&y)!=-1)A[x][y]=1;
    for(int i=1;i<=T;i++)st.insert(A[i]);
    printf("%ld", st.size());
}