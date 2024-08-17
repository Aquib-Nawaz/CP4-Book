#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(){
    int T,m,n,b,cost,k,d;
    scanf("%d", &T);
    string s,r;
    while(T--){
        cin.ignore();
        getline(cin,s);
        set<pair<int,string>>recipe;
        for(char c:s)
            printf("%c", c<='z'&&c>='a' ? c -'a'+'A': c);
        printf("\n");
        scanf("%d %d %d", &m,&n,&b);
        map<string,int>ingred;
        for(int i=0;i<m;i++){
            cin >>s >>cost;
            ingred[s]=cost;
        }
        for(int i=0;i<n;i++){
            cin.ignore();
            int co=0;
            getline(cin,s);
            cin >> k;
            for(int j=0;j<k;j++){cin >> r >>d;co+=ingred[r]*d;}
            if(co<=b)recipe.insert({co,s});
        }

        for(const auto & it : recipe)
            cout << it.second << endl;
        if(recipe.empty())printf("Too expensive!\n");
        printf("\n");
    }
}