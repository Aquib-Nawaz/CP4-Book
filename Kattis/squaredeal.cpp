#include <iostream>
#include <algorithm>
using namespace std;

int X[3],Y[3];
int cur[3];

bool permute(){
    for(int i=0;i<3;i++)cur[i]=i;
    if(X[0]==X[1]&&X[1]==X[2]&&Y[0]+Y[1]+Y[2]==X[0]) return true;
    do{
        if(Y[cur[0]]==Y[cur[1]]&&X[cur[0]]+X[cur[1]]==X[cur[2]]&&Y[cur[1]]+Y[cur[2]]==X[cur[2]]) return true;
    }
    while(next_permutation(cur,cur+3));
    return false;
}


bool solve(int idx){
    if(permute())return true;
    for(int i=idx;i<3;i++){
        swap(X[i],Y[i]);
        if(solve(i+1))return true;
        swap(X[i],Y[i]);
    }
    return false;
}

int main(){
    for(int i=0;i<3;i++)scanf("%d %d",X+i,Y+i);
    printf("%s",solve(0)?"Yes":"No");
}