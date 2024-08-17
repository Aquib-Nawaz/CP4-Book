#include <iostream>
#include <unordered_map>
#include <string>
#include <cstring>
using namespace std;

unordered_map<string, int>mp;
typedef long long ll;
int n,m,e,A[1000];
int dp[1000][1000];
char names[100];
bool affect[1000][1000];

struct power{
    int a,c;
}arr[1000];

int solve(int i, int j){
    if(i==m)return 0;
    if(n-j<m-i)return e+1;
    int &ret = dp[i][j];
    if(ret!=-1)return ret;
    ret = e+1;
    if(affect[i][j] && A[i]<=arr[j].a){
        ret = min(ret, arr[j].c + solve(i+1,j+1));
    }
    ret = min(ret, solve(i,j+1));
    return ret;
}

int main(){
    char c;
    while(scanf("%d%d%d", &n,&m,&e),n||m||e){
        mp.clear();
        for(int i=0;i<n;i++){
            scanf("%s%d%d", names, &arr[i].a, &arr[i].c);
            mp[string(names)] = i;
        }
        for(int i=0;i<m;i++){
            memset(affect[i], 0, sizeof affect[i]);
            memset(dp[i], -1, sizeof dp[i]);
            scanf("%*s %d", &A[i]);
            do{
                scanf(" %[^,\n]%c", names, &c);
                affect[i][mp[string(names)]] = 1;
            }
            while(c!='\n');
        }
        int ans = solve(0,0);
        if(ans>e)printf("No\n");
        else printf("Yes\n");
    }
}