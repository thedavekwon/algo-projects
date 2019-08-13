#include <string>

using namespace std;

struct Trie {
    struct Trie *ch[26];
};

struct Trie* get(void) {
    struct Trie *ret = new Trie();
    return ret;
}

void insert(struct Trie *root, string &key) {
    struct Trie *tmp = root;
    for (int i = 0; i < key.length(); i++) {
        
    }
}