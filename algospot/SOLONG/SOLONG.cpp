#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int ALPHABETS = 26;

int toNumber(char ch) {return ch - 'A';}

struct TrieNode {
    TrieNode* children[ALPHABETS];
    int terminal;
    int first;
    
    TrieNode() : terminal(-1), first(-1) {
        memset(children, 0, sizeof(children));
    }
    
    ~TrieNode() {
        for (int i = 0; i < ALPHABETS; i++) {
            if (children[i]) delete children[i];
        }
    }
    
    void insert(const char* key, int id) {
        if (first == -1) first = id;
        if (*key == 0) terminal = id;
        else {
            int next = toNumber(*key);
            if (children[next] == nullptr) children[next] = new TrieNode();
            children[next]->insert(key+1, id);
        }
    }
    
    int type(const char* key, int id) {
        if (*key == 0) return 0;
        if (first == id) return 1;
        int next = toNumber(*key);
        return 1 + children[next]->type(key+1, id);
    }
    
    TrieNode* find(const char* key) {
        if (*key == 0) return this;
        int next = toNumber(*key);
        if (children[next] == nullptr) return nullptr;
        return children[next]->find(key+1);
    }
};

int countKeys(TrieNode* trie, const char* word) {
    TrieNode* node = trie->find(word);
    if (node == nullptr || node->terminal == -1) return strlen(word);
    return trie->type(word, node->terminal);
}


int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    int tc;
    cin >> tc;

    while(tc--) {
        auto* trie = new TrieNode();
        int N, M;
        cin >> N >> M;
        string s;
        int cnt;
        vector<pair<int, string>> input;
        for (int i = 0; i < N; i++) {
            cin >> s >> cnt;
            input.push_back({-cnt, s});
        }
        
        sort(input.begin(), input.end());
        for (int i = 0; i < N; i++) {
            trie->insert(input[i].second.c_str(), i);
        }
        trie->first = -1;
        
        int ret = 0;
        for (int i = 0; i < M; i++) {
            cin >> s;
            ret = ret + countKeys(trie, s.c_str());
        }
        cout << ret + M - 1 << endl;
    }
}