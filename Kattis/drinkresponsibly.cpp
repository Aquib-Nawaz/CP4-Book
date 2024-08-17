#include <iostream>
#include <string>
using namespace std;

int myround(double x, int y){
    return (int )(x*y+1e-10);
}
int M,U,d;
int par[8][121][1001];

struct drink{
    int cost, st;
    string name;
}arr[8];
char s[21];
int main(){
    double m,u;
    scanf("%lf%lf%d", &m,&u,&d);
    M = myround(m,100);
    U = myround(u,10);
    if(U%5!=0){
        printf("IMPOSSIBLE\n");
        return 0;
    }
    U = (U/10)*6 + (U%10==5)*3;
    for(int i=0;i<d;i++){
        int a,b;
        scanf("%s %d 1/%d %lf", s,&a,&b,&m);
        arr[i].name = s;
        arr[i].st = a*6/b;
        arr[i].cost = myround(m,100);
    }
    for(int i=0;i<d;i++)for(int j=0;j<=U;j++)for(int k=0;k<=M;k++)par[i][j][k]=-1;
    for(int i=0;arr[0].cost*i<=M && arr[0].st*i<=U;i++)par[0][arr[0].st*i][arr[0].cost*i]=i;
    for(int i=1;i<d;i++){
        for(int j=0;j<=U;j++){
            for(int k=0;k<=M;k++){
                if(par[i-1][j][k]==-1)continue;
                for(int l=0;k+l*arr[i].cost<=M && j+l*arr[i].st<=U;l++){
                    par[i][j+l*arr[i].st][k+l*arr[i].cost]=l;
                }
            }
        }
    }
    int ans=-1;
    for(int i=0;i<=M;i++)if(par[d-1][U][i]!=-1)ans=i;
    if(ans==-1)printf("IMPOSSIBLE\n");
    else {
        for(int i=d-1,l;i>=0;i--){
            l = par[i][U][ans];
            if(l!=0){
                ans -= l*arr[i].cost;
                U -= l*arr[i].st;
                printf("%s %d\n", arr[i].name.c_str(), l);
            }
        }
    }
    return 0;

}