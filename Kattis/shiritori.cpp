#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    unordered_set<string> dict;
    char c=0;
    for(int i = 0; i < N; i++){
        string word;
        cin >> word;
        if(dict.find(word) != dict.end()||c!=0&&word.front()!=c){
            printf("Player %d lost", i%2 + 1);
            return 0;
        }

        dict.insert(word);
        c=word.back();
    }
    printf("Fair Game");
}