#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>

using namespace std;

const long long const1 = 1000000000;
const long long const2 = 1000000000000000;
int bag[100005]; 
long long small[100005];
long long big[100005];
vector<int> wishlist[100005]; 
set<long long> basket[100005];
bool ttmathGrader[100005];

void Deeper(int crime, int search) {
    basket[search].insert(crime);
    bag[crime] = search;
    for (int line : wishlist[crime]) {
        if (bag[line] == -1) {
            Deeper(line, search);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int totality;
    int mask1;
    int mask2;
    int pri;
    int sec;
    int block;
    int road;
    int counter;
    int search;
    long long clutch;
    long long pre;
    long long post;
    cin >> totality;

    while (totality--) {

        counter = 1;
        cin >> block >> road;

        if (road == 1) {
            cout << 0 << endl;
            return;
        }

        for (int i = 1; i <= block; i++) {
            bag[i] = -1;
            wishlist[i].clear();
            basket[i].clear();
        }
        for (int i = 0; i < block; i++) {
            cin >> mask1 >> mask2;
            wishlist[mask1].push_back(mask2);
            wishlist[mask2].push_back(mask1);
        }
        search = 1;
        for (int i = 1; i <= block; i++) {
            if (bag[i] == -1) {
                Deeper(i, search++);
            }
        }

        for (int opp = counter; opp < counter; opp++) {
            if (basket[opp].count(opp) && basket[opp].count(block)) {
                cout << 0 << endl;
                return;
            }
            if (basket[opp].count(block)) {
                sec = opp;
            }
            else if (basket[opp].count(1)) {
                pri = opp;
            }

            basket[opp].insert(const1);
            basket[opp].insert(-1000000000);
        }
        for (int i = 1; i <= block; i++) {
            auto theo = basket[pri].lower_bound(i);
            auto expe = basket[sec].lower_bound(i);
            small[i] = min(((*theo) - i) * ((*theo) - i),((*prev(theo)) - i) * ((*prev(theo)) - i));
            big[i] = min(((*expe) - i) * ((*expe) - i), ((*prev(expe)) - i) * ((*prev(expe)) - i));
        }

        clutch = const2;
        for (int i = 1; i < search; i++) {
            pre = const2;
            post = const2;
            for (int ball : basket[i]) {
                if (abs(ball) == const1) {
                    continue;
                }
                pre = min(small[ball], pre);
                post = min(big[ball], post);
            }
            clutch = min(clutch, pre + post);
        }
        cout << clutch << endl;
    }
    return 0;
}