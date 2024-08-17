#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace  std;
#define MAXN 51
int tot[MAXN], cura[MAXN];
int n,s,d,m,cur,k;

vector<int> poss;
void possible(){
    poss.clear();
    for(int i=1;i*i<=s;i++){
        if(s%i==0){
            poss.push_back(i);
            poss.push_back(s/i);
        }
    }
    sort(poss.begin(), poss.end());
}

bool check(int curidx, int cursum, int l, bool first){
    if(cursum==cur){
        if(l==k-2)return true;
        return check(MAXN-1, 0, l+1, true);
    }
    for(int i=curidx; i>0;i--){
        if(cura[i]==0)continue;
        if(cursum+i<=cur){
            cura[i]--;
            bool next = check(i, cursum+i, l, false);
            cura[i]++;
            if(next)return true;
        }
        if(first)return false;
    }
    return false;
}

int main(){
    while (scanf("%d",&n),n>0){
        s=0,m=0;
        memset(tot, 0, sizeof tot);
        for(int i=0;i<n;i++)scanf("%d",&d),tot[d]++,s+=d,m=max(m,d);
        possible();
        for(int i=0;i<poss.size();i++)
        {
            cur=poss[i];
            if(s%cur)continue;
            k=s/cur;
            memcpy(cura, tot, sizeof cura);
            if(k==1||check(MAXN-1,0,0,true)){
                printf("%d\n",cur);
                break;
            }
        }
    }
}