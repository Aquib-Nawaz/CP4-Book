#include <iostream>
#include <vector>
using namespace std;

int k,n,m,u,v,d,z;

typedef struct {
    int s,d,c;
}flight;
int P[9][12];

vector<flight> flights[8];
int main(){
    scanf("%d %d %d", &k,&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d %d %d", &u,&v,&d,&z);
        d--;u--;v--;
        flights[d].push_back({u,v,z});
    }
    for(int i=0;i<k*n;i++){
        scanf("%d %d %d", &u ,&d, &z);
        d--;u--;
        P[d][u]=z;
    }
    for(int i=0;i<n;i++){
        for(auto &fl:flights[i]){
            if(P[i][fl.s]<fl.c){
                printf("suboptimal\n");
                return 0;
            }
            P[i][fl.s]-=fl.c;
            P[i+1][fl.d]+=fl.c;
        }
        for(int j=0;j<k;j++){
            P[i+1][j]+=P[i][j];
        }
    }
    printf("optimal\n");

}