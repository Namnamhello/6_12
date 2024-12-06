#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    char data;
    TreeNode* leftChild;
    TreeNode* rightChild;
};

TreeNode* createNode(char data) {
    TreeNode* node = new TreeNode;
    node->data = data;
    node->leftChild = node->rightChild = nullptr;
    return node;
}

void preTraversal(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> stk;
    stk.push(root);
    while (!stk.empty()) {
        TreeNode* current = stk.top();
        stk.pop();
        cout << current->data << " ";
        if (current->rightChild) stk.push(current->rightChild);
        if (current->leftChild) stk.push(current->leftChild);
    }
}

void inTraversal(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> stk;
    TreeNode* current = root;
    while (current || !stk.empty()) {
        while (current) {
            stk.push(current);
            current = current->leftChild;
        }
        current = stk.top();
        stk.pop();
        cout << current->data << " ";
        current = current->rightChild;
    }
}

void postTraversal(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> stk1, stk2;
    stk1.push(root);
    while (!stk1.empty()) {
        TreeNode* current = stk1.top();
        stk1.pop();
        stk2.push(current);
        if (current->leftChild) stk1.push(current->leftChild);
        if (current->rightChild) stk1.push(current->rightChild);
    }
    while (!stk2.empty()) {
        cout << stk2.top()->data << " ";
        stk2.pop();
    }
}

int main() {
    TreeNode* root = createNode('+');
    root->leftChild = createNode('-');
    root->leftChild->leftChild = createNode('+');
    root->leftChild->leftChild->leftChild = createNode('a');
    root->leftChild->leftChild->rightChild = createNode('/');
    root->leftChild->leftChild->rightChild->leftChild = createNode('*');
    root->leftChild->leftChild->rightChild->leftChild->leftChild = createNode('5');
    root->leftChild->leftChild->rightChild->leftChild->rightChild = createNode('b');
    root->leftChild->leftChild->rightChild->rightChild = createNode('c');
    root->leftChild->rightChild = createNode('^');
    root->leftChild->rightChild->leftChild = createNode('c');
    root->leftChild->rightChild->rightChild = createNode('8');
    root->rightChild = createNode('+');
    root->rightChild->leftChild = createNode('*');
    root->rightChild->leftChild->leftChild = createNode('d');
    root->rightChild->leftChild->rightChild = createNode('e');
    root->rightChild->rightChild = createNode('0'); // Represent 0.5 as two nodes: '0' and '.'
    root->rightChild->rightChild->rightChild = createNode('.');
    root->rightChild->rightChild->rightChild->rightChild = createNode('5');

    cout << "Pre-order: ";
    preTraversal(root);
    cout << endl;

    cout << "In-order: ";
    inTraversal(root);
    cout << endl;

    cout << "Post-order: ";
    postTraversal(root);
    cout << endl;

    return 0;
}
