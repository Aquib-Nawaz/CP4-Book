#include <iostream>
using namespace std;

int main(){
    int a,b;
    scanf("%d %d", &a,&b);
    int lpo=1,rpo=1,lv=0,rv=0;
    while(a||b){
        int l=a%10,r=b%10;
        if(l>r)lv+=lpo*l, lpo*=10;
        else if(l<r)rv+=rpo*r, rpo*=10;
        else{
            lv+=lpo*l, lpo*=10;
            rv+=rpo*r, rpo*=10;
        }
        a/=10,b/=10;
    }
    if(lpo==1)printf("YODA\n");
    else printf("%d\n",lv);
    if(rpo==1)printf("YODA\n");
    else printf("%d\n",rv);
}