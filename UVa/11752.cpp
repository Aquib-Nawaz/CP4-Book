#include <iostream>
#include <set>
using namespace std;

bool isPrime[64];
int composites[50],cnt;
typedef __uint128_t ull;
set<unsigned long long >st;
ull max_val;
bool willMultiplyOverflow(ull a, ull b) {
    return a*b > max_val;
}

void solve(){
    st.insert(1);
    for(int i=2;i<1<<16;i++){
        ull pow=1;
        int exp = 0;
        for(int j=0;j<cnt;j++){
            bool b=false;
            while(exp<composites[j] && !b)b = willMultiplyOverflow(pow,i),exp++, pow=pow*i;
            if(b)break;
            st.insert(pow);
        }
    }
}

int main(){
    for(int i=0;i<64;i++)isPrime[i]= true;
    cnt=0;
    for(int i=2;i<64;i++){
        if(isPrime[i]){
            for(int j=i+i;j<64;j+=i){
                isPrime[j]=false;
            }
        }
    }
    for(int i=4;i<64;i++)if(!isPrime[i])composites[cnt++]=i;
    max_val=1;
    max_val<<=64;
    max_val--;
    solve();
    for(auto t:st)printf("%llu\n",t);
}