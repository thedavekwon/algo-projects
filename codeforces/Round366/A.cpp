// central has all the notifications
// apps has notifcation for each apps
// when 1 happens add to apps and central with the index, insert central idx for the apps queue, insert central idx and app number for central
// when 2 happens remove all the apps in apps and central
// when 3 happens remove all the first in central and apps
// set used because it is implemented with the ordered binary search tree

#include <iostream>
#include <fstream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

int main() {
    ifstream in("./A.input");
    cin.rdbuf(in.rdbuf());
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    int idx = 0;

    set<pii> central;
    vector<set<int>> apps(n+1, set<int>());
    
    for (int i = 0; i < q; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        if (t1 == 1) {
            apps[t2].insert(idx);
            central.insert({idx++, t2});
        }
        if (t1 == 2) {
            for (auto &i : apps[t2]) {
                central.erase({i, t2});
            }
            apps[t2].clear();
        }
        if (t1 == 3) {
            while (!central.empty() && central.begin()->first < t2) {
                auto p = *central.begin();
                central.erase(p);
                apps[p.second].erase(p.first);
            }
        }
        cout << central.size() << endl;
    }
}