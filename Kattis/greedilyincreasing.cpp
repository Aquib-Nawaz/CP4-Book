#include<iostream>
#include <vector>
using namespace std;

int main(){
    int n,a,cur;
    scanf("%d %d", &n, &cur);
    vector<int>res;
    res.push_back(cur);
    for(int i=1;i<n;i++){
        scanf("%d", &a);
        if(a>cur){
            res.push_back(a);
            cur=a;
        }
    }
    printf("%ld\n",res.size());
    for(int i=0;i<res.size();i++){
        printf("%d", res[i]);
        if(i!=res.size()-1)
            printf(" ");
    }
    printf("\n");

}