#include <iostream>
#include <cstring>
using namespace std;

char line[201];

int freq[26];
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        memset(freq, 0, sizeof freq);
        scanf(" %[^\n]", line);
        int max = 0, l= strlen(line);
        for(int i=0;i<l;i++){
            if(line[i]<='z'&&line[i]>='a')
                freq[line[i]-'a']++;
            else if(line[i]<='Z'&&line[i]>='A')
                freq[line[i]-'A']++;
        }
        for(int i : freq){
            if(max<i){
                max = i;
            }
        }
        for(int i=0;i<26;i++)if(freq[i]==max)printf("%c", i+'a');
        printf("\n");
    }
}