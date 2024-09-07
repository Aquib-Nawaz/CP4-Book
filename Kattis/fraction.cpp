#include <iostream>
using namespace std;
typedef long long ll;
int pq[10];

void getFraction(int s, ll &num, ll &den){

    num = 1, den=pq[s-1];
    for(int i=s-2;i>=0;i--){
        int t = den;
        den = pq[i]*den+num;
        num = t;
    }
    swap(num,den);
}

ll gcd(ll a, ll b){
    return b?gcd(b,a%b):a;
}

int getContinuedFraction(ll num, ll den) {
    ll g = gcd(num, den);
    num /= g, den /= g;
    int s=0;
    while(den){
        ll rem = (num%den + den)%den;
        pq[s++] = (num-rem)/den;
        num = den,den=rem;
    }
    return s;
}

void print(int s){
    for(int i=0;i<s-1;i++)printf("%d ", pq[i]);
    printf("%d\n", pq[s-1]);
}

int main(){
    int n,m;
    ll num1,den1,num2,den2, num3, den3, g;
    scanf("%d%d", &n,&m);
    for(int i=0;i<n;i++)scanf("%d", &pq[i]);
    getFraction(n,num1,den1);
    for(int i=0;i<m;i++)scanf("%d", pq+i);
    getFraction(m,num2,den2);
    num3 = num1*den2 + num2*den1;
    den3 = den1*den2;
    print(getContinuedFraction(num3,den3));
    num3 = num1*den2 - num2*den1;
    print(getContinuedFraction(num3,den3));
    num3 = num1*num2;
    print(getContinuedFraction(num3,den3));
    num3 = num1*den2, den3 = den1*num2;
    print(getContinuedFraction(num3,den3));
}