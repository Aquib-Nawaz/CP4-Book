#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <sstream>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
vector<int>A[101][10];
int C[101][10];
struct student{int id=0, s=0,p=0; };
struct st_comparator{
    bool operator()(struct student a, struct student b){
        if(a.s != b.s) return a.s > b.s;
        if(a.p != b.p) return a.p < b.p;
        return a.id < b.id;
    }
};
char L[101];
bool submitted[101];
int main(){
    int d,a,b,c;
    char v,n;
    scanf("%d\n\n", &d);
    string submission;
    while(d--) {
        memset(C, -1, sizeof C);
        memset(submitted, 0, sizeof submitted);
        REP(i,101)REP(j,10)A[i][j].clear();

        while(getline(cin, submission) && submission.length() != 0)
        {
            istringstream in(submission);
            in >> a >> b >> c >> v;
            submitted[a] = true;
            if(v=='C') {
                if(C[a][b]==-1||C[a][b]>c)
                    C[a][b] = c;
            } else if(v=='I') {
                A[a][b].push_back(c);
            }
        }
        vector<student>res;
        REP(i,101)if(submitted[i]){
            struct student st;
            st.id=i;
            REP(j,10)if(C[i][j]!=-1){
                for(int it :A[i][j])if(it<=C[i][j])st.p+=20;
                st.p+=C[i][j];
                st.s++;
            }
            res.push_back(st);
        }
        sort (res.begin(), res.end(), st_comparator());
        REP(i,res.size())printf("%d %d %d\n", res[i].id, res[i].s, res[i].p);
        if(d!=0)printf("\n");
    }

}