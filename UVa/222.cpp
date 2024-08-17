#include <iostream>
#include <cmath>
using namespace std;
double ans,cur;
int n;
struct {
    double r, d;
}gas[52];
double d,c, m,r;

void solve(int l, double p){
    if(l==n+1){
        if(ans>cur||ans==-1)ans=cur;
        return;
    }
    p-=gas[l].d/m;
    if(p*m>=gas[l+1].d){
        solve(l+1,p);
    }
    if(p<c/2||p*m<gas[l+1].d){
        double t = round((c-p)*gas[l].r+200);
        cur+=t;
        solve(l+1,c);
        cur-=t;
    }
}

int main(){
    int C=0;
    while (scanf("%lf", &d), d>0){
        scanf("%lf %lf %lf %d", &c, &m, &r, &n);
        gas[0]={0,0};
        ans=-1;
        cur= round(r*100);
        for(int i=1;i<=n;i++)scanf("%lf %lf", &gas[i].d, &gas[i].r);
        gas[n+1]={0,d};
        for(int i=n+1;i>0;i--)gas[i].d-=gas[i-1].d;
        solve(1,c);
        printf("Data Set #%d\nminimum cost = $%.2lf\n",++C, ans/100);
    }
}