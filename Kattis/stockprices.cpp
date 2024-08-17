#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
char order[5];
int main(){
    int T,n, p,num,st;
    scanf("%d", &T);
    while(T--){
        st=-1;
        scanf("%d", &n);
        priority_queue<pair<int,int>>pqb;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pqa;
        while(n--){
            scanf("%s %d %*s %*s %d", order, &num, &p);
            if(order[0] == 'b'){
                pqb.emplace(p,num);
            }
            else{
                pqa.emplace(p,num);
            }

            while(!pqa.empty() && !pqb.empty() && pqa.top().first<=pqb.top().first){
                auto pa=pqa.top(),pb=pqb.top();
                pqa.pop(); pqb.pop();
                st = pa.first;
                if(pa.second<pb.second){pb.second-=pa.second; pqb.push(pb);}
                else if(pb.second<pa.second){pa.second-=pb.second; pqa.push(pa);}
            }

            if(pqa.empty())printf("- ");
            else printf("%d ", pqa.top().first);
            if(pqb.empty())printf("- ");
            else printf("%d ", pqb.top().first);
            if(st==-1)printf("-");
            else printf("%d", st);
            if(T!=0||n!=0)printf("\n");
        }
    }
}