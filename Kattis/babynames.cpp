#include <bits/stdc++.h>
using namespace std;
#include <bits/extc++.h>                         // pbds
using namespace __gnu_pbds;
typedef tree<string, null_type, less<string>, rb_tree_tag,
tree_order_statistics_node_update> ost;
char word[32], rword[32];
int main() {
    int d,a;
    ost names[2];
    bool f=1;
    while(scanf("%d", &d),d!=0){
        if(d==1){
            scanf("%s %d", word, &a);
            names[a-1].insert(word);
        }
        else if(d==2){
            scanf("%s", word);
            auto it = names[0].find(word);
            if(it!=names[0].end())names[0].erase(it);
            it = names[1].find(word);
            if(it!=names[1].end())names[1].erase(it);

        }
        else {
            scanf("%s %s %d", word, rword, &a);
            int ans=0;
            if(a==0||a==1){
                ans += names[0].order_of_key(rword)-names[0].order_of_key(word);
            }
            if(a==0||a==2){
                ans += names[1].order_of_key(rword)-names[1].order_of_key(word);
            }
            if(!f)printf("\n");
            f=0;
            printf("%d", ans);
        }
    }
// as in Chapter 2
// O(n log n)
// 1-smallest = 2
// 9-smallest/largest = 71
// 5-smallest = 15
// index 0 (rank 1)
// index 8 (rank 9)
// index 4 (rank 5)
//   tree.insert(A[i]);
// O(log n) select
// cout << *tree.find_by_order(0) << "\n";
// cout << *tree.find_by_order(n-1) << "\n";
// cout << *tree.find_by_order(4) << "\n";
// O(log n) rank
// cout << tree.order_of_key(2) << "\n";
// cout << tree.order_of_key(71) << "\n";
// cout << tree.order_of_key(15) << "\n";
    return 0;
}