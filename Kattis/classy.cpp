#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
char name[31],cl[10],c;
struct person{
    string nm; long long vl;
};
struct person A[100];
int main(){
    int t,n;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &n);
        REP(i,n){
            scanf("%s ", name); name[strlen(name)-1]='\0'; A[i].nm = name;A[i].vl=0;
            long long pow=1; int j=0;
            while(true){
                scanf("%[^ -]%c", cl, &c);
                if(cl[0]=='u')A[i].vl+=pow*2;
                else if(cl[0]=='m')A[i].vl+=pow;
                pow*=3;
                j++;
                if(c==' '){scanf("%5s", cl); break;}
            }
            while(j++<10)A[i].vl=A[i].vl*3+1;
        }
        sort(A, A+n, [](const struct person& a, const struct person& b){if(a.vl==b.vl)
            return a.nm<b.nm; else return a.vl>b.vl;});
        REP(i,n)printf("%s\n", A[i].nm.c_str());
        REP(i,30)printf("=");
        printf("\n");
    }
}