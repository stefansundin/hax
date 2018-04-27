// g++ -std=c++11 -g 4.9.cpp && ./a.out
#include <iostream>
#include <vector>

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

void print_paths(vector<Node*> &path, Node *root) {
  if (root == NULL) {
    return;
  }
  if (root->left == NULL && root->right == NULL) {
    cout << "{";
    for (int i=0; i < path.size(); i++) {
      cout << path.at(i)->value;
      cout << ", ";
      // if (i+1 != path->size()) {
      //   cout << ", ";
      // }
    }
    cout << root->value;
    cout << "}" << endl;
    // path->erase(path->end());
  }
  else {
    path.push_back(root);
    if (root->left != NULL) {
      print_paths(path, root->left);
    }
    if (root->right != NULL) {
      print_paths(path, root->right);
    }
    // cout << ((*path->end())->value) << endl;
    // cout << path->at(path->size()-1)->value << endl;
    path.erase(path.end() - 1);
  }
}

int main() {
  {
    int arr[] = {1, 4, 6, 77, 567, 1666, 3572};
    Node *root = createBST(arr, 0, ARRAY_SIZE(arr)-1);
    printTree(root);
    cout << endl;
    vector<Node*> path;
    print_paths(path, root);
  }
  cout << endl;
  {
    int arr[] = {26, 47, 57, 71, 85, 174, 179, 260, 291, 298, 342, 344, 382};
    Node *root = createBST(arr, 0, ARRAY_SIZE(arr)-1);
    printTree(root);
    cout << endl;
    vector<Node*> path;
    print_paths(path, root);
  }
}

// Use javascript to generate a random array:
// var arr = [];
// for (var i=0; i < Math.floor(10+Math.random()*100); i++) { arr.push(Math.floor(Math.random()*400)) }
// `int arr[] = {${arr.filter((el,i,a) => i == a.indexOf(el)).join(", ")}};`
