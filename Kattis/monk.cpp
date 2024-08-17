#include <iostream>
using namespace std;

int A[5001],B[5001], a,d;
int TA[5001],TB[5001];

double getV(double t, int arr[], int arr2[], int l){
    int idx = lower_bound(arr,arr+l,t)-arr;
    if(arr[idx]==t)return arr2[idx];
    double slope = (arr2[idx]-arr2[idx-1])*1.0/(arr[idx]-arr[idx-1]);
    return arr2[idx-1]+slope*(t-arr[idx-1]);
}

double f(double t){
    return A[a]-getV(t,TA,A,a)-getV(t,TB,B,d);
}

int main(){
    scanf("%d %d",&a,&d);
    A[0]=B[0]=TA[0]=TB[0]=0;
    for(int i=1;i<=a;i++)scanf("%d %d", A+i, TA+i),A[i]+=A[i-1],TA[i]+=TA[i-1];
    for(int i=1;i<=d;i++)scanf("%d %d", B+i, TB+i),B[i]+=B[i-1],TB[i]+=TB[i-1];
    double lo=0,hi=max(TA[a],TB[d]),ans,mid,v;
    while(hi-lo>1e-7){
        mid=(lo+hi)/2, v=f(mid);
        if(v>0)lo=mid;
        else hi=mid;
//        if(abs(v)<1e-9)ans=mid;
    }
    printf("%.6lf",lo);
}