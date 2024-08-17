#include <iostream>

int main(){
    int N;
    bool fi=false;
    while (scanf("%d", &N) == 1 && N) {
        if(fi)
            printf("\n");
        fi= true;
        bool f=0;
        for (int fghij = 1234; fghij <= 98765/N; ++fghij) {
            int abcde = fghij*N;                           // as discussed above
            int tmp, used = (fghij < 10000);               // flag if f = 0
            tmp = abcde; while (tmp) { used |= 1<<(tmp%10); tmp /= 10; }
            tmp = fghij; while (tmp) { used |= 1<<(tmp%10); tmp /= 10; }
            if (used == (1<<10)-1)                         // all 10 digits are used
                f=1,printf("%05d / %05d = %d\n", abcde, fghij, N);
        }
        if(!f)
            printf("There are no solutions for %d.\n", N);
    }
}