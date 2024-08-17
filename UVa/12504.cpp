#include <map>
#include <iostream>
#include <cstring>

using namespace std;
char str[100],str1[100],c;

#define REP(i,n) for(int i=0;i<n;++i)


int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        map<string,string>mp[2];
        REP(i,2){
            scanf("%*c%*c");
            c=0;
            while(c!='}'&&scanf("%[^:}]:%[^},]%c", str, str1,&c)==3){
                mp[i][str]=str1;
            }
            if(c!='}')scanf("%*c");
        }
        char sign[2]={'+', '-'};
        bool chang=false;
        REP(j,2){
            bool f=1;
            for(const auto& i:mp[1-j]){
                if(mp[j].count(i.first)==0){
                    if(!f)printf(",");
                    else printf("%c", sign[j]);
                    f=0;
                    chang=1;
                    printf("%s",i.first.c_str());
                }
            }
            if(!f)printf("\n");
        }

        bool f=1;
        for(const auto& i:mp[1]){
            if(mp[0].count(i.first)&&mp[0][i.first]!=i.second){
                if(!f)printf(",");
                else printf("*");
                f=false;
                chang=true;
                printf("%s",i.first.c_str());
            }
        }
        if(!f)printf("\n");
        if(!chang)printf("No changes\n\n");
        else
        printf("\n");
    }
}