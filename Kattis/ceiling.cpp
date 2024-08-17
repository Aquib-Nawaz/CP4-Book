#include <iostream>
using namespace std;

struct Node{
    Node* l,*r;
    int v;
    Node(int _v){
        l=r=NULL;
        v=_v;
    }
};

Node* arr[20];

bool compare(Node* l, Node * r){
    if(l== nullptr)return r== nullptr;
    if(r== nullptr)return false;
    return compare(l->l,r->l) && compare(l->r,r->r);
}

Node* insert(Node* root, int v){
    if(root== nullptr)return new Node(v);

    if(v<root->v){
        root->l=insert(root->l,v);
    }else{
        root->r=insert(root->r,v);
    }
    return root;
}

int main(){
    int N,M,sz=0,d;
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        Node * cur= nullptr;
        for(int j=0;j<M;j++){
            scanf("%d",&d);
            cur = insert(cur,d);
        }
        int j;
        for(j=0;j<sz;j++)if(compare(cur,arr[j]))break;
        if(j==sz)arr[sz++]=cur;
    }
    printf("%d",sz);
}