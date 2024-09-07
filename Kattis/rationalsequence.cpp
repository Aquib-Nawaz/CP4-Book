#include <iostream>
using namespace std;

bool par(int &p, int &q){
    if(p<q){q=q-p;}
    else if(p>q){p=p-q;}
    else return false;
    return true;
}

void rch(int &p, int &q){
    p=p+q;
}

void lch(int &p, int &q){
    q=q+p;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n,p,q;
        scanf("%d %d/%d", &n, &p, &q);
        printf("%d ",n);
        if(p<q){ printf("%d/%d\n", q,q-p); }
        else if(q==1)printf("1/%d\n", p+1);
        else {
            int l=0;
            while(p>q)par(p,q),l++;
            par(p,q),l++;
            rch(p,q),l--;
            while(l)lch(p,q),l--;
            printf("%d/%d\n", p,q);
        }
    }
}