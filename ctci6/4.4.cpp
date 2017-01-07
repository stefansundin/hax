// g++ -std=c++11 -g 4.4.cpp && ./a.out
#include <iostream>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

using namespace std;

class Node {
public:
  int value;
  Node *left;
  Node *right;

  int height;
  bool balanced;

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

Node *createBST(int *arr, int start, int end) {
  if (end < start) return NULL;
  int mid = (start + end)/2;
  Node *left = createBST(arr, start, mid-1);
  Node *right = createBST(arr, mid+1, end);
  Node *root = new Node(arr[mid], left, right);
  return root;
}

int depth(Node *root) {
  if (root == NULL) return 0;
  int left_depth = depth(root->left);
  int right_depth = depth(root->right);
  if (left_depth == -1
   || right_depth == -1
   || abs(left_depth-right_depth) > 1 // subtree height differ at most by one.
  //  || left_depth != right_depth // perfect balanced tree
  ) {
    return -1;
  }
  // uncomment the below if you want to check if the tree is a BST and not just a binary tree
  // else if (
  //     (root->left != NULL && root->left->value > root->value)
  //  || (root->right != NULL && root->right->value < root->value)
  // ) {
  //   return -1;
  // }
  else {
    // cout << left_depth << " " << right_depth << " " << max(left_depth, right_depth)+1 << " " << root->value << endl;
    return max(left_depth, right_depth)+1;
  }
}

bool isBalanced(Node *root) {
  return (bool)(depth(root) != -1);
}

int main() {
  cout.setf(ios::boolalpha);
  {
    Node *root = new Node(10, new Node(5), new Node(10, new Node(3, new Node(5, new Node(10, new Node(3), new Node(9)), NULL), NULL), NULL));
    printTree(root);
    cout << endl;
    cout << "balanced: " << isBalanced(root) << endl;
  }
  {
    Node *root = new Node(10, new Node(5, new Node(3), new Node(9)), new Node(15, new Node(13), new Node(12)));
    printTree(root);
    cout << endl;
    cout << "balanced: " << isBalanced(root) << endl;
  }
  {
    Node *root = new Node(10, new Node(5, new Node(3), new Node(9)), new Node(15, new Node(13), new Node(19)));
    printTree(root);
    cout << endl;
    cout << "balanced: " << isBalanced(root) << endl;
  }
  {
    Node *root = new Node(1, new Node(5, new Node(3, new Node(3, new Node(3), new Node(3)), new Node(3)), new Node(9)), new Node(15, new Node(13), new Node(19)));
    printTree(root);
    cout << endl;
    cout << "balanced: " << isBalanced(root) << endl;
  }
  {
    int arr[] = {1, 4, 6, 77, 567, 1666, 3572};
    Node *root = createBST(arr, 0, ARRAY_SIZE(arr)-1);
    printTree(root);
    cout << endl;
    cout << "balanced: " << isBalanced(root) << endl;
  }
  {
    int arr[] = {26, 47, 57, 71, 85, 174, 179, 260, 291, 298, 342, 344, 382};
    Node *root = createBST(arr, 0, ARRAY_SIZE(arr)-1);
    printTree(root);
    cout << endl;
    cout << "balanced: " << isBalanced(root) << endl;
  }
}

// Use javascript to generate a random array:
// var arr = [];
// for (var i=0; i < Math.floor(10+Math.random()*14); i++) { arr.push(Math.floor(Math.random()*400)) }
// arr.sort((a,b) => a-b).filter((el,i,a) => i == a.indexOf(el));
