// g++ -std=c++11 -g 4.5.cpp && ./a.out
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Node {
public:
  int value;
  Node *left;
  Node *right;

  Node(int v) {
    value = v;
    left = NULL;
    right = NULL;
  }
  Node(int v, Node *l) {
    value = v;
    left = l;
    right = NULL;
  }
  Node(int v, Node *l, Node *r) {
    value = v;
    left = l;
    right = r;
  }
};

void printTree(Node *n) {
  if (n == NULL) {
    cout << "NULL";
    return;
  }
  cout << n->value << " [";
  printTree(n->left);
  cout << ",";
  printTree(n->right);
  cout << "]";
}

int treeMin(Node *n) {
  if (n == NULL) return INT_MAX;
  return min(n->value, min(treeMin(n->left), treeMin(n->right)));
}

int treeMax(Node *n) {
  if (n == NULL) return INT_MIN;
  return max(n->value, max(treeMax(n->left), treeMax(n->right)));
}

bool checkBST1(Node *n) {
  if (n == NULL) return true;
  int leftMax = treeMax(n->left);
  int rightMin = treeMin(n->right);
  // cout << "checkBST1(" << n->value << "). leftMax: " << leftMax << ", rightMin: " << rightMin << endl;
  return (leftMax <= n->value && n->value < rightMin);
}

bool checkBST2(Node *n, int min, int max) {
  if (n == NULL) return true;
  // cout << "checkBST2(" << n->value << "," << min << "," << max << ")" << ". Allowable range: (" << min << "," << max << ")" << endl;
  if (!(min <= n->value && n->value <= max)) {
    // cout << "failed 1 (" << n->value << ")" << endl;
    return false;
  }
  if (!checkBST2(n->left,min,n->value)) {
    // cout << "failed 2 (" << n->value << ")" << endl;
    return false;
  }
  if (!checkBST2(n->right,n->value,max)) {
    // cout << "failed 3 (" << n->value << ")" << endl;
    return false;
  }
  return true;
}

int main() {
  // std::cout << std::fixed;
  Node root(5, new Node(4, new Node(4)), new Node(6));
  printTree(&root);
  cout << endl;
  // cout << "min: " << treeMin(&root) << endl;
  // cout << "max: " << treeMax(&root) << endl;
  cout << "checkBST1: ";
  if (checkBST1(&root)) {
    std::cout << "Tree is a binary search tree." << std::endl;
  } else {
    std::cout << "Tree is NOT a binary search tree!" << std::endl;
  }
  cout << "checkBST2: ";
  if (checkBST2(&root, INT_MIN, INT_MAX)) {
    std::cout << "Tree is a binary search tree." << std::endl;
  } else {
    std::cout << "Tree is NOT a binary search tree!" << std::endl;
  }
}
