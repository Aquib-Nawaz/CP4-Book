#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<int,int>pi;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

vector<int>coprimes[1001];

int help(int x, int i, int n){
    return lower_bound(coprimes[i].begin(), coprimes[i].end(), ceil(x*i*1.0/n))-coprimes[i].begin();
}

int f(int x, int n){
    int ret=0;
    for(int i=1;i<=n;i++){
        ret+= help(x,i,n);
    }
    return ret;
}
//find x such that f(x,n)<k<=f(x+1,n)
int binarysearch(int n, int k){
    int lo=1,hi=n;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(f(mid,n)<k) lo=mid;
        else hi=mid-1;
    }
    if(lo!=hi && f(hi,n)<k)lo=hi;
    return lo;
}

int main(){
    for(int i=1;i<1001;i++){
        for(int j=1;j<=i;j++){
            if(gcd(i,j)==1) coprimes[i].push_back(j);
        }
    }
    int n,k;
    while (scanf("%d%d", &n,&k)==2){
        int x = binarysearch(n,k);

        vector<pi>candidates;
        for(int i=1,t;i<=n;i++){
            t = help(x,i,n);
            if(t!=coprimes[i].size()){
                candidates.push_back({coprimes[i][t],i});
            }
        }
        sort(candidates.begin(), candidates.end(), [](pi a, pi b)
        {return a.first*b.second < b.first*a.second;});
        int rem = k-f(x,n)-1;
        printf("%d/%d\n", candidates[rem].first, candidates[rem].second);
    }
    // k/i > x/N => k> x*i/N
}