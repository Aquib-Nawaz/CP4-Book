#include <iostream>
#include <cstring>
using namespace std;

char line[51];
int main(){
    int n,l,a,b,c;
    scanf("%d", &n);
    while(n--){
        scanf("%s", line);
        l = strlen(line);
        a = b = c = 0;
        int i=0;
        for(i = 0; i < l && line[i]!='M'; i++){
            if(line[i] == '?') a++;
        }
        for(i=i+1;i<l&&line[i]!='E'; i++)
            if(line[i] == '?') b++;
        for(i=i+1;i<l; i++)
            if(line[i] == '?') c++;
        if(a==0||b==0||a+b!=c||a+b+c!=l-2)
            printf("no-theorem\n");
        else printf("theorem\n");
    }
}