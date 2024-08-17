#include <iostream>
#include <string>
#include <unordered_set>
#include <cstring>
#include <unordered_map>
#include <vector>
using namespace std;
char word[151];

int main(){
    int t,C=0,ret;
    scanf("%d", &t);
    while(C++<t){
        printf("Document %d: ", C);
        vector<string >A;
        unordered_set<string>B;
        unordered_map<string,int>mp;
        int cnt=0;
        while(true){
            ret = scanf("%*[^a-zA-Z] %[a-zA-Z]", word);
            if(ret==0)continue;
            if(strcmp(word, "END")==0)break;
            A.push_back(word);
            B.insert(word);
        }
        int sz=B.size();
        B.clear();
        int ml=-1,mr,l=0;
        for(int r=0;r<A.size();r++){
            if(mp.find(A[r])==mp.end())cnt++,mp.insert({A[r],1});
            else mp[A[r]]++;
            while( mp[A[l]]>1){
                mp[A[l]]--;l++;
            }
            if(cnt==sz){
                if(ml==-1||r-l<mr-ml)ml=l,mr=r;
            }
        }
        printf("%d %d\n", ml+1, mr+1);
    }
}