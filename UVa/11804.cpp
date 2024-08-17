#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct {
    int a,d;
    string name;
} playa;

struct comparator{
    bool operator()(const playa& a,playa &b){
        if(a.a!=b.a)return a.a>b.a;
        if(a.d!=b.d)return a.d<b.d;
        return a.name<b.name;
    }
};

char name[21];

playa A[10];
#define REP(i,j,n) for( i=j;i<n;i++)
int main(){
    int t, C=0,i;
    scanf("%d", &t);

    while(C++<t){
        REP(i,0,10)scanf("%s %d %d", name, &A[i].a, &A[i].d), A[i].name=name;
        sort(A,A+10,comparator());
        sort(A,A+5,[](playa &a, playa &b){return a.name<b.name;});
        sort(A+5,A+10,[](playa &a, playa &b){return a.name<b.name;});
        printf("Case %d:\n", C);
        printf("(");
        REP(i,0,5){
            if(i!=0)printf(", ");
            printf("%s", A[i].name.c_str());
        }
        printf(")\n(");
        REP(i,5,10){
            if(i!=5)printf(", ");
            printf("%s", A[i].name.c_str());
        }
        printf(")\n");
    }
}