#include <unordered_map>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string line;

int main() {
    int T,n;
    double p;
    char c;
    scanf("%d", &T);
    while (T--) {
        unordered_map<char, double> umap;
        double sum=0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            cin >> c >> p;
            umap[c]=p;
        }
        scanf("%d", &n);
        cin.ignore();
        for(int i=0;i<n;i++){
            line = "";
            getline(cin, line);
            int l = line.size();
            for(int j=0;j<l;j++){
                auto it = umap.find(line[j]);
                if(it!=umap.end())
                    sum+=it->second;
            }
        }
        printf("%.02lf$\n", sum/100);
    }
}