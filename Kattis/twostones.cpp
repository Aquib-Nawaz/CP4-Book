#include <iostream>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    printf("%s\n",N&1 ? "Alice" : "Bob");
}