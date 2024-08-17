#include <cstdio>
#include <cmath>
#include <deque>
#include <stdlib.h>
#include <cstring>

using namespace std;

bool call(){
    return rand()/141%2;
}

void giveUp(deque<char>& s1, deque<char>& s2){
    while(!s2.empty()){
        s1.push_front(s2.back());
        s2.pop_back();
    }
}

void turnPile(deque<char>& s1, deque<char>& s2){
    while(!s2.empty()){
        s1.push_front(s2.front());
        s2.pop_front();
    }
}

void print(deque<char> s){
    while(!s.empty()){
        printf("%c", s.front());
        s.pop_front();
    }
    printf("\n");

}

int main(){
    int n;
    scanf("%d", &n);
    char jon[51];
    char jan[51];
    for(int i = 0; i < n; i++){
        scanf("\n");
        scanf("%s", jan);
        scanf("%s", jon);
        if(i!=0){
            printf("\n");
        }

        deque<char>janD,jonD,janU,jonU;
        for(int i=0;i< strlen(jan); i++){
            janD.push_back(jan[i]);
            jonD.push_back(jon[i]);
        }
        int rep=0;
        while(!janD.empty()&&!jonD.empty()){
            char ja = janD.front();
            char jo = jonD.front();
            janD.pop_front();
            jonD.pop_front();
            janU.push_front(ja);
            jonU.push_front(jo);
            if(ja==jo){
                if(!call()){
                    giveUp(janU, jonU);
                    printf("Snap! for Jane: ");
                    print(janU);
                    rep++;
                }
                else{
                    giveUp(jonU, janU);
                    printf("Snap! for John: ");
                    print(jonU);
                }
            }
            if(janD.empty()){
                turnPile(janD, janU);
            }
            if(jonD.empty()){
                turnPile(jonD, jonU);
            }
        }
        if(janD.empty()){
            printf("John wins.\n");
        }
        else{
            printf("Jane wins.\n");
        }
    }
}