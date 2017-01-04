// g++ -std=c++11 -g 4.2.cpp && ./a.out
#include <iostream>
#include <cmath>

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

// trickier:
// Node *createBST(int *arr, int size) {
//   // cout << "createBST(" << *arr << ", " << size << ")" << endl;
//   if (size == 0) return NULL;
//   // cout << arr[size/2] << endl;
//   if (size == 1) return new Node(arr[0]);
//   int mid = arr[size/2];
//   Node *left = createBST(arr, size/2);
//   Node *right = createBST(arr+size/2+1, ceil(size/2.0)-1);
//   Node *root = new Node(mid, left, right);
//   return root;
// }

// easier:
Node *createBST(int *arr, int start, int end) {
  // cout << "createBST(" << start << ", " << end << ")" << endl;
  if (end < start) return NULL;
  // cout << arr[size/2] << endl;
  int mid = (start + end)/2;
  Node *left = createBST(arr, start, mid-1);
  Node *right = createBST(arr, mid+1, end);
  Node *root = new Node(arr[mid], left, right);
  return root;
}

int main() {
  {
    int arr[] = {1, 4, 6, 77, 567, 1561, 1666, 3572};
    // Node *root = createBST(arr, ARRAY_SIZE(arr));
    Node *root = createBST(arr, 0, ARRAY_SIZE(arr)-1);
    printTree(root);
    cout << endl;
  }
  {
    int arr[] = {1, 4, 6, 77, 567, 1666, 3572};
    // Node *root = createBST(arr, ARRAY_SIZE(arr));
    Node *root = createBST(arr, 0, ARRAY_SIZE(arr)-1);
    printTree(root);
    cout << endl;
  }
  {
    int arr[] = {26, 47, 57, 71, 85, 174, 179, 260, 291, 298, 342, 344, 382};
    // Node *root = createBST(arr, ARRAY_SIZE(arr));
    Node *root = createBST(arr, 0, ARRAY_SIZE(arr)-1);
    printTree(root);
    cout << endl;
  }
}

// Use javascript to generate a random array:
// var arr = [];
// for (var i=0; i < Math.floor(10+Math.random()*14); i++) { arr.push(Math.floor(Math.random()*400)) }
// arr.sort((a,b) => a-b).filter((el,i,a) => i == a.indexOf(el));
