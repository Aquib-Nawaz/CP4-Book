#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <cstring>
#include <utility>
using namespace std;

map<string,int>places;
string  names[100];
int n,curver[10],par[11][1<<10],homei, sz;
double dist[100][100], dp[11][1<<10];
pair<double,double> points[100];
char name[21];

double solve(int id, int pos, int mask){
    if(mask==0)return dist[pos][homei];
    double &ans=dp[id][mask];
    if(ans>0)return ans;
    ans=1e9;
    for(int i=0;i<sz;i++){
        if(mask&(1<<i)){
            if(ans>solve(i+1,curver[i],mask^(1<<i))+dist[pos][curver[i]]){
                ans = solve(i+1,curver[i],mask^(1<<i))+dist[pos][curver[i]];
                par[id][mask]=i+1;
            }
        }
    }
    return ans;
}

int main() {
    double x, y;
    scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %lf %lf ", name, &x, &y);
        places[name] = i;
        names[i] = name;
        points[i] = {x, y};
        dist[i][i] = 0;
    }
    homei = places["home"];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            dist[i][j] = dist[j][i] =
                    sqrt((points[i].first - points[j].first) * (points[i].first - points[j].first) +
                         (points[i].second - points[j].second) * (points[i].second - points[j].second));

    char c;
    int ret;
    do{
        sz=0;
        do{
            ret= scanf("%s%c", name, &c);
            curver[sz++]=places[name];
        }while(c!='\n' && ret==2);
        if(ret==-1)break;
        memset(dp,-1,sizeof dp);
        solve(0,places["work"],(1<<sz)-1);
        int mask = (1<<sz)-1;
        for(int i=0,v=par[0][mask];i<sz;i++){
            printf("%s", names[curver[v-1]].c_str());
            if(i==sz-1)printf("\n");
            else printf(" ");
            mask^=1<<(v-1);
            v=par[v][mask];
        }
    }while(true);
}