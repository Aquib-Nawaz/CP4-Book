#include <cstdio>
#include <cmath>
#include <deque>
#include <stdlib.h>
#include <cstring>
#include <vector>
using namespace std;

int main(){
    int a,b;
    vector<int>A,B;
    while(scanf("%d %d", &a, &b), (a||b)){
        A.clear();B.clear();
        A.reserve(a);B.reserve(b);
        for(int i=0,t; i<a; i++){
            scanf("%d", &t);
            if(i>0&&t==A.back())
                continue;
            A.push_back(t);
        }
        for(int i=0,t; i<b; i++){
            scanf("%d", &t);
            if(i>0&&t==B.back())
                continue;
            B.push_back(t);
        }

        int av, bv;
        av=bv=0;
        int i,j;
        for(i=0,j=0; i<A.size()&&j<B.size(); i=i){
            if(A[i]==B[j]){
                i++;j++;
            }
            else if(A[i]<B[j]){
                av++;i++;
            }
            else{
                bv++;j++;
            }
        }
        if(i==A.size())
            bv+=(int)B.size()-j;
        else
            av+=(int)A.size()-i;
        printf("%d\n", av<bv?av:bv);
    }

}