#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>

#define REP(i,n) for(int i=0; i<n; ++i)
using namespace std;
string A[1001];
int main(){
    char C[31];
    int a;
    while(scanf("%d", &a), a){
        REP(i, a) {scanf("%s", C); A[i] = C;}
        sort(A, A+a);

        int i=0;
        while(i<A[a/2-1].size() &&  (A[a/2-1][i]==A[a/2][i] || A[a/2-1][i]=='Z'))
        {
            printf("%c", A[a/2-1][i]);
            i++;
        }
        if(i!=A[a/2-1].size()){
            if(i+1!=A[a/2].size() || A[a/2][i]!=A[a/2-1][i]+1 || A[a/2-1].size()==i+1)
                printf("%c\n", A[a/2-1][i]+(i+1!=A[a/2-1].size()));
            else{
                printf("%c", A[a/2-1][i++]);
                while(i<A[a/2-1].size() && A[a/2-1][i]=='Z')
                    printf("%c", A[a/2-1][i++]);
                if(i!=A[a/2-1].size())
                    printf("%c", A[a/2-1][i]+(i+1!=A[a/2-1].size()));
                printf("\n");
            }
        }
        else printf("\n");

    }
}