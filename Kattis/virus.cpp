#include<cstring>
#include <iostream>
using namespace std;

char A[100001],B[100001];

int main(){
    scanf("%s %s",A,B);
    int l,ra,rb;
    for(l=0,ra=strlen(A)-1,rb=strlen(B)-1;l<=ra && l<=rb;){
        if(A[l]==B[l])l++;
        else if(A[ra]==B[rb])ra--,rb--;
        else break;
    }
    printf("%d",rb-l+1);

}