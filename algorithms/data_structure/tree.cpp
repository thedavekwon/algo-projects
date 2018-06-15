#include <string>
#include <vector>
#include <iostream>

using namespace std;

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

// implementation
bool isChild() {

}

Node* getTree(Node* root, const vector<Node*> &nodes) {
    Node* ret = root;
    for (auto node : nodes) {
        if (isChild(root, node, nodes)) {
            ret->children.push_back(getTree(node, nodes));
        }
    }
    return ret;
}

