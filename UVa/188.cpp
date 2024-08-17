#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int A[13];
char W[6];
int main(){
    int ret=2,n,t;
    while(ret!=-1){
        char c=0;
        n=0;
        while(c!='\n'&&(ret=scanf("%s%c", W,&c))!=-1){
            A[n]=0;
            for(int i=0;i< strlen(W);i++)A[n]=A[n]<<5|W[i]-'a'+1;
            n++;
            printf("%s", W);
            if(ret==2)
                while(c==' '&&ret!=-1)printf("%c",c),ret = scanf("%c",&c);
            else {break;}
            if(ret!=-1&&c!='\n')ungetc(c,stdin);
        }
        if(n==0)break;
        long long C=0;
        bool ch;
        do{
            ch=false;
            unordered_map<int,vector<long long>>mp;
            for(int i=0;i<n;i++){
                t=(int)(C/A[i]%n);
                mp[t].push_back((C/A[i]+1)*A[i]);
            }
            for(auto &it:mp){
                if(it.second.size()==1)continue;
                std::sort(it.second.begin(), it.second.end());
                C = max(it.second[it.second.size()-2],C);
                ch=true;
            }
        }
        while(ch);
        printf("\n%lld\n\n",C);
    }

}