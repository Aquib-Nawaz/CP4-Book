#include <iostream>
#include <cstring>
using namespace std;
char A[101],B[101];
int main(){
    int s1, s2, ans;
    bool err;
    while(scanf("%s %s", A, B)!=-1){
        s1= strlen(A), s2= strlen(B);
        ans=s1+s2;
        for(int l=0;l<s1+s2;l++){
            err= false;
            if(max(s1+s2, l+s1)-min(l,s1)>ans) break;
            for(int i=max(l, s1); i<min(s1+s2, l+s1); i++){
                if(A[i-l]=='2'&&B[i-s1]=='2'){err= true; break;}
            }
            if(!err){
                ans= max(s1+s2, l+s1)-min(l,s1);
            }
        }
        printf("%d\n" ,ans);
    }
}