#include <iostream>
#include <stack>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
int A[1001];
int main(){
    int N,cur;
    while(scanf("%d", &N), N){
        while(scanf("%d", A),A[0]){
            stack<int> s;
            REP(i,N-1)scanf("%d", A+i+1);
            cur=1;
            int i=0;
            while(true){
                while(cur<=N && (s.empty()||s.top()!=A[i]))s.push(cur++);
                while(i<N && !s.empty() && s.top()==A[i])s.pop(),i++;
                if(i==N||cur==N+1)break;
            }
            printf("%s\n", i==N?"Yes":"No");
        }
        printf("\n");
    }
}