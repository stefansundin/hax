// g++ -std=c++11 -g 4.6.cpp && ./a.out
#include <iostream>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

using namespace std;

class Node {
public:
  int value;
  Node *left;
  Node *right;
  Node *parent;

  Node(int v) {
    value = v;
    left = NULL;
    right = NULL;
    parent = NULL;
  }
  Node(int v, Node *l, Node *r) {
    value = v;
    left = l;
    right = r;
    if (left != NULL) {
      left->parent = this;
    }
    if (right != NULL) {
      right->parent = this;
    }
  }

  Node* next() {
    // in-order successor
    if (right != NULL) {
      Node *leftmost = right;
      while (leftmost->left != NULL) {
        leftmost = leftmost->left;
      }
      return leftmost;
    }
    else {
      Node *n = this;
      while (n->parent != NULL && n->parent->right == n) {
        n = n->parent;
      }
      return n->parent;
    }
  }
};

void printTree(Node *n) {
  if (n == NULL) {
    cout << "NULL";
    return;
  }
  cout << n->value;
  if (n->left != NULL || n->right != NULL) {
    cout << " [";
    printTree(n->left);
    cout << ", ";
    printTree(n->right);
    cout << "]";
  }
}

void printNext(Node *n) {
  cout << "the node after " << n->value << " is ";
  Node *next = n->next();
  if (next == NULL) {
    cout << "null";
  }
  else {
    cout << next->value;
  }
  cout << endl;
}

int main() {
  {
    Node *root = new Node(567, new Node(6, new Node(4, new Node(1), NULL), new Node(77)), new Node(1666, new Node(1561), new Node(3572)));
    printTree(root);
    cout << endl;
    Node *n = root->left->left->left;
    while (n != NULL) {
      printNext(n);
      n = n->next();
    }
  }
}
