#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <set>
using namespace std;

char A[201];
int stack[10];
pair<int,int>brackets[10],temp[10],consec[10];

int main(){
    int n;
    scanf("%s", A);
    n= strlen(A);
    int k=0,cl=0;
    for(int i=0,j=0;i<n;i++){
        if(A[i]=='(')stack[j++]=i;
        else if(A[i]==')')brackets[k++]={stack[--j],i};
    }
    sort(brackets, brackets+k,[](pair<int,int>&a, pair<int,int>&b){return a.first>b.first;});
    temp[0]=brackets[0];
    for(int i=1,j=0;i<k;i++){
        if(brackets[i].first+1==temp[j].first&&brackets[i].second-1==temp[j].second)j++;
        else if(j!=0){
            consec[cl++]={i-j-1,j+1};
            j=0;
        }
        temp[j]=brackets[i];
    }
    set<string> ans;
    for(int i=1;i<1<<k;i++){
        bool err=false;
        for(int j=0;j<cl;j++){
            int t = (i>>consec[j].first)&(1<<consec[j].second)-1;
            t++;
            if((t&-t)!=t){err=true; break;}
        }
        if(err)continue;
        unordered_set<int>rem;
        for(int j=0,_i=i;_i;_i>>=1,j++)if(_i&1)rem.insert(brackets[j].first),rem.insert(brackets[j].second);
        string s;
        for(int j=0;j<n;j++)if(!rem.count(j))s+=A[j];
        ans.insert(s);
    }
    for(const string& s:ans)cout<<s<<endl;
    return 0;
}