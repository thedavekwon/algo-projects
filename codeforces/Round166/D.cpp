#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int ALPHABETS = 26;

int cnt = 0;

int toNumber(char ch) { return ch - 'a';}

struct TrieNode {
    TrieNode* children[ALPHABETS];
    int k;
    
    TrieNode() : k(0) {
        memset(children, 0, sizeof(children));
    }
    
    ~TrieNode() {
        for (int i = 0; i < ALPHABETS; i++) {
            if (children[i]) delete children[i];
        }
    }
    
    void insert(const char* key, const string &available, int K) {
        if (*key == 0) return;
        else {
            int next = toNumber(*key);
            // if never visited we need to calculate the new k
            if (children[next] == nullptr) {
                // if the next input is part of not available mark k+1
                int newK = k + (available[*key-'a'] == '0' ? 1 : 0);
                // maximumu difference can not exceed K
                if (newK <= K) {
                    children[next] = new TrieNode();
                    children[next]->k = newK;
                    children[next]->insert(key+1, available, K);
                    cnt++;
                }
            } else {
                if (children[next]->k <= K) {
                    children[next]->insert(key+1, available, K);
                }
            }
        }
    }
    
    TrieNode* find(const char* key) {
        if (*key == 0) return this;
        int next = toNumber(*key);
        if (children[next] == nullptr) return nullptr;
        return children[next]->find(key+1);
    }
};

int main() {
    ifstream in("./D.input");
    cin.rdbuf(in.rdbuf());
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    string s;
    string available;
    int K;
    cin >> s >> available >> K;
    
    auto trie = new TrieNode();
    
    for (int i = 0; i < s.length(); i++) {
        trie->insert(s.substr(i, s.length()-i).c_str(), available, K);
    }
    
    cout << cnt << endl;
    
    return 0;
    
}