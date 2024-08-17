#include <iostream>
#include <cstring>
#include <map>
#include <cmath>
#include <cstdlib>
using namespace std;
map<char, int>m= { {'+',0}, {'-',1}, {'*',2}, {'/',3}};
void solve(char s[]) {
    char *end;
    int operands[43];
    int i=0;
    operands[i++] = strtol(s, &end, 10);
    int numop=0;
    while(*end != '\0') {
        while(*end==' ')
            end++;
        if(*end=='=')
            break;
        operands[i++] = m[*end];
        end++;
        operands[i++] = strtol(end, &end, 10);
        numop++;
    }
    end++;
    while(*end==' ')
        end++;
    char* var = end;
    int j;
    for(j=1;j<2*numop;j+=2){
        printf("%d %c ", operands[j-1], operands[j]==0?'+':operands[j]==1?'-':operands[j]==2?'*':'/');
    }
    printf("%d = %s\n", operands[j-1], var);
    for(i=numop;i>0;i--){
        bool f=false;
        for(int j=1;j<=2*i;j+=2){
            if(operands[j]==2){
                operands[j+1]=operands[j-1]*operands[j+1];
                memmove(operands+j-1, operands+j+1, sizeof (int)*(2*i-j+1));
                f=true;
                break;
            }
            else if(operands[j]==3){
                operands[j+1]=operands[j-1]/operands[j+1];
                memmove(operands+j-1, operands+j+1, sizeof (int)*(2*i-j+1));
                f=true;
                break;
            }
        }
        int j=1;
        if(!f){
            if(operands[j]==0){
                operands[j+1]=operands[j-1]+operands[j+1];
                memmove(operands+j-1, operands+j+1, sizeof (int)*(2*i-j+1));
            }
            else if(operands[j]==1){
                operands[j+1]=operands[j-1]-operands[j+1];
                memmove(operands+j-1, operands+j+1, sizeof (int)*(2*i-j+1));
            }
        }
        for(j=1;j<2*(i-1);j+=2){
            printf("%d %c ", operands[j-1], operands[j]==0?'+':operands[j]==1?'-':operands[j]==2?'*':'/');
        }
        printf("%d = %s\n", operands[j-1], var);
    }
    printf("\n");

}
int main() {
    char s[1000];
    while (scanf("%[^\n]", s) != EOF) {
        solve(s);
        int ch;
        while ((ch = fgetc(stdin)) != '\n' && ch != EOF) {
            ;
        }
    }
}