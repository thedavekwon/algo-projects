#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

Node* newNode(int item) {
    auto *tmp = new Node();
    tmp->key = item;
    tmp->left = tmp->right = nullptr;
    return tmp;
}

void inOrder(Node *root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

void preOrder(Node *root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}

Node* insert(Node* node, int key) {
    if (node == nullptr) return newNode(key);
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    return node;
}

int maxHeight(Node *root) {
    if (root == nullptr) return 0;
    int h = 0;
    h = max(1+maxHeight(root->left), 1+maxHeight(root->right));
    return h;
}

int minHeight(Node *root) {
    if (root == nullptr) return 0;
    int h = 0;
    h = min(1+minHeight(root->left), 1+minHeight(root->right));
    return h;
}

int main() {
    Node *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 90);
    insert(root, 100);

    cout << "Inorder traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preOrder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postOrder(root);
    cout << endl;

    cout << minHeight(root) << " " << maxHeight(root) << endl;
    return 0;
}