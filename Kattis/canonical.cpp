#include <iostream>
using namespace std;

int arr[100], repr[2][100];

int greedy(int n, int v, int id=0){
    int ans=0;
    for(int i=0;i<n;i++)repr[id][i]=v/arr[i], ans+=repr[id][i], v%=arr[i];
    return ans;
}

int main(){
    int n,d;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",arr+n-i);
    bool can = true;
    for(int i=1;i<n;i++){
        greedy(n,arr[i-1]-1);
        int  counterex=0,num=0;
        for(int j=i;j<n;j++){
            counterex+=arr[j]*repr[0][j];
            num+=repr[0][j];
            if(greedy(n,counterex+arr[j],1)>num+1){
                can = false;
                break;
            }
        }
    }
    printf("%scanonical", can?"":"non-");
    return 0;

}