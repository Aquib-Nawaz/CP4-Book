//
// Created by Aquib Nawaz on 27/05/24.
//
#include <iostream>
#include<cstring>
using namespace std;

void target_finder(int al, int i, int j, const int ai[], const int aj[], char C[][8], bool f){
    for(int k=0;k<al;k++){
        int ti=i,tj=j;
        while(true){
            ti+=ai[k],tj+=aj[k];
            if(ti>=0&&ti<8&&tj>=0&&tj<8&&(C[ti][tj]==' '||C[ti][tj]=='x')) {
                C[ti][tj] = 'x';
            }
            else
                break;
            if(f)
                break;
        }
    }
}

int main(){
    char C[8][8];
    int di [] = {1,-1,1,-1}, dj [] = {1,1,-1,-1};
    int hi [] = {1,0,-1,0}, hj [] = {0,1,0,-1};

    int ni [] = {2,2,-2,-2, -1,1,1,-1}, nj [] = {1,-1,1,-1,
    2,2,-2,-2};
    int pi[] = {1,1},pj[]={1,-1};
    int Pi[] = {-1,-1},Pj[]={1,-1};


    char pos[100];
    while(scanf("%s",pos)!=EOF){

        for(int idx=0,i=0,j=0;  idx< strlen(pos); idx++){
            char c=pos[idx];
            if(c=='/'){
                i++;j=0;
                continue;}
            if(c<='9'&&c>='0'){
                for(int k=0;k<c-'0';k++)
                    C[i][j++]=' ';
            }
            else{
                if(c!='P'&&c<='Z')
                    c += -'A'+'a';
                C[i][j++]=c;
            }
        }
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(C[i][j]=='q'||C[i][j]=='b'||C[i][j]=='k'){
                    target_finder(4,i,j,di,dj,C,C[i][j]=='k');
                }
                if(C[i][j]=='q'||C[i][j]=='r'||C[i][j]=='k'){
                    target_finder(4,i,j,hi,hj,C,C[i][j]=='k');
                }

                if(C[i][j]=='n'){
                    target_finder(8,i,j,ni,nj,C, true);
                }

                if(C[i][j]=='p'){
                    target_finder(2,i,j,pi,pj,C, true);
                }
                if(C[i][j]=='P'){
                    target_finder(2,i,j,Pi,Pj,C, true);
                }
            }

        }
        int ans=0;
        for(int i=0;i<8;i++)
            for (int I = 0; I < 8; ++I) {
                if(C[i][I]==' ')
                    ans++;
            }
        printf("%d\n",ans);
    }
}