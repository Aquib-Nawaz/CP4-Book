#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;

struct Node{
    Node *l,*r;
    ld f;

    explicit Node(ld f){
        this->l= nullptr;
        this->r= nullptr;
        this->f=f;
    }
};

struct Compare{
    bool operator()(const Node* lhs, const Node* rhs) const {
        return lhs->f>rhs->f;
    }
};

priority_queue<Node*, vector<Node*>, Compare>nd;

int main(){
    int n;
    double P[4];
    scanf("%d",&n);
    for(int i=0;i<4;i++)scanf("%lf",P+i);
    ll fac[21];
    fac[0]=1;
    for(int i=1;i<21;i++)fac[i]=fac[i-1]*i;
    ld ans=0;

    for(int i=0;i<=n;i++){
        for(int j=0;i+j<=n;j++)
            for(int k=0;i+j+k<=n;k++){
                ld v=(ld)fac[n]/(ld)(fac[i]*fac[j]*fac[k]*fac[n-i-j-k]);
                v*=pow(P[0],i)*pow(P[1],j)*pow(P[2],k)*pow(P[3],n-i-j-k);
                nd.push(new Node(v));
            }
    }
    while(nd.size()>1){
        Node*a=nd.top();
        nd.pop();
        Node*b=nd.top();
        nd.pop();
        Node*c=new Node(a->f+b->f);
        c->l=a;
        c->r=b;
        nd.push(c);
        ans+=c->f;
    }
    printf("%Lf",ans);
}