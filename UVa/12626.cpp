#include <iostream>
#include <cstring>
using namespace std;

int getId(char c){
    if(c=='M')
        return 0;
    else if(c=='A')
        return 1;
    else if (c=='R')
        return 2;
    else if(c=='G')
        return 3;
    else if(c=='I')
        return 4;
    else if(c=='T')
        return 5;
    return 6;
}
int freq[7];
char line[601];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        memset(freq, 0, sizeof freq);
        scanf("%s", line);
        int l= strlen(line);
        for(int j=0;j<l;j++){
            freq[getId(line[j])]++;
        }
        int ans=n;
        for(int j=0;j<6;j++){
            if(j==1)
                ans = min(ans, freq[j]/3);
            else if(j==2)
                ans = min(ans, freq[j]/2);
            else ans = min(ans,freq[j]);
        }
        printf("%d\n", ans);
    }
}