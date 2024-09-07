#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[1000];
int main(){
    int n;
    while (scanf("%d", &n) , n){
        double d;
        int sum =0,ans=0;
        for(int i=0;i<n;i++)scanf("%lf", &d), arr[i]=(int)round(d*100), sum+=arr[i];
        sort(arr, arr+n, greater<int>());
        int k=sum%n,l=sum/n;
        for(int i=0;i<n&&arr[i]>l+(i<k);i++)ans+=arr[i]-l-(i<k);
        printf("$%.2lf\n", ans/100.0);
    }
}