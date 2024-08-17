#include <iostream>
#include <set>
using namespace std;

int main(){
    long long N;
    scanf("%lld" ,&N);
    set<long long>st;
    for(long long i=1; i*i<=N; i++){
        if(N%i==0){
            st.insert(i);
            st.insert(N/i);
        }
    }

    for(auto i:st)printf("%lld " ,i-1);
}