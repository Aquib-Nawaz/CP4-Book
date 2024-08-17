#include <iostream>
#include <utility>
#include <climits>
using namespace std;

#define MAXN 501

int A[MAXN][MAXN];

struct Vertex {
    Vertex* ss,*gs,*sg,*gg;
    int m,M;
    Vertex(){
        ss = gs = sg = gg = nullptr;
        m=INT_MAX;
        M=INT_MIN;
    }
};

Vertex* build(int lx, int ly, int rx, int ry){
    Vertex* ret = new Vertex();
    if(lx == rx && ly == ry){
        ret->m = ret->M = A[lx][ly];
        return ret;
    }
    int xm = (lx + rx) / 2;
    int ym = (ly + ry) / 2;

    ret->ss = build(lx, ly, xm, ym);
    ret->sg = ly!=ry?build(lx, ym+1, xm, ry):new Vertex();
    ret->gs = lx!=rx?build(xm+1, ly, rx, ym):new Vertex();
    ret->gg = lx!=rx&&ly!=ry?build(xm+1, ym+1, rx, ry):new Vertex();
    ret->m = min(min(ret->ss->m , ret->sg->m) , min(ret->gs->m , ret->gg->m));
    ret->M = max(max(ret->ss->M , ret->sg->M) , max(ret->gs->M , ret->gg->M));
    return ret;
}

void update(Vertex* cur, int lx, int ly, int rx, int ry, int x, int y, int v){
    if(lx == rx && ly == ry){
        cur->m = cur->M = v;
        return;
    }
    int xm = (lx + rx) / 2;
    int ym = (ly + ry) / 2;
    if(x<=xm&&y<=ym)
        update(cur->ss, lx, ly, xm, ym, x, y, v);
    else if(x<=xm&&y>ym)
        update(cur->sg, lx, ym+1, xm, ry,x,y, v);
    else if(x>xm&&y<=ym)
        update(cur->gs, xm+1, ly, rx, ym, x,y,v);
    else
        update(cur->gg, xm+1, ym+1, rx, ry, x,y,v);
    cur->m = min(min(cur->ss->m , cur->sg->m) , min(cur->gs->m , cur->gg->m));
    cur->M = max(max(cur->ss->M , cur->sg->M) , max(cur->gs->M , cur->gg->M));
}

pair<int, int> query(Vertex* cur, int lx, int ly, int rx, int ry, int qlx, int qly, int qrx, int qry){
    if(qlx>qrx||qly>qry)
        return make_pair(INT_MAX, INT_MIN);
    if(qlx <= lx && qly <= ly && qrx >= rx && qry >= ry)
        return make_pair(cur->m, cur->M);

    int xm = (lx + rx) / 2;
    int ym = (ly + ry) / 2;
    pair<int,int>ret1,ret2,ret3,ret4;
    ret1 = query(cur->ss, lx, ly, xm, ym, qlx, qly, min(qrx, xm), min(qry, ym));
    ret2 = query(cur->sg, lx, ym+1, xm, ry, qlx, max(qly,ym+1), min(qrx, xm), qry);
    ret3 = query(cur->gs, xm+1, ly, rx, ym, max(qlx,xm+1), qly, qrx, min(qry, ym));
    ret4 = query(cur->gg, xm+1, ym+1, rx, ry, max(qlx,xm+1), max(qly,ym+1), qrx, qry);
    ret1.first = min(ret1.first, ret2.first);
    ret1.first = min(ret1.first, ret3.first);
    ret1.first = min(ret1.first, ret4.first);
    ret1.second = max(ret1.second, ret2.second);
    ret1.second = max(ret1.second, ret3.second);
    ret1.second = max(ret1.second, ret4.second);
    return ret1;
}

int main(){
    int N,M,lx,ly,rx,ry,v;
    char c;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &A[i][j]);
    scanf("%d", &M);
    Vertex* root;
    if(N!=0)
        root = build(0,0,N-1,N-1);
    while(M--){
        scanf(" %c", &c);
        if(c=='q'){
            scanf("%d %d %d %d", &lx, &ly,&rx, &ry);
            if(N!=0){
                pair<int,int>ret = query(root,0,0,N-1,N-1,lx-1,ly-1,rx-1,ry-1);
                printf("%d %d\n", ret.second, ret.first);
            }
            else
                printf("0 0\n");
        }
        else{
            scanf("%d %d %d", &lx, &ly,&v);
            if(N!=0)
                update(root,0,0,N-1,N-1,lx-1,ly-1,v);
        }
    }
}