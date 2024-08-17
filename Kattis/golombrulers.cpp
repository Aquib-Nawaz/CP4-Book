#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;
int A[25];
int main(){

    int d;
    char c;
    while(scanf("%d%c", &d ,&c)!=EOF) {
        int i=0;
        A[i++] = d;
        unordered_set<int>st;
        while(c!='\n'&&scanf("%d%c", &d, &c)!=EOF)A[i++]=d;
        sort(A,A+i);
        bool err=false;
        for(int j=0;j<i&&!err;j++){
            for(int k=j+1;k<i;k++){
                if(st.count(A[k]-A[j])){err=true;break;}
                st.insert(A[k]-A[j]);
            }
        }
        if(err){
            printf("not a ruler\n");
            continue;
        }
        for(int j=1;j<=A[i-1];j++){
            if(!st.count(j)){
                if(!err){
                    printf("missing");
                }
                err= true;
                printf(" %d",j);
            }
        }
        if(!err)printf("perfect");
        printf("\n");

    }
}