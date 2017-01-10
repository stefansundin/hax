// g++ -std=c++11 -g 4.8.cpp && ./a.out
#include <iostream>
#include <vector>
#include <algorithm>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

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
  cout << n->value;
  if (n->left != NULL || n->right != NULL) {
    cout << " [";
    printTree(n->left);
    cout << ", ";
    printTree(n->right);
    cout << "]";
  }
}

Node* createBST(int *arr, int start, int end) {
  if (end < start) return NULL;
  int mid = (start + end)/2;
  Node *left = createBST(arr, start, mid-1);
  Node *right = createBST(arr, mid+1, end);
  Node *root = new Node(arr[mid], left, right);
  return root;
}

Node* find(Node *root, int v) {
  if (root == NULL) {
    return NULL;
  }
  if (root->value == v) {
    return root;
  }
  Node *n;
  n = find(root->left, v);
  if (n != NULL) {
    return n;
  }
  n = find(root->right, v);
  if (n != NULL) {
    return n;
  }
  return NULL;
}

Node* find_path(vector<Node*> *path, Node *root, Node *node) {
  if (root == NULL) {
    return NULL;
  }
  if (root == node) {
    path->insert(path->begin(), root);
    return root;
  }
  Node *n;
  if ((n=find_path(path,root->left,node)) != NULL
   || (n=find_path(path,root->right,node)) != NULL) {
    path->insert(path->begin(), root);
    return n;
  }
  return NULL;
}

void print_path(vector<Node*> *path) {
  for (int i=0; i < path->size(); i++) {
    cout << path->at(i)->value;
    if (i+1 != path->size()) {
      cout << " -> ";
    }
  }
  cout << endl;
}

int main() {
  int arr[] = {324, 286, 97, 167, 181, 300, 355, 279, 154, 67, 183, 48, 380, 302, 164, 292, 277, 339, 81, 60, 4, 22, 186, 138, 46, 232, 253, 119, 359, 248, 118, 301, 72, 78, 89, 143, 56, 146, 121, 136, 122, 261, 240, 245, 347, 191, 49, 104, 130, 235, 171, 288, 40, 132, 364, 370, 285, 192, 335, 188, 257, 6, 92, 197, 86, 216, 287, 343};
  Node *root = createBST(arr, 0, ARRAY_SIZE(arr)-1);
  printTree(root);
  cout << endl;

  Node *a = find(root, 89);
  Node *b = find(root, 347);

  vector<Node*> path_a, path_b;
  find_path(&path_a, root, a);
  find_path(&path_b, root, b);
  print_path(&path_a);
  print_path(&path_b);

  int length = min(path_a.size(), path_b.size());
  Node *common = NULL;
  for (int i=0; i < length; i++) {
    if (path_a[i] != path_b[i]) {
      common = path_a[i-1];
      break;
    }
  }
  if (common != NULL) {
    cout << "First common ancestor: " << common->value << endl;
  }
  else {
    cout << "Error: no common ancestor." << endl;
  }
}

// Use javascript to generate a random array:
// var arr = [];
// for (var i=0; i < Math.floor(10+Math.random()*100); i++) { arr.push(Math.floor(Math.random()*400)) }
// `int arr[] = {${arr.filter((el,i,a) => i == a.indexOf(el)).join(", ")}};`
