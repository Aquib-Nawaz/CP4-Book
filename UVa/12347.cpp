#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int inor[10000], preor[10000], prei=0;
unordered_map<int,int>mp;
void print(int inst, int inen){
    if(inst>inen)return;
    int root = mp[preor[prei++]];
    print(inst, root-1);
    print(root+1, inen);
    printf("%d\n", inor[root]);
}

int main() {
    int d,n=0;
    while (scanf("%d", &d)!=-1) inor[n]=preor[n]=d, n++;
    sort(inor, inor+n);
    for(int i=0;i<n;i++)mp[inor[i]]=i;
    print(0, n-1);
}
