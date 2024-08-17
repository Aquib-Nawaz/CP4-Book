#include <iostream>
#include <string>
using namespace std;

string A[100];
int O[100];

int main(){
    char c=0;
    int k=0,n;
    while(c!='\n')scanf("%*s%c",&c),k++;
    scanf("%d ",&n);
    for(int i=0;i<n;i++)getline(cin,A[i]);
    for(int i=0;i<n;i++){
        int res=0;
        for(int j=n-i;j<=n;j++)res = (res+k-1)%j+1;
        O[i]=res-1;
    }
    printf("%d\n",(n+1)>>1);
    for(int i=0;i<n;i+=2){
        printf("%s\n", A[O[i]].c_str());
    }
    printf("%d\n",n>>1);
    for(int i=1;i<n;i+=2){
        printf("%s\n", A[O[i]].c_str());
    }
}