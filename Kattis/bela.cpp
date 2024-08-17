#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>
using namespace std;

int main(){
    int n;
    char c;
    scanf("%d %c\n", &n, &c);
    map<char, vector<int>>mp;
    mp['A'] = {11,11};
    mp['K'] = {4,4};
    mp['Q'] = {3,3};
    mp['J'] = {20,2};
    mp['T'] = {10,10};
    mp['9'] = {14,0};
    mp['8'] = {0,0};
    mp['7'] = {0,0};
    int ans=0;
    char card[2];
    for(int i=0; i<4*n; i++){
        scanf("%s", card);
        ans = ans + mp[card[0]][card[1]!=c];
    }
    printf("%d\n", ans);
}