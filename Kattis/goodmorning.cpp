#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>A[10];

int gr(int a){if(a==0)return 3;return (a-1)/3;}
int gc(int a){if(a==0)return 1;return (a-1)%3;}

int main(){
    for(int i=0,cr,cc;i<=9;i++){
        cr = gr(i);
        cc = gc(i);
        for(int j=0;j<=9;j++)if(gr(j)>=cr&&gc(j)>=cc)A[i].push_back(j);
    }
    int T,n;
    scanf("%d",&T);
    while (T--){
        vector<int>num;
        int cur=0;
        scanf("%d",&n);
        int _n=n;
        while(_n)num.push_back(_n%10),_n/=10;
        reverse(num.begin(),num.end());
        cur=num[0];
        for(int i=1;i<num.size();i++){
            auto it =lower_bound(A[cur%10].begin(), A[cur%10].end(),num[i]);
            if(it!=A[cur%10].end()&&*it==num[i]){
                cur=cur*10+num[i];
                continue;
            }
            int t1=cur,t2=cur;
            if(it!=A[cur%10].end()){
                t1 = t1*10+*it;
                for(int j=i+1;j<num.size();j++)t1=t1*10+A[*it][0];
            }
            else{
                t1++;
                for(int j=i;j<num.size();j++)t1=t1*10+A[t1%10][0];
            }
            if(it!=A[cur%10].begin()){
                it--;
                t2 = t2*10+*it;
                for(int j=i+1;j<num.size();j++)t2=t2*10+A[*it].back();
            }
            else{
                t2--;
                for(int j=i;j<num.size();j++)t2=t2*10+A[t2%10].back();
            }
            if(t1-n>n-t2)cur=t2;
            else cur=t1;
            break;
        }
        printf("%d\n",cur);
    }
}