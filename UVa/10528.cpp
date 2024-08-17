#include <iostream>
#include <string>
#include <unordered_map>
#include <cstring>
#include <sstream>

using namespace std;
int main(){
    string notes[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    unordered_map<string, int>mp;
    int diff[] = {2,2,1,2,2, 2};
    int family[12],k;
    memset(family, 0, sizeof family);
    for(int i=0;i<sizeof notes/sizeof notes[0];i++){
        mp[notes[i]] = i;
        family[i]|=1<<i;
        k=i;
        for(int j : diff){
            k = (k+j)%12;
            family[i]|=1<<k;
        }
    }

    char in[3],c;
    int inp;
    string line,note;
    while (getline(cin, line), line != "END")
    {
        inp=0;

        stringstream ss(line);
        while (ss >> note)
            inp|=1<<mp[note];

        bool f=0;
        for(int i=0;i<12;i++){
            if((family[i]&inp) == inp){
                if(f)
                    printf(" ");
                f=1;
                printf("%s",notes[i].c_str());
            }
        }
        printf("\n");
    }
}