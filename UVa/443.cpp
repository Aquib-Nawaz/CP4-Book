#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

vector<long long>powv[4];

int num[]={2,3,5,7};
int main(){
    for(int i=0;i<4;i++){
        long long po=1;
        while(po<=2e9){
            powv[i].push_back(po);
            po*=num[i];
        }
    }
    unordered_map<int,int>m;
    set<int>st;
    for(int i=0;i<powv[0].size();i++){
        for(int j=0;j<powv[1].size()&&powv[0][i]*powv[1][j]<=2e9;j++){
            for(int k=0;k<powv[2].size()&&powv[0][i]*powv[1][j]*powv[2][k]<=2e9;k++){
                for(int l=0;l<powv[3].size()&&powv[0][i]*powv[1][j]*powv[2][k]*powv[3][l]<=2e9;l++){
                    st.insert(powv[0][i]*powv[1][j]*powv[2][k]*powv[3][l]);
                }
            }
        }
    }
    int i=0;
    for(auto it:st){
        m[++i]=it;
    }
    int n;
    while(scanf("%d", &n),n){
        printf("The %d%s humble number is %d.\n", n,(n%10>3||n%10==0 || n/10%10==1)?"th":n%10==1?"st":n%10==2?"nd":"rd" ,m[n]);
    }
}