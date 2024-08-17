#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i=sqrt(n)+1e-10;i>=1;i--){
        if(n%i==0&&(n/i-i)%2==0){
            assert(abs(pow((n/i+i)/2,2)-pow((n/i-i)/2,2)-n)<1e-10);
            printf("%d %d",(n/i-i)/2,(n/i+i)/2);
            return 0;
        }
    }
    printf("impossible");
}