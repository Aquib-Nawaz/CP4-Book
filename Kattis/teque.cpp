#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
char cmd[15];
int main() {
    int n,d;
    scanf("%d", &n);
    bool f=true;
    deque<int> dq1,dq2;
    while (n--) {
        scanf("%s %d", cmd, &d);
        if (strcmp(cmd, "push_front")==0) {

            dq1.push_front(d);
            if(dq1.size()-dq2.size()>1){dq2.push_front(dq1.back()); dq1.pop_back();}
        } else if (strcmp(cmd, "push_back")==0) {

            dq2.push_back(d);
            if(dq2.size()>dq1.size()){dq1.push_back(dq2.front()); dq2.pop_front();}
        }
        else if (strcmp(cmd, "push_middle")==0) {
            if(dq1.size()==dq2.size())
                dq1.push_back(d);
            else dq2.push_front(d);
        }
        else{
            if(!f)
                printf("\n");
            if(d<dq1.size()) printf("%d", dq1[d]);
            else printf("%d", dq2[d-dq1.size()]);
            f= false;
        }
    }
}