#include <iostream>
#include <string>
#include <set>
using namespace std;

char word[11];
int main(){
    set<string>s1,s2;
    while(scanf("%s", word) != EOF){
        s1.insert(word);
    }
    for(auto it=s1.begin();it!=s1.end(); it++){
        for(auto it1=s1.begin(); it1!=s1.end(); it1++){
            if(it==it1) continue;
            string temp = *it + *it1;
            s2.insert(temp);
        }
    }
    for(auto it=s2.begin(); it!=s2.end(); it++){
        printf("%s\n", it->c_str());
    }
}