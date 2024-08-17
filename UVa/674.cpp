#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
ll dp[7490];
int main(){
    int arr[]= {50,25,10,5,1};
    int N;
    memset(dp,0,sizeof dp);
    dp[0]=1;
    for(int i=0;i<5;i++){
        for(int j=arr[i];j<7490;j++){
            dp[j]+=dp[j-arr[i]];
        }
    }
    while(cin>>N){
        cout << dp[N] << endl;
    }
}