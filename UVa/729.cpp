#include <iostream>
#include <string>
using namespace std;

string cur;

void solve(int id, int n, int h){
    if(h==0){
        printf("%s\n",cur.c_str());
        return;
    }
    for(int i=id;n-i>=h;i++){
        cur[i] = '0';
        solve(i+1,n,h-1);
        cur[i] = '1';
    }

}

int main(){
    int T,n,h;
    scanf("%d",&T);
    while (T--){
        scanf("%d %d",&n,&h);
        h=n-h;
        cur = string (n,'1');
        solve(0,n,h);
        if(T!=0)printf("\n");
    }
}