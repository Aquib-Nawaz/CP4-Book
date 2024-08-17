#include <iostream>
#include <algorithm>
using namespace std;

int A[5];
int res;
char cur[4],op[3]={'+','-','*'};

int _calc(int a, int b, char c){
    if(c=='+')return a+b;
    if(c=='-')return a-b;
    if(c=='*')return a*b;
    return 0;
}

bool calc(int id){

    if(id==4){
        res=A[0];
        for(int i=0;i<4;i++){
            res = _calc(res,A[i+1],cur[i]);
        }
        if(res==23)return true;
        return false;
    }
    for(char i : op){
        cur[id]=i;
        if(calc(id+1))return true;
    }
    return false;
}



int main(){
    while(true){
        bool f= false;
        for(int i=0;i<5;i++)scanf("%d",A+i);
        if(A[0]==0)break;
        sort(A,A+5);
        do{
            if(calc(0)){
                printf("Possible\n");
                f=true;
                break;
            }
        }while(next_permutation(A,A+5));
        if(!f)printf("Impossible\n");
    }

}