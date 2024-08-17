#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>

using namespace std;

char word[20];
unordered_map<char, int> m = {{'B',1}, {'F', 1}, {'P', 1}, {'V', 1}, {'C', 2},
                              {'G', 2}, {'J', 2}, {'K', 2}, {'Q', 2}, {'S', 2},
                              {'X', 2}, {'Z', 2}, {'D', 3}, {'T', 3}, {'L', 4},
                              {'M', 5}, {'N', 5}, {'R', 6}};

int main(){
    while(scanf("%s", word)!=EOF){
        vector<int>s;
        int n= strlen(word);
        for(int i=0;i<n;i++){
            if(m.count(word[i])!=0&&(s.empty()||m[word[i]]!=s.back())){
                s.push_back(m[word[i]]);
            }
            if(m.count(word[i])==0)
                s.push_back(-1);
        }
        for(int it: s)
            if(it!=-1)
            printf("%d", it);
        printf("\n");
    }
}