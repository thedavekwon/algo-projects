#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N, Q;
int parents[200001];

struct Node {
    string label;
    Node *parent;
    vector<Node*> children;
};

void printLabels(Node* root) {
    cout<<root->label<<endl;
    for (int i=0; i < root->children.size(); i++) {
        printLabels(root->children[i]);
    }
}

int height(Node* root) {
    int h = 0;
    for (int i=0; i < root->children.size(); i++) {
        h = max(h, 1 + height(root->children[i]));
    }
    return h;
}

int main() {
    ios::sync_with_stdio(false);

    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    cin >> N >> Q;
    for (int i = 1; i < N; ++i) {
        cin >> parents[i];
    }
}