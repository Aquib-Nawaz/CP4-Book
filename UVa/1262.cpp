#include <iostream>
#include <set>
using namespace std;

char A[6][6],B[6][6];
set<char>st[5];
int main(){
    int T,k;
    scanf("%d",&T);

    while (T--){
        scanf("%d",&k);
        for(int i=0;i<6;i++)scanf("%s",A[i]);
        for(int i=0;i<6;i++)scanf("%s",B[i]);
        for(int i=0;i<5;i++){
            st[i].clear();
            for(int j=0;j<6;j++){
                for(int l=0;l<6;l++){
                    if(A[j][i]==B[l][i])st[i].insert(A[j][i]);
                }
            }
        }
        int mx = 1;
        for(int i=0;i<5;i++)mx*=st[i].size();
        if(k>mx){
            printf("NO\n");
            continue;
        }
        k--;
        for(int i=0;i<5;i++){
            mx/=st[i].size();
            auto it=st[i].begin();
            for(int j=0;j<k/mx;j++)it++;
            printf("%c",*it);
            k%=mx;
        }
        printf("\n");
    }


}