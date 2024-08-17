#include <iostream>
#include <stack>

using namespace std;
 int main(){
     int n, ret=2;
     char c=0;
     while(ret!=-1){
         stack<int>st,stsum;
         bool adj=true,err=false;
         while(true) {
             while((ret=scanf("%c", &c))!=-1 && c==' ');
             if(ret==-1||c=='\n')break;
             ungetc(c,stdin);
             scanf("%d", &n);
             if(err){}
             else if(n>0){
                 if(!st.empty()&&st.top()==n){
                     if(!adj && (stsum.empty() || stsum.top()>=n))err=true;
                     if(!err&&!adj)stsum.pop();
                     st.pop();
                 }
                 else err= true;
                 adj=false;
             }
             else if(adj){
                 st.push(-n),stsum.push(-n);
             }
             else {
                adj= true;
                st.push(-n);
                stsum.top()+=-n;
             }
         }
         if(c=='\n'&&ret==-1)break;
         if(err||!st.empty())printf(":-( Try again.\n");
         else printf(":-) Matrioshka!\n");
     }
 }