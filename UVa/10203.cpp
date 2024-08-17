#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

typedef long double ld;

ld dist(int u1,int v1,int u2,int v2){
    return sqrt((ld)(u1-u2)*(u1-u2)+(ld)(v1-v2)*(v1-v2));
}

int main(){
    int T;
    scanf("%d ", &T);
    while (T--){
        string s;
        int u1,v1,u2,v2;
        scanf("%*d%*d ");
        ld d=0;
        while (getline(cin,s)){
            if(s=="")break;
            stringstream ss(s);
            ss>>u1>>v1>>u2>>v2;
            d+= dist(u1,v1,u2,v2);
        }
        int min=round(6*d/1000);
        printf("%d:%02d\n",min/60,min%60);
        if(T)printf("\n");
    }
}