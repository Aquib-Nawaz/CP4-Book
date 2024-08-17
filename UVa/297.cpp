#include <iostream>
#include <assert.h>
using namespace std;

string a,b;

int count_quad(string &s, int &i, int le){
    if(s[i]=='e'){i++;return 0;}
    if(s[i]=='f'){i++;return le;}
    le/=4;
    i++;
    int ret=0;
    for(int j=0;j<4;j++)ret+=count_quad(s, i, le);
    return ret;
}

void skip_quad(string &s, int &i){
    if(s[i]=='e'||s[i]=='f'){i++; return;}
    i++;
    for(int j=0;j<4;j++)skip_quad(s, i);
}

int process_quad(int &i, int &j, int le){
    int ret=-1;
    if(a[i]=='e'&&b[j]=='e')ret=0;
    if(a[i]=='f'||b[j]=='f')ret = le;
    if(ret!=-1){
        skip_quad(a, i);
        skip_quad(b,j);
        return ret;
    }
    le/=4;
    ret=0;
    i++;
    j++;
    if(a[i-1]=='e'){
        for(int k=0;k<4;k++)
            ret+=count_quad(b,j,le);
        return ret;
    }
    if(b[j-1]=='e'){
        for(int k=0;k<4;k++)
            ret+=count_quad(a,i,le);
        return ret;
    }
    for(int k=0;k<4;k++){
        ret+=process_quad(i,j,le);
    }
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    while(n--){
        cin >> a >> b;
        int i=0,j=0;
        int ans = process_quad(i,j,1<<10);
        printf("There are %d black pixels.\n", ans);
    }

}