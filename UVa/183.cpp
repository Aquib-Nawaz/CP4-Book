#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char l[51];

string s,ans;
int idx,N,M;

void fill(char v, int xlo, int xhi, int ylo, int yhi){
    for(int i=xlo;i<=xhi;i++)for(int j=ylo;j<=yhi;j++)ans[i*M+j]=v;
}

void DtoB(int xlo, int xhi, int ylo, int yhi){
    if(xlo>xhi||ylo>yhi||idx==s.length())return;
    if(s[idx]!='D'){
        fill(s[idx++], xlo, xhi, ylo, yhi);
        return;
    }
    idx++;
    int xm = (xlo+xhi)>>1, ym = (ylo+yhi)>>1;
    DtoB(xlo,xm,ylo,ym);
    DtoB(xlo,xm,ym+1,yhi);
    DtoB(xm+1,xhi,ylo,ym);
    DtoB(xm+1,xhi,ym+1,yhi);

}

char BtoD(int xlo, int xhi, int ylo, int yhi){
    if(xlo>xhi||ylo>yhi||idx==s.length())return 0;
    if(xlo==xhi&&ylo==yhi){ans+= s[M*xlo+ylo]; return ans.back();}

    ans+='D';
    int xm = (xlo+xhi)>>1, ym = (ylo+yhi)>>1, cnt=2;

    char tl = BtoD(xlo,xm,ylo,ym);
    bool eq= tl!='D';

    char tr = BtoD(xlo,xm,ym+1,yhi);
    if(tr!=0)eq &= tr==tl, cnt++;

    char bl = BtoD(xm+1,xhi,ylo,ym);
    if(bl!=0)eq &= bl==tl, cnt++;

    char br = BtoD(xm+1,xhi,ym+1,yhi);
    if(br!=0)eq &= br==tl, cnt++;

    if(eq){for(int i=0;i<cnt;i++)ans.pop_back(); ans+=tl; return tl;}

    return 'D';
}

int main(){
    char t,nt;
    scanf("%c",&t);
    while(scanf("%d %d", &N,&M)==2){
        s.clear();
        ans.clear();
        idx=0;
        while(true){
            scanf("%s",l);
            if(strlen(l)==1 && (l[0]=='B'||l[0]=='D'||l[0]=='#')){
                nt=l[0];
                break;
            }
            else s+=l;
        }
        if(t=='D'){
            ans.resize(N*M);
            DtoB(0,N-1,0,M-1);
        }
        else {
            BtoD(0,N-1,0,M-1);
        }
        printf("%c%4d%4d\n",t=='B'?'D':'B', N,M);
        for(int i=0;i<ans.size(); i+=50)
            printf("%s\n", ans.substr(i,50).c_str());
        t=nt;
    }

}